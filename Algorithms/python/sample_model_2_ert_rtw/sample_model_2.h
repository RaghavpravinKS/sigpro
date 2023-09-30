/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sample_model_2.h
 *
 * Code generated for Simulink model 'sample_model_2'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 15:35:26 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sample_model_2_h_
#define RTW_HEADER_sample_model_2_h_
#ifndef sample_model_2_COMMON_INCLUDES_
#define sample_model_2_COMMON_INCLUDES_
#include "driver_android_plot.h"
#include "rtwtypes.h"
#include "driver_android_accelerometer.h"
#include "driver_android_gyroscope.h"
#include "driver_android_datadisplay.h"
#endif                                 /* sample_model_2_COMMON_INCLUDES_ */

#include "sample_model_2_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T fv[12];
  real_T jj[4];
  real_T c_y[4];
  real32_T fv1[4];
  real32_T out[3];
  real32_T out_m[3];
  real_T qm;
  real_T e_y;
  real_T b_scale;
} B_sample_model_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidA_T obj; /* '<S1>/Accelerometer' */
  codertarget_internal_androidG_T obj_i;/* '<S2>/MATLAB System' */
  real_T q_est[4];                     /* '<Root>/MATLAB Function1' */
} DW_sample_model_2_T;

/* Real-time Model Data Structure */
struct tag_RTM_sample_model_2_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_sample_model_2_T sample_model_2_B;

/* Block states (default storage) */
extern DW_sample_model_2_T sample_model_2_DW;

/* Model entry point functions */
extern void sample_model_2_initialize(void);
extern void sample_model_2_step(void);
extern void sample_model_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sample_model_2_T *const sample_model_2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Reshape' : Reshape block reduction
 * Block '<Root>/Reshape1' : Reshape block reduction
 * Block '<Root>/Reshape2' : Reshape block reduction
 * Block '<Root>/Reshape3' : Reshape block reduction
 * Block '<Root>/Reshape4' : Reshape block reduction
 * Block '<Root>/Reshape5' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sample_model_2'
 * '<S1>'   : 'sample_model_2/Accelerometer'
 * '<S2>'   : 'sample_model_2/Gyroscope'
 * '<S3>'   : 'sample_model_2/MATLAB Function1'
 * '<S4>'   : 'sample_model_2/Pitch'
 * '<S5>'   : 'sample_model_2/Roll'
 * '<S6>'   : 'sample_model_2/Yaw'
 */
#endif                                 /* RTW_HEADER_sample_model_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
