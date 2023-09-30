/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled2.c
 *
 * Code generated for Simulink model 'untitled2'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 15:51:34 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled2.h"
#include "rtwtypes.h"
#include <math.h>
#include "untitled2_private.h"

/* Block states (default storage) */
DW_untitled2_T untitled2_DW;

/* Real-time model */
static RT_MODEL_untitled2_T untitled2_M_;
RT_MODEL_untitled2_T *const untitled2_M = &untitled2_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (untitled2_M->Timing.TaskCounters.TID[1])++;
  if ((untitled2_M->Timing.TaskCounters.TID[1]) > 4409) {/* Sample time: [0.1s, 0.0s] */
    untitled2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void untitled2_step(void)
{
  real_T outData;
  real32_T out[3];
  int16_T rtb_TmpSignalConversionAtSFunct[2];
  int16_T rtb_y_l_0;
  char_T b_FormatStringTerminated[5];

  /* Sin: '<Root>/Sine Wave' */
  if (untitled2_DW.systemEnable != 0) {
    outData = untitled2_P.SineWave_Freq * ((untitled2_M->Timing.clockTick0) *
      2.2675736961451248E-5);
    untitled2_DW.lastSin = sin(outData);
    untitled2_DW.lastCos = cos(outData);
    untitled2_DW.systemEnable = 0;
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  outData = rt_roundd_snf(((untitled2_DW.lastSin * untitled2_P.SineWave_PCos +
    untitled2_DW.lastCos * untitled2_P.SineWave_PSin) *
    untitled2_P.SineWave_HCos + (untitled2_DW.lastCos *
    untitled2_P.SineWave_PCos - untitled2_DW.lastSin * untitled2_P.SineWave_PSin)
    * untitled2_P.SineWave_Hsin) * untitled2_P.SineWave_Amp +
    untitled2_P.SineWave_Bias);
  if (outData < 32768.0) {
    if (outData >= -32768.0) {
      rtb_y_l_0 = (int16_T)outData;
    } else {
      rtb_y_l_0 = MIN_int16_T;
    }
  } else {
    rtb_y_l_0 = MAX_int16_T;
  }

  /* SignalConversion generated from: '<S5>/ SFunction ' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  rtb_TmpSignalConversionAtSFunct[0] = rtb_y_l_0;
  rtb_TmpSignalConversionAtSFunct[1] = rtb_y_l_0;

  /* MATLABSystem: '<S2>/Audio Playback' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  if (untitled2_DW.obj.SampleFreq != untitled2_P.AudioPlayback_SampleFreq) {
    untitled2_DW.obj.SampleFreq = untitled2_P.AudioPlayback_SampleFreq;
  }

  AUDIO_PLAYBACK(&rtb_TmpSignalConversionAtSFunct[0], untitled2_DW.obj.FrameSize);

  /* End of MATLABSystem: '<S2>/Audio Playback' */
  if (untitled2_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<S1>/Accelerometer' */
    out[0] = 0.0F;
    out[1] = 0.0F;
    out[2] = 0.0F;
    GET_ACCELEROMETER_DATA(&out[0], &out[1], &out[2]);

    /* MATLABSystem: '<S3>/DataDisplay' incorporates:
     *  MATLABSystem: '<S1>/Accelerometer'
     */
    outData = out[0];
    b_FormatStringTerminated[0] = '%';
    b_FormatStringTerminated[1] = '.';
    b_FormatStringTerminated[2] = '6';
    b_FormatStringTerminated[3] = 'f';
    b_FormatStringTerminated[4] = '\x00';
    PUT_DATADISPLAY_DATA(&outData, 1.0, 9, 1, &b_FormatStringTerminated[0]);
  }

  /* Update for Sin: '<Root>/Sine Wave' */
  outData = untitled2_DW.lastSin;
  untitled2_DW.lastSin = untitled2_DW.lastSin * untitled2_P.SineWave_HCos +
    untitled2_DW.lastCos * untitled2_P.SineWave_Hsin;
  untitled2_DW.lastCos = untitled2_DW.lastCos * untitled2_P.SineWave_HCos -
    outData * untitled2_P.SineWave_Hsin;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 2.2675736961451248E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled2_M->Timing.clockTick0++;
  rate_scheduler();
}

/* Model initialize function */
void untitled2_initialize(void)
{
  /* Start for MATLABSystem: '<S2>/Audio Playback' */
  untitled2_DW.obj.matlabCodegenIsDeleted = false;
  untitled2_DW.obj.SampleFreq = untitled2_P.AudioPlayback_SampleFreq;
  untitled2_DW.obj.isInitialized = 1;
  untitled2_DW.obj.FrameSize = 1.0;
  INIT_AUDIO_PLAYBACK(untitled2_DW.obj.SampleFreq, untitled2_DW.obj.FrameSize);
  untitled2_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Accelerometer' */
  untitled2_DW.obj_f.matlabCodegenIsDeleted = false;
  untitled2_DW.obj_f.isInitialized = 1;
  INITIALIZE_ACCELEROMETER();
  untitled2_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Enable for Sin: '<Root>/Sine Wave' */
  untitled2_DW.systemEnable = 1;
}

/* Model terminate function */
void untitled2_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Audio Playback' */
  if (!untitled2_DW.obj.matlabCodegenIsDeleted) {
    untitled2_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled2_DW.obj.isInitialized == 1) &&
        untitled2_DW.obj.isSetupComplete) {
      TERMINATE_AUDIO_PLAYBACK();
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Audio Playback' */

  /* Terminate for MATLABSystem: '<S1>/Accelerometer' */
  if (!untitled2_DW.obj_f.matlabCodegenIsDeleted) {
    untitled2_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Accelerometer' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
