package com.example.untitled2;

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
import com.example.untitled2.databinding.ActivityMainBinding;
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
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.widget.TextView;
import java.util.Hashtable;
import android.annotation.TargetApi;
import android.os.Build;
import android.content.Context;
import android.media.AudioManager;

public class untitled2 extends AppCompatActivity implements OnFragmentInteractionListener , SensorEventListener {
    private InfoFragment infoFragment;
    private AppFragment appFragment;
     FragmentManager fm;
     Fragment current;
     private Hashtable<Integer,TextView> textViews = new Hashtable<Integer,TextView>();
     private float[] mAccelerometerData = { 0.0f, 0.0f, 0.0f };
     private SensorManager mSensorManager;
    String nativeSampleRate;
    String nativeSampleBufSize;

     private void registerSensorManager() {
        mSensorManager.registerListener(this,
            mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER),
            SensorManager.SENSOR_DELAY_FASTEST);
     }

    private boolean checkIfAllPermissionsGranted()
    {
        return true;
    }
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        com.example.untitled2.databinding.ActivityMainBinding activityMainBinding = ActivityMainBinding.inflate(LayoutInflater.from(this));
        setContentView(activityMainBinding.getRoot());
        fm = getSupportFragmentManager();
        Fragment navHostFragment = fm.findFragmentById(R.id.nav_host_fragment);
        navHostFragment = navHostFragment.getChildFragmentManager().getFragments().get(0);
        current =  navHostFragment;
        appFragment  = (AppFragment) navHostFragment;
        infoFragment  = new InfoFragment();
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
        return true;                }
                return false;
                }
        });
        // Initiate the SensorManager
        mSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        queryNativeAudioParameters();
        thisClass = this;
     }

    private untitled2 thisClass;
    private final Thread BgThread = new Thread() {
    @Override
    public void run() {
            String argv[] = new String[] {"MainActivity","untitled2"};
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
         super.onDestroy();
         System.exit(0); //to kill all our threads.
    }

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
         registerSensorManager();
    }

    @Override
    protected void onPause() {
        if (BgThread.isAlive())
            naOnAppStateChange(4);
         mSensorManager.unregisterListener(this);
        super.onPause();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    public void registerDataDisplays() {
    // bind text views for data display block;
    for (int i = 1; i <= 1; i++) {
            TextView textView = (TextView) findViewById(
            getResources().getIdentifier("DataDisplay" + i, "id", getPackageName()));
            textViews.put(i, textView);
        }
    }
    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        float [] values = event.values;
        //Comment out if you want to log the data in logcat
        //String logMessage = String.format("%d: 0'%g'", event.sensor.getType(), values[0]);
        //Log.d("Sensor Data IN:", logMessage);
        switch(event.sensor.getType()) {
            case Sensor.TYPE_ACCELEROMETER:
                mAccelerometerData[0] = values[0];
                mAccelerometerData[1] = values[1];
                mAccelerometerData[2] = values[2];
                break;
        }
    }

    // Get SensorEvent Data throws exception if the data is null
    public float[] getAccelerometerData() {
        return mAccelerometerData;
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
                    Log.e("untitled2.updateTextViewById", ex.getLocalizedMessage());
                }
            }
        });
    }
    @TargetApi(Build.VERSION_CODES.JELLY_BEAN_MR1)
    private void queryNativeAudioParameters() {
        Log.d("audioEQ", "queryNativeAudioParameters called");
        AudioManager myAudioMgr = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
        nativeSampleRate = myAudioMgr.getProperty(AudioManager.PROPERTY_OUTPUT_SAMPLE_RATE);
        nativeSampleBufSize = myAudioMgr.getProperty(AudioManager.PROPERTY_OUTPUT_FRAMES_PER_BUFFER);
    }

    public int getNativeSampleRate() {
        Log.d("audioEQ", "JNI getNativeSampleRate called");
        return Integer.parseInt(nativeSampleRate);
    }
    public int getNativeSampleBufSize() {
        Log.d("audioEQ", "JNI getNativeSampleBufSize called");
        return Integer.parseInt(nativeSampleBufSize);
    }
    private native int naMain(String[] argv, untitled2 pThis);
    private native void naOnAppStateChange(int state);
    static {
        System.loadLibrary("untitled2");
    }

}
