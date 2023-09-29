/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 01:36:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  real_T rtb_y;
  real32_T out[3];
  char_T b_FormatStringTerminated[5];

  /* MATLABSystem: '<S1>/Accelerometer' */
  out[0] = 0.0F;
  out[1] = 0.0F;
  out[2] = 0.0F;
  GET_ACCELEROMETER_DATA(&out[0], &out[1], &out[2]);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  MATLABSystem: '<S1>/Accelerometer'
   */
  rtb_y = out[0] * 100.0F;

  /* MATLABSystem: '<S2>/DataDisplay' */
  b_FormatStringTerminated[0] = '%';
  b_FormatStringTerminated[1] = '.';
  b_FormatStringTerminated[2] = '6';
  b_FormatStringTerminated[3] = 'f';
  b_FormatStringTerminated[4] = '\x00';
  PUT_DATADISPLAY_DATA(&rtb_y, 1.0, 9, 1, &b_FormatStringTerminated[0]);
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for MATLABSystem: '<S1>/Accelerometer' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isInitialized = 1;
  INITIALIZE_ACCELEROMETER();
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/DataDisplay' */
  INITIALIZE_DATADISPLAY();
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Accelerometer' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Accelerometer' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
