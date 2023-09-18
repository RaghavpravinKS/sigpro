package com.example.reciever;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.widget.Toast;
import android.util.Log;
import java.util.ArrayList;
import android.content.res.Configuration;
import androidx.core.app.ActivityCompat;
import androidx.fragment.app.Fragment;
import androidx.core.content.ContextCompat;
import android.view.LayoutInflater;
import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import com.example.reciever.databinding.ActivityMainBinding;
import com.google.android.material.tabs.TabLayoutMediator;
import androidx.fragment.app.FragmentManager;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import android.view.MenuItem;
import androidx.navigation.fragment.NavHostFragment;
import androidx.navigation.ui.NavigationUI;
import android.widget.LinearLayout;
import com.google.android.material.bottomnavigation.BottomNavigationView;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import android.widget.TextView;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Set;
import java.util.HashMap;

public class reciever extends AppCompatActivity implements OnFragmentInteractionListener  {
    private InfoFragment infoFragment;
    private AppFragment appFragment;
     FragmentManager fm;
     Fragment current;
    private LogFragment logFragment;
     private Hashtable<Integer,TextView> textViews = new Hashtable<Integer,TextView>();
     private Hashtable<Integer, ThingSpeakRead> thingSpeakReadBlocks = new Hashtable<>();

    private boolean checkIfAllPermissionsGranted()
    {
        return true;
    }
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        com.example.reciever.databinding.ActivityMainBinding activityMainBinding = ActivityMainBinding.inflate(LayoutInflater.from(this));
        setContentView(activityMainBinding.getRoot());
        fm = getSupportFragmentManager();
        Fragment navHostFragment = fm.findFragmentById(R.id.nav_host_fragment);
        navHostFragment = navHostFragment.getChildFragmentManager().getFragments().get(0);
        current =  navHostFragment;
        appFragment  = (AppFragment) navHostFragment;
        infoFragment  = new InfoFragment();
        logFragment  = new LogFragment();
        fm.beginTransaction().add(R.id.nav_host_fragment, logFragment, "3").hide(logFragment).commit();
        fm.beginTransaction().add(R.id.nav_host_fragment, infoFragment, "2").hide(infoFragment).commit();
        fm.beginTransaction().add(R.id.nav_host_fragment, appFragment, "1").commit();
        BottomNavigationView navView = findViewById(R.id.nav_view);
        NavController navController = Navigation.findNavController(this, R.id.nav_host_fragment);
        NavigationUI.setupWithNavController(navView, navController);
        navView.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
        @Override
                public boolean onNavigationItemSelected(@NonNull MenuItem menuItem) {
                        switch (menuItem.getItemId()) {                case R.id.navigation_app:
                fm.beginTransaction().hide(current).show(appFragment).commit();
                current = appFragment;
        return true;                case R.id.navigation_info:
                fm.beginTransaction().hide(current).show(infoFragment).commit();
                current = infoFragment;
        return true;                case R.id.navigation_log:
                fm.beginTransaction().hide(current).show(logFragment).commit();
                current = logFragment;
        return true;                }
                return false;
                }
        });
        thisClass = this;
     }

    private reciever thisClass;
    private final Thread BgThread = new Thread() {
    @Override
    public void run() {
            String argv[] = new String[] {"MainActivity","reciever"};
            naMain(argv, thisClass);
        }
    };

    public void flashMessage(final String inMessage) {
        runOnUiThread(new Runnable() {
              public void run() {
                    Toast.makeText(getBaseContext(), inMessage, Toast.LENGTH_SHORT).show();
              }
        });
    }

    public void terminateApp() {
        finish();
    }

    protected void onDestroy() {
         if (BgThread.isAlive())
             naOnAppStateChange(6);
        Iterator it = thingSpeakReadBlocks.entrySet().iterator();
        while (it.hasNext()) {
            HashMap.Entry pair = (HashMap.Entry)it.next();
            ThingSpeakRead tsR  = (ThingSpeakRead) pair.getValue();
            tsR.cancelTimer();
        }
         super.onDestroy();
         System.exit(0); //to kill all our threads.
    }

   //Methods for ThingSpeak Write block
   public void initThingSpeakReadConnection(int channelID, String readAPIKey, int field, double sampleTime) {
       if (!thingSpeakReadBlocks.containsKey(channelID)) {
            ThingSpeakRead thingSpeakWrite = new ThingSpeakRead(channelID,readAPIKey, field, this, sampleTime);
            thingSpeakWrite.setChannelID(channelID);
            thingSpeakWrite.setReadAPIKey(readAPIKey);
            thingSpeakWrite.setLogFragment(logFragment);
            thingSpeakReadBlocks.put(channelID, thingSpeakWrite);
       } else{
             ThingSpeakRead tsR = thingSpeakReadBlocks.get(channelID);
             if (tsR != null) {
                  tsR.addSampleTime(field, sampleTime);
             }
       }
   }
   public float[] readThingSpeakData(int channelid, int field) {
       ThingSpeakRead thingSpeakRead = thingSpeakReadBlocks.get(channelid);
       if( thingSpeakRead != null){
           float[] f =  thingSpeakRead.readData(channelid, field);
           return f;
       }else
           return new float[]{0,0};   }

	@Override
    public void onAttachFragment(Fragment fragment) {
        super.onAttachFragment(fragment);
        if (fragment instanceof InfoFragment) {
            this.infoFragment = (InfoFragment) fragment;
            infoFragment.setFragmentInteractionListener(this);
        }
        if (fragment instanceof AppFragment) {
            ((AppFragment)fragment).setFragmentInteractionListener(this);
        }
        if (fragment instanceof LogFragment) {
            this.logFragment = (LogFragment) fragment;
            Set<Integer> keySet = thingSpeakReadBlocks.keySet();
            Iterator<Integer> itr = keySet.iterator();
            while (itr.hasNext()) {
                Integer v = itr.next();
                thingSpeakReadBlocks.get(v).setLogFragment((LogFragment) fragment);
            }
        }
    }

	@Override
    public void onFragmentCreate(String name) {

    }

    @Override
    public void onFragmentStart(String name) {
        switch (name) {
            case "Info":
               break;
            case "App":
                break;
            default:
                break;
    }
    }

    @Override
    public void onFragmentResume(String name) {
        switch (name) {
            case "App":
                registerDataDisplays();
                if (checkIfAllPermissionsGranted()){
                    if (!BgThread.isAlive()) {
                        BgThread.start();
                    }
                }
                break;
            default:
                break;
        }
    }

    @Override
    public void onFragmentPause(String name) {
    }
    @Override
    protected void onResume() {
         super.onResume();
         if (BgThread.isAlive())
             naOnAppStateChange(3);
    }

    @Override
    protected void onPause() {
        if (BgThread.isAlive())
            naOnAppStateChange(4);
        super.onPause();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    public void registerDataDisplays() {
    // bind text views for data display block;
    for (int i = 1; i <= 2; i++) {
            TextView textView = (TextView) findViewById(
            getResources().getIdentifier("DataDisplay" + i, "id", getPackageName()));
            textViews.put(i, textView);
        }
    }
    public void displayText(int id, byte[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, short[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, int[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, long[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, float[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    public void displayText(int id, double[] data, byte[] format) {
        String formatString = new String(format);
        String toDisplay = String.format(formatString, data[0]);
        if (data.length > 1) {
            for (int i = 1; i < data.length; i++)
                toDisplay += "\n" + String.format(formatString, data[i]);
        }
        updateTextViewById(id, toDisplay);
    }

    private void updateTextViewById(final int id, final String finalStringToDisplay) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                try {
                    TextView tv = textViews.get(id);
                    if(tv != null) {
                        tv.setText(finalStringToDisplay);
                    }
					
                } catch (Exception ex) {
                    Log.e("reciever.updateTextViewById", ex.getLocalizedMessage());
                }
            }
        });
    }
    private native int naMain(String[] argv, reciever pThis);
    private native void naOnAppStateChange(int state);
    static {
        System.loadLibrary("reciever");
    }

}
