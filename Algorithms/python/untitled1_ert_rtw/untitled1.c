/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 16:08:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "untitled1_types.h"
#include "rtwtypes.h"
#include "untitled1_private.h"
#include <string.h>
#include <math.h>

/* Block signals (default storage) */
B_untitled1_T untitled1_B;

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

/* Forward declaration for local functions */
static void untitled1_SystemCore_setup(codertarget_internal_androidT_T *obj);
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

static void untitled1_SystemCore_setup(codertarget_internal_androidT_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[12];
  char_T ipaddr[12];
  uint8_T isLittleEndian;
  static const char_T tmp_1[12] = "10.7.20.134";
  int32_T str_size_idx_1;
  obj->isInitialized = 1;
  errorNo = obj->errorNo_;
  obj->isServer_ = 0.0;
  for (i = 0; i < 12; i++) {
    ipaddr[i] = tmp_1[i];
  }

  tmp = rt_roundd_snf(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  TCPStreamSetup(25000, 0, &obj->connStream_, tmp_0, 0.0, &obj->errorNo_,
                 &ipaddr[0]);
  littleEndianCheck(&isLittleEndian);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 1.0, 1, MAX_int16_T);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 12;
        for (i = 0; i < 12; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 1.0, 1, &b_str_data[0]);
    }
  }
}

/* Model step function */
void untitled1_step(void)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[12];
  char_T str_data[12];
  int8_T b_status;
  static const char_T tmp_1[12] = "10.7.20.134";
  int32_T str_size_idx_1;

  /* MATLABSystem: '<Root>/TCP//IP Receive' */
  errorNo = untitled1_DW.obj.errorNo_;
  tmp = rt_roundd_snf(untitled1_DW.obj.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  TCPStreamStepRecv(&untitled1_B.u0_tmp[0], &b_status, 25344,
                    untitled1_DW.obj.connStream_, &untitled1_DW.obj.errorNo_,
                    tmp_0);
  if ((errorNo != untitled1_DW.obj.errorNo_) && (untitled1_DW.obj.errorNo_ > 0) &&
      (untitled1_DW.obj.errorNo_ < 10)) {
    str_size_idx_1 = 1;
    str_data[0] = '\x00';
    if (untitled1_DW.obj.errorNo_ == 4) {
      UPDATE_TCP_LOGI(untitled1_DW.obj.errorNo_, 1.0, 1, MAX_int16_T);
    } else {
      if (untitled1_DW.obj.errorNo_ == 5) {
        str_size_idx_1 = 12;
        for (i = 0; i < 12; i++) {
          str_data[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &str_data[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(untitled1_DW.obj.errorNo_, 1.0, 1, &b_str_data[0]);
    }
  }

  /* End of MATLABSystem: '<Root>/TCP//IP Receive' */

  /* MATLABSystem: '<S2>/Video Display' */
  PUT_VIDEO_DISPLAY_DATA(&untitled1_B.u0_tmp[0], &untitled1_B.u0_tmp[0],
    &untitled1_B.u0_tmp[0]);
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/TCP//IP Receive' */
  untitled1_DW.obj.errorNo_ = 0;
  untitled1_DW.obj.isInitialized = 0;
  untitled1_SystemCore_setup(&untitled1_DW.obj);

  /* Start for MATLABSystem: '<S2>/Video Display' */
  INITIALIZE_VIDEO_DISPLAY(176, 144);
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
