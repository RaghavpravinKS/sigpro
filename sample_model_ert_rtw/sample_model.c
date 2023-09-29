/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sample_model.c
 *
 * Code generated for Simulink model 'sample_model'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 01:51:54 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sample_model.h"
#include "rtwtypes.h"
#include <math.h>
#include "sample_model_private.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block states (default storage) */
DW_sample_model_T sample_model_DW;

/* Real-time model */
static RT_MODEL_sample_model_T sample_model_M_;
RT_MODEL_sample_model_T *const sample_model_M = &sample_model_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void sample_model_step(void)
{
  real_T out[3];
  real_T a;
  real_T c_a;
  real32_T outData;
  char_T b_FormatStringTerminated[5];

  /* MATLABSystem: '<S2>/Location Sensor' */
  out[0] = 0.0;
  out[1] = 0.0;
  out[2] = 0.0;
  GET_LOCATION_DATA(&out[0], &out[1], &out[2]);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  MATLABSystem: '<S2>/Location Sensor'
   */
  a = sin(0.017453292519943295 * out[0] / 2.0);
  c_a = sin(0.017453292519943295 * out[1] / 2.0);
  a = cos(0.017453292519943295 * out[0]) * (c_a * c_a) + a * a;

  /* MATLABSystem: '<S1>/DataDisplay' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  outData = (real32_T)(rt_atan2d_snf(sqrt(a), sqrt(1.0 - a)) * 2.0 * 6371.0 >
                       2.0);
  b_FormatStringTerminated[0] = '%';
  b_FormatStringTerminated[1] = '.';
  b_FormatStringTerminated[2] = '6';
  b_FormatStringTerminated[3] = 'f';
  b_FormatStringTerminated[4] = '\x00';
  PUT_DATADISPLAY_DATA(&outData, 1.0, 8, 1, &b_FormatStringTerminated[0]);
}

/* Model initialize function */
void sample_model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for MATLABSystem: '<S2>/Location Sensor' */
  sample_model_DW.obj.matlabCodegenIsDeleted = false;
  sample_model_DW.obj.isInitialized = 1;
  INIT_LOCATION_SENSOR();
  sample_model_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/DataDisplay' */
  INITIALIZE_DATADISPLAY();
}

/* Model terminate function */
void sample_model_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Location Sensor' */
  if (!sample_model_DW.obj.matlabCodegenIsDeleted) {
    sample_model_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Location Sensor' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
