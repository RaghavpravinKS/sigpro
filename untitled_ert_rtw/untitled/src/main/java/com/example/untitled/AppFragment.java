package com.example.untitled;

/* Copyright 2016-2021 The MathWorks, Inc. */

import android.app.Activity;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.res.ResourcesCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.viewpager2.widget.ViewPager2;

import com.example.untitled.databinding.FragmentAppBinding;
import com.google.android.material.tabs.TabLayout;
import com.google.android.material.tabs.TabLayoutMediator;


public class AppFragment extends Fragment {

    FragmentAppBinding fragmentAppBinding;
    
    private final CountDownTimer timerZoomButton = new CountDownTimer(5000, 1000) {
        @Override
        public void onTick(long l) {
            fragmentAppBinding.cameraScopeLayout.btnZoom.setAlpha(0.5f + 0.1f * l);
        }

        @Override
        public void onFinish() {
            fragmentAppBinding.cameraScopeLayout.btnZoom.setAlpha(0.4f);
        }
    };
	

    
    private OnFragmentInteractionListener mListener;
    private boolean isWidgetsLayoutHidden = false;

    public AppFragment() {
    }

    public static AppFragment newInstance() {
        AppFragment fragment = new AppFragment();
        Bundle args = new Bundle();
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (mListener == null) {
            try {
                mListener = (OnFragmentInteractionListener) getActivity();
            } catch (ClassCastException e) {
                throw new ClassCastException(getActivity().toString()
                        + " must implement OnFragmentInteractionListener");
            }
        }
        mListener.onFragmentCreate("App");
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        fragmentAppBinding = FragmentAppBinding.inflate(inflater, container, false);
        return fragmentAppBinding.getRoot();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        this.registerCameraScopeLayout();
    }

    @Override
    public void onDetach() {
        super.onDetach();
        mListener = null;
    }

    @Override
    public void onStart() {
        super.onStart();
        mListener.onFragmentStart("App");
    }

    @Override
    public void onResume() {
        super.onResume();
        mListener.onFragmentResume("App");
    }

    @Override
    public void onPause() {
        super.onPause();
        mListener.onFragmentPause("App");
    }

    public void setFragmentInteractionListener(Activity activity) {
        try {
            mListener = (OnFragmentInteractionListener) activity;
        } catch (ClassCastException e) {
            throw new ClassCastException(activity.toString()
                    + " must implement OnFragmentInteractionListener");
        }
    }

    private void registerCameraScopeLayout() {
        // Create the adapter that will return a fragment for each of the three
        // primary sections of the activity.
        CameraScopeSectionsPagerAdapter mCameraScopeAdapter = new CameraScopeSectionsPagerAdapter((FragmentActivity) mListener);

        // Set up the ViewPager with the sections adapter.
        ViewPager2 mCameraScopePager = fragmentAppBinding.cameraScopeLayout.cameraScopeContainer;
        mCameraScopePager.setOffscreenPageLimit(mCameraScopeAdapter.getItemCount());
        mCameraScopePager.setAdapter(mCameraScopeAdapter);

        new TabLayoutMediator(fragmentAppBinding.cameraScopeLayout.dots, mCameraScopePager,
                new TabLayoutMediator.TabConfigurationStrategy() {
                    @Override
                    public void onConfigureTab(@NonNull TabLayout.Tab tab, int position) {
                    }
                }
        ).attach();
        ImageButton btnZoom = fragmentAppBinding.cameraScopeLayout.btnZoom;
        btnZoom.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.setVisibility(View.INVISIBLE);

                if (isWidgetsLayoutHidden) {

                    isWidgetsLayoutHidden = false;
                    ((ImageButton) view).setImageDrawable(ResourcesCompat.getDrawable(getResources(), R.drawable.expand, null));
                } else {

                    isWidgetsLayoutHidden = true;
                    ((ImageButton) view).setImageDrawable(ResourcesCompat.getDrawable(getResources(), R.drawable.shrink, null));
                }
                view.setVisibility(View.VISIBLE);
                view.setAlpha(1.0f);
                timerZoomButton.start();
            }
        });
        timerZoomButton.start();
    }

    
}
