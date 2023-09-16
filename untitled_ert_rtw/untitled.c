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
 * C/C++ source code generated on : Thu Sep 14 19:22:26 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_SystemCore_step(uint8_T varargout_1[307200], uint8_T
  varargout_2[307200], uint8_T varargout_3[307200]);
static void untitled_SystemCore_step(uint8_T varargout_1[307200], uint8_T
  varargout_2[307200], uint8_T varargout_3[307200])
{
  GET_CAMERA_DATA(&varargout_1[0], &varargout_2[0], &varargout_3[0]);
}

/* Model step function */
void untitled_step(void)
{
  real_T out_0[3];
  real_T outData;
  real32_T out[3];
  char_T b_FormatStringTerminated[5];

  /* MATLABSystem: '<S2>/Camera' */
  untitled_SystemCore_step(untitled_B.b_varargout_1, untitled_B.b_varargout_2,
    untitled_B.b_varargout_3);

  /* MATLABSystem: '<S5>/Video Display' incorporates:
   *  MATLABSystem: '<S2>/Camera'
   */
  PUT_VIDEO_DISPLAY_DATA(&untitled_B.b_varargout_1[0],
    &untitled_B.b_varargout_2[0], &untitled_B.b_varargout_3[0]);

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

  /* MATLABSystem: '<S4>/Location Sensor' */
  out_0[0] = 0.0;
  out_0[1] = 0.0;
  out_0[2] = 0.0;
  GET_LOCATION_DATA(&out_0[0], &out_0[1], &out_0[2]);
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for MATLABSystem: '<S2>/Camera' */
  untitled_DW.obj_d.isInitialized = 1;
  INITIALIZE_CAMERA(0.1, 2, 640, 480);

  /* Start for MATLABSystem: '<S5>/Video Display' */
  INITIALIZE_VIDEO_DISPLAY(640, 480);

  /* Start for MATLABSystem: '<S1>/Accelerometer' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isInitialized = 1;
  INITIALIZE_ACCELEROMETER();
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<S4>/Location Sensor' */
  untitled_DW.obj_c.matlabCodegenIsDeleted = false;
  untitled_DW.obj_c.isInitialized = 1;
  INIT_LOCATION_SENSOR();
  untitled_DW.obj_c.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Accelerometer' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Accelerometer' */

  /* Terminate for MATLABSystem: '<S4>/Location Sensor' */
  if (!untitled_DW.obj_c.matlabCodegenIsDeleted) {
    untitled_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Location Sensor' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
