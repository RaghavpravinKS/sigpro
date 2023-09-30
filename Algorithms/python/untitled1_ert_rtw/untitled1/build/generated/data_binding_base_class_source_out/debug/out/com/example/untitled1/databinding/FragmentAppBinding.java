// Generated by view binder compiler. Do not edit!
package com.example.untitled1.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import androidx.viewbinding.ViewBindings;
import com.example.untitled1.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class FragmentAppBinding implements ViewBinding {
  @NonNull
  private final LinearLayout rootView;

  @NonNull
  public final CameraScopeLayoutBinding cameraScopeLayout;

  @NonNull
  public final LinearLayout layoutapp;

  private FragmentAppBinding(@NonNull LinearLayout rootView,
      @NonNull CameraScopeLayoutBinding cameraScopeLayout, @NonNull LinearLayout layoutapp) {
    this.rootView = rootView;
    this.cameraScopeLayout = cameraScopeLayout;
    this.layoutapp = layoutapp;
  }

  @Override
  @NonNull
  public LinearLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static FragmentAppBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static FragmentAppBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.fragment_app, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static FragmentAppBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.camera_scope_layout;
      View cameraScopeLayout = ViewBindings.findChildViewById(rootView, id);
      if (cameraScopeLayout == null) {
        break missingId;
      }
      CameraScopeLayoutBinding binding_cameraScopeLayout = CameraScopeLayoutBinding.bind(cameraScopeLayout);

      LinearLayout layoutapp = (LinearLayout) rootView;

      return new FragmentAppBinding((LinearLayout) rootView, binding_cameraScopeLayout, layoutapp);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
