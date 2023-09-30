/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: reciever.c
 *
 * Code generated for Simulink model 'reciever'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 19:39:14 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "reciever.h"
#include "reciever_types.h"
#include "rtwtypes.h"
#include "reciever_private.h"
#include <math.h>
#include <string.h>

/* Block signals (default storage) */
B_reciever_T reciever_B;

/* Block states (default storage) */
DW_reciever_T reciever_DW;

/* Real-time model */
static RT_MODEL_reciever_T reciever_M_;
RT_MODEL_reciever_T *const reciever_M = &reciever_M_;

/* Forward declaration for local functions */
static void reciever_SystemCore_setup(codertarget_internal_androidT_T *obj);
static void reciever_SystemCore_setup_j(codertarget_internal_androidT_T *obj);
static void reciever_SystemCore_setup_j3(codertarget_internal_androidT_T *obj);
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
  (reciever_M->Timing.TaskCounters.TID[1])++;
  if ((reciever_M->Timing.TaskCounters.TID[1]) > 4409) {/* Sample time: [0.1s, 0.0s] */
    reciever_M->Timing.TaskCounters.TID[1] = 0;
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

static void reciever_SystemCore_setup(codertarget_internal_androidT_T *obj)
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

static void reciever_SystemCore_setup_j(codertarget_internal_androidT_T *obj)
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

  TCPStreamSetup(26000, 0, &obj->connStream_, tmp_0, 0.0, &obj->errorNo_,
                 &ipaddr[0]);
  littleEndianCheck(&isLittleEndian);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 2.0, 1, MAX_int16_T);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 12;
        for (i = 0; i < 12; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 2.0, 1, &b_str_data[0]);
    }
  }
}

static void reciever_SystemCore_setup_j3(codertarget_internal_androidT_T *obj)
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

  TCPStreamSetup(24000, 0, &obj->connStream_, tmp_0, 0.0, &obj->errorNo_,
                 &ipaddr[0]);
  littleEndianCheck(&isLittleEndian);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 3.0, 1, MAX_int16_T);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 12;
        for (i = 0; i < 12; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 3.0, 1, &b_str_data[0]);
    }
  }
}

/* Model step function */
void reciever_step(void)
{
  real_T lastSin_tmp;
  int32_T i;
  real32_T outData;
  int16_T rtb_TmpSignalConversionAtSFunct[2];
  int16_T errorNo;
  uint16_T tmp;
  char_T b_str_data[12];
  char_T b_FormatStringTerminated[5];
  char_T b_FormatStringTerminated_0[5];
  int8_T b_status;
  uint8_T b_data[4];
  static const char_T tmp_0[12] = "10.7.20.134";
  int32_T str_size_idx_1;
  if (reciever_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/TCP//IP Receive' */
    errorNo = reciever_DW.obj_p.errorNo_;
    lastSin_tmp = rt_roundd_snf(reciever_DW.obj_p.isServer_);
    if (lastSin_tmp < 65536.0) {
      if (lastSin_tmp >= 0.0) {
        tmp = (uint16_T)lastSin_tmp;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    TCPStreamStepRecv(&reciever_B.u0_tmp[0], &b_status, MAX_uint16_T,
                      reciever_DW.obj_p.connStream_, &reciever_DW.obj_p.errorNo_,
                      tmp);
    if ((errorNo != reciever_DW.obj_p.errorNo_) && (reciever_DW.obj_p.errorNo_ >
         0) && (reciever_DW.obj_p.errorNo_ < 10)) {
      str_size_idx_1 = 1;
      reciever_B.str_data[0] = '\x00';
      if (reciever_DW.obj_p.errorNo_ == 4) {
        UPDATE_TCP_LOGI(reciever_DW.obj_p.errorNo_, 1.0, 1, MAX_int16_T);
      } else {
        if (reciever_DW.obj_p.errorNo_ == 5) {
          str_size_idx_1 = 12;
          for (i = 0; i < 12; i++) {
            reciever_B.str_data[i] = tmp_0[i];
          }
        }

        memcpy(&b_str_data[0], &reciever_B.str_data[0], (uint32_T)str_size_idx_1
               * sizeof(char_T));
        UPDATE_TCP_LOGS(reciever_DW.obj_p.errorNo_, 1.0, 1, &b_str_data[0]);
      }
    }

    /* End of MATLABSystem: '<Root>/TCP//IP Receive' */

    /* MATLABSystem: '<S6>/Video Display' */
    PUT_VIDEO_DISPLAY_DATA(&reciever_B.u0_tmp[0], &reciever_B.u0_tmp[0],
      &reciever_B.u0_tmp[0]);

    /* MATLABSystem: '<Root>/TCP//IP Receive1' */
    errorNo = reciever_DW.obj_h5.errorNo_;
    lastSin_tmp = rt_roundd_snf(reciever_DW.obj_h5.isServer_);
    if (lastSin_tmp < 65536.0) {
      if (lastSin_tmp >= 0.0) {
        tmp = (uint16_T)lastSin_tmp;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    TCPStreamStepRecv(&b_data[0], &b_status, 4, reciever_DW.obj_h5.connStream_,
                      &reciever_DW.obj_h5.errorNo_, tmp);
    if ((errorNo != reciever_DW.obj_h5.errorNo_) && (reciever_DW.obj_h5.errorNo_
         > 0) && (reciever_DW.obj_h5.errorNo_ < 10)) {
      str_size_idx_1 = 1;
      reciever_B.str_data[0] = '\x00';
      if (reciever_DW.obj_h5.errorNo_ == 4) {
        UPDATE_TCP_LOGI(reciever_DW.obj_h5.errorNo_, 2.0, 1, MAX_int16_T);
      } else {
        if (reciever_DW.obj_h5.errorNo_ == 5) {
          str_size_idx_1 = 12;
          for (i = 0; i < 12; i++) {
            reciever_B.str_data[i] = tmp_0[i];
          }
        }

        memcpy(&b_str_data[0], &reciever_B.str_data[0], (uint32_T)str_size_idx_1
               * sizeof(char_T));
        UPDATE_TCP_LOGS(reciever_DW.obj_h5.errorNo_, 2.0, 1, &b_str_data[0]);
      }
    }

    /* MATLABSystem: '<S2>/DataDisplay' incorporates:
     *  MATLABSystem: '<Root>/TCP//IP Receive1'
     *  MATLABSystem: '<S3>/DataDisplay'
     *  MATLABSystem: '<S4>/DataDisplay'
     *  MATLABSystem: '<S5>/DataDisplay'
     */
    outData = b_data[0];
    b_FormatStringTerminated_0[0] = '%';
    b_FormatStringTerminated_0[1] = '.';
    b_FormatStringTerminated_0[2] = '6';
    b_FormatStringTerminated_0[3] = 'f';
    b_FormatStringTerminated_0[4] = '\x00';
    for (i = 0; i < 5; i++) {
      b_FormatStringTerminated[i] = b_FormatStringTerminated_0[i];
    }

    PUT_DATADISPLAY_DATA(&outData, 1.0, 8, 1, &b_FormatStringTerminated[0]);

    /* End of MATLABSystem: '<S2>/DataDisplay' */

    /* MATLABSystem: '<S3>/DataDisplay' incorporates:
     *  MATLABSystem: '<Root>/TCP//IP Receive1'
     */
    outData = b_data[1];
    for (i = 0; i < 5; i++) {
      b_FormatStringTerminated[i] = b_FormatStringTerminated_0[i];
    }

    PUT_DATADISPLAY_DATA(&outData, 2.0, 8, 1, &b_FormatStringTerminated[0]);

    /* MATLABSystem: '<S4>/DataDisplay' incorporates:
     *  MATLABSystem: '<Root>/TCP//IP Receive1'
     */
    outData = b_data[2];
    for (i = 0; i < 5; i++) {
      b_FormatStringTerminated[i] = b_FormatStringTerminated_0[i];
    }

    PUT_DATADISPLAY_DATA(&outData, 3.0, 8, 1, &b_FormatStringTerminated[0]);

    /* MATLABSystem: '<S5>/DataDisplay' incorporates:
     *  MATLABSystem: '<Root>/TCP//IP Receive1'
     */
    outData = b_data[3];
    PUT_DATADISPLAY_DATA(&outData, 4.0, 8, 1, &b_FormatStringTerminated_0[0]);
  }

  /* Sin: '<Root>/Sine Wave' */
  if (reciever_DW.systemEnable != 0) {
    lastSin_tmp = reciever_P.SineWave_Freq * ((reciever_M->Timing.clockTick0) *
      2.2675736961451248E-5);
    reciever_DW.lastSin = sin(lastSin_tmp);
    reciever_DW.lastCos = cos(lastSin_tmp);
    reciever_DW.systemEnable = 0;
  }

  if (reciever_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/TCP//IP Receive2' */
    errorNo = reciever_DW.obj_h.errorNo_;
    lastSin_tmp = rt_roundd_snf(reciever_DW.obj_h.isServer_);
    if (lastSin_tmp < 65536.0) {
      if (lastSin_tmp >= 0.0) {
        tmp = (uint16_T)lastSin_tmp;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    /* MATLABSystem: '<Root>/TCP//IP Receive2' */
    TCPStreamStepRecv(&reciever_B.TCPIPReceive2_o1, &b_status, 1,
                      reciever_DW.obj_h.connStream_, &reciever_DW.obj_h.errorNo_,
                      tmp);

    /* MATLABSystem: '<Root>/TCP//IP Receive2' */
    if ((errorNo != reciever_DW.obj_h.errorNo_) && (reciever_DW.obj_h.errorNo_ >
         0) && (reciever_DW.obj_h.errorNo_ < 10)) {
      str_size_idx_1 = 1;
      reciever_B.str_data[0] = '\x00';
      if (reciever_DW.obj_h.errorNo_ == 4) {
        UPDATE_TCP_LOGI(reciever_DW.obj_h.errorNo_, 3.0, 1, MAX_int16_T);
      } else {
        if (reciever_DW.obj_h.errorNo_ == 5) {
          str_size_idx_1 = 12;
          for (i = 0; i < 12; i++) {
            reciever_B.str_data[i] = tmp_0[i];
          }
        }

        memcpy(&b_str_data[0], &reciever_B.str_data[0], (uint32_T)str_size_idx_1
               * sizeof(char_T));
        UPDATE_TCP_LOGS(reciever_DW.obj_h.errorNo_, 3.0, 1, &b_str_data[0]);
      }
    }
  }

  /* Switch: '<Root>/Switch' */
  if (reciever_B.TCPIPReceive2_o1 >= reciever_P.Switch_Threshold) {
    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Sin: '<Root>/Sine Wave'
     */
    lastSin_tmp = rt_roundd_snf(((reciever_DW.lastSin * reciever_P.SineWave_PCos
      + reciever_DW.lastCos * reciever_P.SineWave_PSin) *
      reciever_P.SineWave_HCos + (reciever_DW.lastCos * reciever_P.SineWave_PCos
      - reciever_DW.lastSin * reciever_P.SineWave_PSin) *
      reciever_P.SineWave_Hsin) * reciever_P.SineWave_Amp +
      reciever_P.SineWave_Bias);
    if (lastSin_tmp < 32768.0) {
      if (lastSin_tmp >= -32768.0) {
        errorNo = (int16_T)lastSin_tmp;
      } else {
        errorNo = MIN_int16_T;
      }
    } else {
      errorNo = MAX_int16_T;
    }
  } else {
    /* MATLAB Function: '<Root>/MATLAB Function1' */
    errorNo = 0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* SignalConversion generated from: '<S10>/ SFunction ' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  rtb_TmpSignalConversionAtSFunct[0] = errorNo;
  rtb_TmpSignalConversionAtSFunct[1] = errorNo;

  /* MATLABSystem: '<S1>/Audio Playback' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  if (reciever_DW.obj.SampleFreq != reciever_P.AudioPlayback_SampleFreq) {
    reciever_DW.obj.SampleFreq = reciever_P.AudioPlayback_SampleFreq;
  }

  AUDIO_PLAYBACK(&rtb_TmpSignalConversionAtSFunct[0], reciever_DW.obj.FrameSize);

  /* End of MATLABSystem: '<S1>/Audio Playback' */
  if (reciever_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<S11>/DataDisplay' */
    outData = reciever_B.TCPIPReceive2_o1;
    b_FormatStringTerminated_0[0] = '%';
    b_FormatStringTerminated_0[1] = '.';
    b_FormatStringTerminated_0[2] = '1';
    b_FormatStringTerminated_0[3] = 'f';
    b_FormatStringTerminated_0[4] = '\x00';
    PUT_DATADISPLAY_DATA(&outData, 5.0, 8, 1, &b_FormatStringTerminated_0[0]);
  }

  /* Update for Sin: '<Root>/Sine Wave' */
  lastSin_tmp = reciever_DW.lastSin;
  reciever_DW.lastSin = reciever_DW.lastSin * reciever_P.SineWave_HCos +
    reciever_DW.lastCos * reciever_P.SineWave_Hsin;
  reciever_DW.lastCos = reciever_DW.lastCos * reciever_P.SineWave_HCos -
    lastSin_tmp * reciever_P.SineWave_Hsin;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 2.2675736961451248E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  reciever_M->Timing.clockTick0++;
  rate_scheduler();
}

/* Model initialize function */
void reciever_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/TCP//IP Receive' */
  reciever_DW.obj_p.errorNo_ = 0;
  reciever_DW.obj_p.isInitialized = 0;
  reciever_SystemCore_setup(&reciever_DW.obj_p);

  /* Start for MATLABSystem: '<S6>/Video Display' */
  INITIALIZE_VIDEO_DISPLAY(352, 288);

  /* Start for MATLABSystem: '<Root>/TCP//IP Receive1' */
  reciever_DW.obj_h5.errorNo_ = 0;
  reciever_DW.obj_h5.isInitialized = 0;
  reciever_SystemCore_setup_j(&reciever_DW.obj_h5);

  /* Start for MATLABSystem: '<S2>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<S3>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<S4>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<S5>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<Root>/TCP//IP Receive2' */
  reciever_DW.obj_h.errorNo_ = 0;
  reciever_DW.obj_h.isInitialized = 0;
  reciever_SystemCore_setup_j3(&reciever_DW.obj_h);

  /* Start for MATLABSystem: '<S1>/Audio Playback' */
  reciever_DW.obj.matlabCodegenIsDeleted = false;
  reciever_DW.obj.SampleFreq = reciever_P.AudioPlayback_SampleFreq;
  reciever_DW.obj.isInitialized = 1;
  reciever_DW.obj.FrameSize = 1.0;
  INIT_AUDIO_PLAYBACK(reciever_DW.obj.SampleFreq, reciever_DW.obj.FrameSize);
  reciever_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S11>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Enable for Sin: '<Root>/Sine Wave' */
  reciever_DW.systemEnable = 1;
}

/* Model terminate function */
void reciever_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Audio Playback' */
  if (!reciever_DW.obj.matlabCodegenIsDeleted) {
    reciever_DW.obj.matlabCodegenIsDeleted = true;
    if ((reciever_DW.obj.isInitialized == 1) && reciever_DW.obj.isSetupComplete)
    {
      TERMINATE_AUDIO_PLAYBACK();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Audio Playback' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
