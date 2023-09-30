/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: audio_sine_wave.c
 *
 * Code generated for Simulink model 'audio_sine_wave'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 20:11:37 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "audio_sine_wave.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_audio_sine_wave_T audio_sine_wave_B;

/* Block states (default storage) */
DW_audio_sine_wave_T audio_sine_wave_DW;

/* Real-time model */
static RT_MODEL_audio_sine_wave_T audio_sine_wave_M_;
RT_MODEL_audio_sine_wave_T *const audio_sine_wave_M = &audio_sine_wave_M_;

/* Model step function */
void audio_sine_wave_step(void)
{
  real_T outData;
  int32_T k;
  int32_T n;
  real32_T out[3];
  real32_T acc1;
  real32_T rtb_DigitalFilter;
  real32_T zCurr;
  char_T b_FormatStringTerminated[5];
  char_T b_FormatStringTerminated_0[5];

  /* MATLABSystem: '<S1>/Accelerometer' */
  out[0] = 0.0F;
  out[1] = 0.0F;
  out[2] = 0.0F;
  GET_ACCELEROMETER_DATA(&out[0], &out[1], &out[2]);

  /* MATLABSystem: '<S1>/Accelerometer' */
  audio_sine_wave_B.Accelerometer_o1 = out[0];

  /* MATLABSystem: '<S2>/DataDisplay' incorporates:
   *  MATLABSystem: '<S3>/DataDisplay'
   */
  outData = audio_sine_wave_B.Accelerometer_o1;
  b_FormatStringTerminated_0[0] = '%';
  b_FormatStringTerminated_0[1] = '.';
  b_FormatStringTerminated_0[2] = '6';
  b_FormatStringTerminated_0[3] = 'f';
  b_FormatStringTerminated_0[4] = '\x00';
  for (k = 0; k < 5; k++) {
    b_FormatStringTerminated[k] = b_FormatStringTerminated_0[k];
  }

  PUT_DATADISPLAY_DATA(&outData, 1.0, 9, 1, &b_FormatStringTerminated[0]);

  /* End of MATLABSystem: '<S2>/DataDisplay' */

  /* DiscreteFir: '<S4>/Digital Filter' */
  rtb_DigitalFilter = audio_sine_wave_B.Accelerometer_o1;
  for (k = 0; k < 1; k++) {
    acc1 = 0.0F;

    /* load input sample */
    for (n = 0; n < 22; n++) {
      /* shift state */
      zCurr = rtb_DigitalFilter;
      rtb_DigitalFilter = audio_sine_wave_DW.DigitalFilter_states[n];
      audio_sine_wave_DW.DigitalFilter_states[n] = zCurr;

      /* compute one tap */
      acc1 += audio_sine_wave_P.DigitalFilter_Coefficients[n] * zCurr;
    }

    /* compute last tap */
    /* store output sample */
    rtb_DigitalFilter = audio_sine_wave_P.DigitalFilter_Coefficients[n] *
      rtb_DigitalFilter + acc1;
  }

  /* End of DiscreteFir: '<S4>/Digital Filter' */

  /* MATLABSystem: '<S3>/DataDisplay' */
  outData = rtb_DigitalFilter;
  PUT_DATADISPLAY_DATA(&outData, 2.0, 9, 1, &b_FormatStringTerminated_0[0]);

  /* Scope: '<Root>/Scope' */
  /* Call plotting routine for a mobile target */
  {
    int_T scope1ID = 1;

    {
      int_T portIdx = 0;
      int_T signalWidth = 1;
      int_T sigNumDims = 2;
      int_T sigDims[2] = { 1, 1 };

      real32_T up0[1];
      up0[0] = (real32_T)audio_sine_wave_B.Accelerometer_o1;
      CACHE_PLOT_DATA(scope1ID,portIdx,up0,signalWidth,sigNumDims,sigDims);
    }

    {
      int_T portIdx = 1;
      int_T signalWidth = 1;
      int_T sigNumDims = 2;
      int_T sigDims[2] = { 1, 1 };

      real32_T up1[1];
      up1[0] = (real32_T)rtb_DigitalFilter;
      CACHE_PLOT_DATA(scope1ID,portIdx,up1,signalWidth,sigNumDims,sigDims);
    }

    PLOT_DATA(scope1ID);
  }

  /* End of Scope: '<Root>/Scope' */
}

/* Model initialize function */
void audio_sine_wave_initialize(void)
{
  {
    int32_T i;

    /* SetupRuntimeResources for Scope: '<Root>/Scope' */
    {
      const char* mobileScopeProperties1 =
        "{\"axesColor\":[0,0,0],\"axesScaling\":\"manual\",\"axesTickColor\":[0.6862745098039216,0.6862745098039216,0.6862745098039216],\"blockType\":\"Scope\",\"displays\":[{\"lineColors\":[[1,1,0.06666666666666667],[0.07450980392156863,0.6235294117647059,1],[1,0.4117647058823529,0.1607843137254902],[0.39215686274509803,0.8313725490196079,0.07450980392156863],[0.7176470588235294,0.27450980392156865,1],[0.058823529411764705,1,1],[1,0.07450980392156863,0.6509803921568628]],\"lineStyles\":[\"-\",\"-\",\"-\",\"-\",\"-\",\"-\",\"-\"],\"lineWidths\":[0.75,0.75,0.75,0.75,0.75,0.75,0.75],\"showGrid\":true,\"showLegend\":true,\"yLimits\":[-10,10]}],\"frameBasedProcessing\":false,\"inputNames\":[\"Accelerometer\\/1\",\"Digital Filter Design\"],\"layoutDimensions\":[1,1],\"timeSpan\":10.000000000000046,\"timeSpanOverrunMode\":\"Wrap\"}";
      int_T numInputPortsScope1 = 2;
      int_T scope1ID = 1;
      real32_T sampleTimes1[2] = { 0.1, 0.1 };

      INITIALIZE_PLOT(scope1ID,numInputPortsScope1,mobileScopeProperties1,
                      sampleTimes1);
    }

    /* End of Scope: '<Root>/Scope' */

    /* InitializeConditions for DiscreteFir: '<S4>/Digital Filter' */
    for (i = 0; i < 22; i++) {
      audio_sine_wave_DW.DigitalFilter_states[i] =
        audio_sine_wave_P.DigitalFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S4>/Digital Filter' */

    /* Start for MATLABSystem: '<S1>/Accelerometer' */
    audio_sine_wave_DW.obj.matlabCodegenIsDeleted = false;
    audio_sine_wave_DW.obj.isInitialized = 1;
    INITIALIZE_ACCELEROMETER();
    audio_sine_wave_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S3>/DataDisplay' */
    INITIALIZE_DATADISPLAY();
  }
}

/* Model terminate function */
void audio_sine_wave_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Accelerometer' */
  if (!audio_sine_wave_DW.obj.matlabCodegenIsDeleted) {
    audio_sine_wave_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Accelerometer' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
