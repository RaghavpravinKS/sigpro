/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sample_model_2.c
 *
 * Code generated for Simulink model 'sample_model_2'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 02:57:59 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sample_model_2.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "sample_model_2_private.h"
#include "rt_defines.h"

/* Block signals (default storage) */
B_sample_model_2_T sample_model_2_B;

/* Block states (default storage) */
DW_sample_model_2_T sample_model_2_DW;

/* Real-time model */
static RT_MODEL_sample_model_2_T sample_model_2_M_;
RT_MODEL_sample_model_2_T *const sample_model_2_M = &sample_model_2_M_;
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
void sample_model_2_step(void)
{
  real_T b_absxk;
  real_T b_t;
  real_T rtb_pitch;
  int32_T b_k;
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  char_T b_FormatStringTerminated[5];
  char_T b_FormatStringTerminated_0[5];

  /* MATLABSystem: '<S1>/Accelerometer' */
  sample_model_2_B.out[0] = 0.0F;
  sample_model_2_B.out[1] = 0.0F;
  sample_model_2_B.out[2] = 0.0F;
  GET_ACCELEROMETER_DATA(&sample_model_2_B.out[0], &sample_model_2_B.out[1],
    &sample_model_2_B.out[2]);

  /* MATLABSystem: '<S2>/MATLAB System' */
  sample_model_2_B.out_m[0] = 0.0F;
  sample_model_2_B.out_m[1] = 0.0F;
  sample_model_2_B.out_m[2] = 0.0F;
  GET_GYROSCOPE_DATA(&sample_model_2_B.out_m[0], &sample_model_2_B.out_m[1],
                     &sample_model_2_B.out_m[2]);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  MATLABSystem: '<S1>/Accelerometer'
   *  MATLABSystem: '<S2>/MATLAB System'
   */
  scale = 1.29246971E-26F;
  absxk = (real32_T)fabs(sample_model_2_B.out[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = (real32_T)fabs(sample_model_2_B.out[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = (real32_T)fabs(sample_model_2_B.out[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  t = scale * (real32_T)sqrt(y);
  sample_model_2_B.fv[0] = (real32_T)(-2.0 * sample_model_2_DW.q_est[2]);
  sample_model_2_B.fv[1] = (real32_T)(2.0 * sample_model_2_DW.q_est[3]);
  sample_model_2_B.fv[2] = (real32_T)(-2.0 * sample_model_2_DW.q_est[0]);
  sample_model_2_B.fv[3] = (real32_T)(2.0 * sample_model_2_DW.q_est[1]);
  sample_model_2_B.fv[4] = (real32_T)(2.0 * sample_model_2_DW.q_est[1]);
  sample_model_2_B.fv[5] = (real32_T)(2.0 * sample_model_2_DW.q_est[0]);
  sample_model_2_B.fv[6] = (real32_T)(2.0 * sample_model_2_DW.q_est[3]);
  sample_model_2_B.fv[7] = (real32_T)(2.0 * sample_model_2_DW.q_est[2]);
  sample_model_2_B.fv[8] = 0.0F;
  sample_model_2_B.fv[9] = (real32_T)(-4.0 * sample_model_2_DW.q_est[1]);
  sample_model_2_B.fv[10] = (real32_T)(-4.0 * sample_model_2_DW.q_est[2]);
  sample_model_2_B.fv[11] = 0.0F;
  scale = ((real32_T)(sample_model_2_DW.q_est[1] * sample_model_2_DW.q_est[3] -
                      sample_model_2_DW.q_est[0] * sample_model_2_DW.q_est[2]) -
           sample_model_2_B.out[0] / t) * 2.0F;
  absxk = ((real32_T)(sample_model_2_DW.q_est[0] * sample_model_2_DW.q_est[1] +
                      sample_model_2_DW.q_est[2] * sample_model_2_DW.q_est[3]) -
           sample_model_2_B.out[1] / t) * 2.0F;
  t = ((real32_T)((0.5 - sample_model_2_DW.q_est[1] * sample_model_2_DW.q_est[1])
                  - sample_model_2_DW.q_est[2] * sample_model_2_DW.q_est[2]) -
       sample_model_2_B.out[2] / t) * 2.0F;
  sample_model_2_B.fv1[0] = 0.0F;
  sample_model_2_B.fv1[1] = sample_model_2_B.out_m[0] * 0.05F;
  sample_model_2_B.fv1[2] = sample_model_2_B.out_m[1] * 0.05F;
  sample_model_2_B.fv1[3] = sample_model_2_B.out_m[2] * 0.05F;
  for (b_k = 0; b_k < 4; b_k++) {
    sample_model_2_B.qm = (sample_model_2_B.fv1[b_k] - ((sample_model_2_B.fv[b_k
      + 4] * absxk + sample_model_2_B.fv[b_k] * scale) + sample_model_2_B.fv[b_k
      + 8] * t) * 0.01F * 0.1F) * 0.1F + (real32_T)sample_model_2_DW.q_est[b_k];
    sample_model_2_DW.q_est[b_k] = sample_model_2_B.qm;
    sample_model_2_B.jj[b_k] = sample_model_2_B.qm;
    sample_model_2_B.c_y[b_k] = sample_model_2_B.qm * sample_model_2_B.qm;
  }

  sample_model_2_B.qm = sqrt(((sample_model_2_B.c_y[0] + sample_model_2_B.c_y[1])
    + sample_model_2_B.c_y[2]) + sample_model_2_B.c_y[3]);
  sample_model_2_B.b_scale = 3.3121686421112381E-170;
  rtb_pitch = sample_model_2_B.jj[0] / sample_model_2_B.qm;
  sample_model_2_B.jj[0] = rtb_pitch;
  b_absxk = fabs(rtb_pitch);
  if (b_absxk > 3.3121686421112381E-170) {
    sample_model_2_B.e_y = 1.0;
    sample_model_2_B.b_scale = b_absxk;
  } else {
    b_t = b_absxk / 3.3121686421112381E-170;
    sample_model_2_B.e_y = b_t * b_t;
  }

  rtb_pitch = sample_model_2_B.jj[1] / sample_model_2_B.qm;
  sample_model_2_B.jj[1] = rtb_pitch;
  b_absxk = fabs(rtb_pitch);
  if (b_absxk > sample_model_2_B.b_scale) {
    b_t = sample_model_2_B.b_scale / b_absxk;
    sample_model_2_B.e_y = sample_model_2_B.e_y * b_t * b_t + 1.0;
    sample_model_2_B.b_scale = b_absxk;
  } else {
    b_t = b_absxk / sample_model_2_B.b_scale;
    sample_model_2_B.e_y += b_t * b_t;
  }

  rtb_pitch = sample_model_2_B.jj[2] / sample_model_2_B.qm;
  sample_model_2_B.jj[2] = rtb_pitch;
  b_absxk = fabs(rtb_pitch);
  if (b_absxk > sample_model_2_B.b_scale) {
    b_t = sample_model_2_B.b_scale / b_absxk;
    sample_model_2_B.e_y = sample_model_2_B.e_y * b_t * b_t + 1.0;
    sample_model_2_B.b_scale = b_absxk;
  } else {
    b_t = b_absxk / sample_model_2_B.b_scale;
    sample_model_2_B.e_y += b_t * b_t;
  }

  rtb_pitch = sample_model_2_B.jj[3] / sample_model_2_B.qm;
  b_absxk = fabs(rtb_pitch);
  if (b_absxk > sample_model_2_B.b_scale) {
    b_t = sample_model_2_B.b_scale / b_absxk;
    sample_model_2_B.e_y = sample_model_2_B.e_y * b_t * b_t + 1.0;
    sample_model_2_B.b_scale = b_absxk;
  } else {
    b_t = b_absxk / sample_model_2_B.b_scale;
    sample_model_2_B.e_y += b_t * b_t;
  }

  sample_model_2_B.e_y = sample_model_2_B.b_scale * sqrt(sample_model_2_B.e_y);
  sample_model_2_B.jj[0] /= sample_model_2_B.e_y;
  sample_model_2_B.jj[1] /= sample_model_2_B.e_y;
  sample_model_2_B.jj[2] /= sample_model_2_B.e_y;
  sample_model_2_B.jj[3] = rtb_pitch / sample_model_2_B.e_y;
  sample_model_2_B.qm = (sample_model_2_B.jj[0] * sample_model_2_B.jj[2] -
    sample_model_2_B.jj[1] * sample_model_2_B.jj[3]) * 2.0;
  if (fabs(sample_model_2_B.qm) >= 1.0) {
    if (rtIsNaN(sample_model_2_B.qm)) {
      sample_model_2_B.qm = (rtNaN);
    } else if (sample_model_2_B.qm < 0.0) {
      sample_model_2_B.qm = -1.0;
    } else {
      sample_model_2_B.qm = (sample_model_2_B.qm > 0.0);
    }

    rtb_pitch = sample_model_2_B.qm * 3.1415926535897931 / 2.0;
  } else {
    rtb_pitch = asin(sample_model_2_B.qm);
  }

  sample_model_2_B.b_scale = sample_model_2_B.jj[2] * sample_model_2_B.jj[2];
  sample_model_2_B.qm = rt_atan2d_snf((sample_model_2_B.jj[0] *
    sample_model_2_B.jj[3] + sample_model_2_B.jj[1] * sample_model_2_B.jj[2]) *
    2.0, 1.0 - (sample_model_2_B.jj[3] * sample_model_2_B.jj[3] +
                sample_model_2_B.b_scale) * 2.0) * 57.295779513082323 *
    57.295779513082323;
  rtb_pitch = 57.295779513082323 * rtb_pitch * 57.295779513082323;
  sample_model_2_B.b_scale = rt_atan2d_snf((sample_model_2_B.jj[0] *
    sample_model_2_B.jj[1] + sample_model_2_B.jj[2] * sample_model_2_B.jj[3]) *
    2.0, 1.0 - (sample_model_2_B.jj[1] * sample_model_2_B.jj[1] +
                sample_model_2_B.b_scale) * 2.0) * 57.295779513082323 *
    57.295779513082323;

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* MATLABSystem: '<S4>/DataDisplay' incorporates:
   *  MATLABSystem: '<S5>/DataDisplay'
   *  MATLABSystem: '<S6>/DataDisplay'
   */
  b_FormatStringTerminated_0[0] = '%';
  b_FormatStringTerminated_0[1] = '.';
  b_FormatStringTerminated_0[2] = '6';
  b_FormatStringTerminated_0[3] = 'f';
  b_FormatStringTerminated_0[4] = '\x00';
  for (b_k = 0; b_k < 5; b_k++) {
    b_FormatStringTerminated[b_k] = b_FormatStringTerminated_0[b_k];
  }

  PUT_DATADISPLAY_DATA(&rtb_pitch, 1.0, 9, 1, &b_FormatStringTerminated[0]);

  /* End of MATLABSystem: '<S4>/DataDisplay' */

  /* MATLABSystem: '<S5>/DataDisplay' */
  for (b_k = 0; b_k < 5; b_k++) {
    b_FormatStringTerminated[b_k] = b_FormatStringTerminated_0[b_k];
  }

  PUT_DATADISPLAY_DATA(&sample_model_2_B.b_scale, 2.0, 9, 1,
                       &b_FormatStringTerminated[0]);

  /* MATLABSystem: '<S6>/DataDisplay' */
  PUT_DATADISPLAY_DATA(&sample_model_2_B.qm, 3.0, 9, 1,
                       &b_FormatStringTerminated_0[0]);
}

/* Model initialize function */
void sample_model_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
  sample_model_2_DW.q_est[0] = 1.0;
  sample_model_2_DW.q_est[1] = 0.0;
  sample_model_2_DW.q_est[2] = 0.0;
  sample_model_2_DW.q_est[3] = 0.0;

  /* Start for MATLABSystem: '<S1>/Accelerometer' */
  sample_model_2_DW.obj.matlabCodegenIsDeleted = false;
  sample_model_2_DW.obj.isInitialized = 1;
  INITIALIZE_ACCELEROMETER();
  sample_model_2_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/MATLAB System' */
  sample_model_2_DW.obj_i.matlabCodegenIsDeleted = false;
  sample_model_2_DW.obj_i.isInitialized = 1;
  INITIALIZE_GYROSCOPE();
  sample_model_2_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<S5>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<S6>/DataDisplay' */
  INITIALIZE_DATADISPLAY();
}

/* Model terminate function */
void sample_model_2_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Accelerometer' */
  if (!sample_model_2_DW.obj.matlabCodegenIsDeleted) {
    sample_model_2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Accelerometer' */

  /* Terminate for MATLABSystem: '<S2>/MATLAB System' */
  if (!sample_model_2_DW.obj_i.matlabCodegenIsDeleted) {
    sample_model_2_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
