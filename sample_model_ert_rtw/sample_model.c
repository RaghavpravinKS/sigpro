/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sample_model.c
 *
 * Code generated for Simulink model 'sample_model'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 16 16:35:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sample_model.h"
#include "sample_model_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "sample_model_private.h"
#include <stddef.h>
#include <math.h>

/* Block signals (default storage) */
B_sample_model_T sample_model_B;

/* Block states (default storage) */
DW_sample_model_T sample_model_DW;

/* Real-time model */
static RT_MODEL_sample_model_T sample_model_M_;
RT_MODEL_sample_model_T *const sample_model_M = &sample_model_M_;

/* Forward declaration for local functions */
static void sample_model_SystemCore_setup(codertarget_internal_androidT_T *obj);
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
  (sample_model_M->Timing.TaskCounters.TID[1])++;
  if ((sample_model_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    sample_model_M->Timing.TaskCounters.TID[1] = 0;
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

static void sample_model_SystemCore_setup(codertarget_internal_androidT_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T b_str_data[16];
  char_T ipaddr[16];
  static const char_T tmp_1[16] = "192.168.240.220";
  int32_T str_size_idx_1;
  obj->isInitialized = 1;
  errorNo = obj->errorNo_;
  obj->isServer_ = 0.0;
  for (i = 0; i < 16; i++) {
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
  littleEndianCheck(&obj->isLittleEnd_);
  if ((errorNo != obj->errorNo_) && (obj->errorNo_ > 0) && (obj->errorNo_ < 10))
  {
    str_size_idx_1 = 1;
    ipaddr[0] = '\x00';
    if (obj->errorNo_ == 4) {
      UPDATE_TCP_LOGI(obj->errorNo_, 1.0, 0, MAX_int16_T);
    } else {
      if (obj->errorNo_ == 5) {
        str_size_idx_1 = 16;
        for (i = 0; i < 16; i++) {
          ipaddr[i] = tmp_1[i];
        }
      }

      memcpy(&b_str_data[0], &ipaddr[0], (uint32_T)str_size_idx_1 * sizeof
             (char_T));
      UPDATE_TCP_LOGS(obj->errorNo_, 1.0, 0, &b_str_data[0]);
    }
  }
}

/* Model step function */
void sample_model_step(void)
{
  real_T outData;
  int32_T sendPost;
  real32_T out[3];
  real32_T dataIn;
  int16_T errorNo;
  uint16_T tmp;
  char_T b_FormatStringTerminated[5];
  char_T b_FormatStringTerminated_0[5];
  uint8_T b_x[4];
  uint8_T xtmp;
  static const char_T tmp_0[16] = "192.168.240.220";
  int32_T str_size_idx_1;
  if (sample_model_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<S4>/Accelerometer' */
    out[0] = 0.0F;
    out[1] = 0.0F;
    out[2] = 0.0F;
    GET_ACCELEROMETER_DATA(&out[0], &out[1], &out[2]);

    /* MATLABSystem: '<S1>/DataDisplay' incorporates:
     *  MATLABSystem: '<S2>/DataDisplay'
     *  MATLABSystem: '<S3>/DataDisplay'
     *  MATLABSystem: '<S4>/Accelerometer'
     */
    outData = out[0];
    b_FormatStringTerminated_0[0] = '%';
    b_FormatStringTerminated_0[1] = '.';
    b_FormatStringTerminated_0[2] = '6';
    b_FormatStringTerminated_0[3] = 'f';
    b_FormatStringTerminated_0[4] = '\x00';
    for (sendPost = 0; sendPost < 5; sendPost++) {
      b_FormatStringTerminated[sendPost] = b_FormatStringTerminated_0[sendPost];
    }

    PUT_DATADISPLAY_DATA(&outData, 1.0, 9, 1, &b_FormatStringTerminated[0]);

    /* End of MATLABSystem: '<S1>/DataDisplay' */

    /* MATLABSystem: '<S2>/DataDisplay' incorporates:
     *  MATLABSystem: '<S4>/Accelerometer'
     */
    outData = out[1];
    for (sendPost = 0; sendPost < 5; sendPost++) {
      b_FormatStringTerminated[sendPost] = b_FormatStringTerminated_0[sendPost];
    }

    PUT_DATADISPLAY_DATA(&outData, 2.0, 9, 1, &b_FormatStringTerminated[0]);

    /* MATLABSystem: '<S3>/DataDisplay' incorporates:
     *  MATLABSystem: '<S4>/Accelerometer'
     */
    outData = out[2];
    PUT_DATADISPLAY_DATA(&outData, 3.0, 9, 1, &b_FormatStringTerminated_0[0]);

    /* MATLABSystem: '<Root>/TCP//IP Send' incorporates:
     *  MATLABSystem: '<S4>/Accelerometer'
     */
    errorNo = sample_model_DW.obj.errorNo_;
    dataIn = out[2];
    if (sample_model_DW.obj.isLittleEnd_ == 1) {
      memcpy((void *)&b_x[0], (void *)&out[2], (size_t)4 * sizeof(uint8_T));
      xtmp = b_x[0];
      b_x[0] = b_x[3];
      b_x[3] = xtmp;
      xtmp = b_x[1];
      b_x[1] = b_x[2];
      b_x[2] = xtmp;
      memcpy((void *)&dataIn, (void *)&b_x[0], (size_t)1 * sizeof(real32_T));
    }

    outData = rt_roundd_snf(sample_model_DW.obj.isServer_);
    if (outData < 65536.0) {
      if (outData >= 0.0) {
        tmp = (uint16_T)outData;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    TCPStreamStepSend(&dataIn, 4U, sample_model_DW.obj.connStream_, tmp,
                      &sample_model_DW.obj.errorNo_);
    if ((errorNo != sample_model_DW.obj.errorNo_) &&
        (sample_model_DW.obj.errorNo_ > 0) && (sample_model_DW.obj.errorNo_ < 10))
    {
      str_size_idx_1 = 1;
      sample_model_B.str_data[0] = '\x00';
      if (sample_model_DW.obj.errorNo_ == 4) {
        UPDATE_TCP_LOGI(sample_model_DW.obj.errorNo_, 1.0, 0, MAX_int16_T);
      } else {
        if (sample_model_DW.obj.errorNo_ == 5) {
          str_size_idx_1 = 16;
          for (sendPost = 0; sendPost < 16; sendPost++) {
            sample_model_B.str_data[sendPost] = tmp_0[sendPost];
          }
        }

        memcpy(&sample_model_B.b_str_data[0], &sample_model_B.str_data[0],
               (uint32_T)str_size_idx_1 * sizeof(char_T));
        UPDATE_TCP_LOGS(sample_model_DW.obj.errorNo_, 1.0, 0,
                        &sample_model_B.b_str_data[0]);
      }
    }

    /* End of MATLABSystem: '<Root>/TCP//IP Send' */

    /* MATLABSystem: '<Root>/ThingSpeak Write' incorporates:
     *  MATLABSystem: '<S4>/Accelerometer'
     */
    CHECK_UPDATE_INTERVAL(1.0, &sendPost);
    if (sendPost == 1) {
      ADD_FIELD(1.0, 1, (real_T)out[0]);
      ADD_FIELD(1.0, 2, (real_T)out[1]);
      ADD_FIELD(1.0, 3, (real_T)out[2]);
      ADD_FIELD(1.0, 4, 0.0);
      ADD_FIELD(1.0, 5, 0.0);
      ADD_FIELD(1.0, 6, 0.0);
      ADD_FIELD(1.0, 7, 0.0);
      ADD_FIELD(1.0, 8, 0.0);
      SEND_POST_REQUEST(1.0);
    }

    /* End of MATLABSystem: '<Root>/ThingSpeak Write' */
  }

  /* MATLABSystem: '<S11>/Location Sensor' */
  sample_model_B.out[0] = 0.0;
  sample_model_B.out[1] = 0.0;
  sample_model_B.out[2] = 0.0;
  GET_LOCATION_DATA(&sample_model_B.out[0], &sample_model_B.out[1],
                    &sample_model_B.out[2]);

  /* MATLABSystem: '<S5>/DataDisplay' incorporates:
   *  MATLABSystem: '<S10>/DataDisplay'
   *  MATLABSystem: '<S11>/Location Sensor'
   *  MATLABSystem: '<S12>/DataDisplay'
   *  MATLABSystem: '<S6>/DataDisplay'
   *  MATLABSystem: '<S7>/DataDisplay'
   *  MATLABSystem: '<S8>/DataDisplay'
   */
  b_FormatStringTerminated_0[0] = '%';
  b_FormatStringTerminated_0[1] = '.';
  b_FormatStringTerminated_0[2] = '6';
  b_FormatStringTerminated_0[3] = 'f';
  b_FormatStringTerminated_0[4] = '\x00';
  for (sendPost = 0; sendPost < 5; sendPost++) {
    b_FormatStringTerminated[sendPost] = b_FormatStringTerminated_0[sendPost];
  }

  PUT_DATADISPLAY_DATA(&sample_model_B.out[2], 4.0, 9, 1,
                       &b_FormatStringTerminated[0]);

  /* End of MATLABSystem: '<S5>/DataDisplay' */

  /* MATLABSystem: '<S10>/DataDisplay' incorporates:
   *  MATLABSystem: '<S11>/Location Sensor'
   */
  for (sendPost = 0; sendPost < 5; sendPost++) {
    b_FormatStringTerminated[sendPost] = b_FormatStringTerminated_0[sendPost];
  }

  PUT_DATADISPLAY_DATA(&sample_model_B.out[0], 8.0, 9, 1,
                       &b_FormatStringTerminated[0]);

  /* MATLABSystem: '<S12>/DataDisplay' incorporates:
   *  MATLABSystem: '<S11>/Location Sensor'
   */
  for (sendPost = 0; sendPost < 5; sendPost++) {
    b_FormatStringTerminated[sendPost] = b_FormatStringTerminated_0[sendPost];
  }

  PUT_DATADISPLAY_DATA(&sample_model_B.out[1], 9.0, 9, 1,
                       &b_FormatStringTerminated[0]);

  /* MATLABSystem: '<S9>/MATLAB System' */
  out[0] = 0.0F;
  out[1] = 0.0F;
  out[2] = 0.0F;
  GET_GYROSCOPE_DATA(&out[0], &out[1], &out[2]);

  /* MATLABSystem: '<S6>/DataDisplay' incorporates:
   *  MATLABSystem: '<S9>/MATLAB System'
   */
  outData = out[0];
  for (sendPost = 0; sendPost < 5; sendPost++) {
    b_FormatStringTerminated[sendPost] = b_FormatStringTerminated_0[sendPost];
  }

  PUT_DATADISPLAY_DATA(&outData, 5.0, 9, 1, &b_FormatStringTerminated[0]);

  /* MATLABSystem: '<S7>/DataDisplay' incorporates:
   *  MATLABSystem: '<S9>/MATLAB System'
   */
  outData = out[1];
  for (sendPost = 0; sendPost < 5; sendPost++) {
    b_FormatStringTerminated[sendPost] = b_FormatStringTerminated_0[sendPost];
  }

  PUT_DATADISPLAY_DATA(&outData, 6.0, 9, 1, &b_FormatStringTerminated[0]);

  /* MATLABSystem: '<S8>/DataDisplay' incorporates:
   *  MATLABSystem: '<S9>/MATLAB System'
   */
  outData = out[2];
  PUT_DATADISPLAY_DATA(&outData, 7.0, 9, 1, &b_FormatStringTerminated_0[0]);
  rate_scheduler();
}

/* Model initialize function */
void sample_model_initialize(void)
{
  {
    int32_T i;
    static const char_T tmp[17] = "F3AJHHWU1CZNX648";

    /* Start for MATLABSystem: '<S4>/Accelerometer' */
    sample_model_DW.obj_n.matlabCodegenIsDeleted = false;
    sample_model_DW.obj_n.isInitialized = 1;
    INITIALIZE_ACCELEROMETER();
    sample_model_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S2>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S3>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<Root>/TCP//IP Send' */
    sample_model_DW.obj.errorNo_ = 0;
    sample_model_DW.obj.isInitialized = 0;
    sample_model_SystemCore_setup(&sample_model_DW.obj);

    /* Start for MATLABSystem: '<Root>/ThingSpeak Write' */
    for (i = 0; i < 17; i++) {
      sample_model_B.b[i] = tmp[i];
    }

    INIT_THINGSPEAK_WRITE(1.0, 2.272726E+6, &sample_model_B.b[0], 30.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Write' */

    /* Start for MATLABSystem: '<S11>/Location Sensor' */
    sample_model_DW.obj_c.matlabCodegenIsDeleted = false;
    sample_model_DW.obj_c.isInitialized = 1;
    INIT_LOCATION_SENSOR();
    sample_model_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S10>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S12>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S9>/MATLAB System' */
    sample_model_DW.obj_h.matlabCodegenIsDeleted = false;
    sample_model_DW.obj_h.isInitialized = 1;
    INITIALIZE_GYROSCOPE();
    sample_model_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S7>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S8>/DataDisplay' */
    INITIALIZE_DATADISPLAY();
  }
}

/* Model terminate function */
void sample_model_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Accelerometer' */
  if (!sample_model_DW.obj_n.matlabCodegenIsDeleted) {
    sample_model_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Accelerometer' */

  /* Terminate for MATLABSystem: '<S11>/Location Sensor' */
  if (!sample_model_DW.obj_c.matlabCodegenIsDeleted) {
    sample_model_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S11>/Location Sensor' */

  /* Terminate for MATLABSystem: '<S9>/MATLAB System' */
  if (!sample_model_DW.obj_h.matlabCodegenIsDeleted) {
    sample_model_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
