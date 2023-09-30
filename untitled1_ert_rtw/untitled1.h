/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.h
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 15:13:31 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled1_h_
#define RTW_HEADER_untitled1_h_
#ifndef untitled1_COMMON_INCLUDES_
#define untitled1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_camera.h"
#include "driver_android_datadisplay.h"
#include "MW_TCPSendReceive.h"
#include "driver_android_tcp_log.h"
#endif                                 /* untitled1_COMMON_INCLUDES_ */

#include "untitled1_types.h"
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
  uint8_T b_varargout_3[25344];
  uint8_T b_varargout_2[25344];
  uint8_T b_varargout_1[25344];
  uint8_T y_d[25344];                  /* '<Root>/MATLAB Function3' */
  real32_T outData[80];
} B_untitled1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidT_T obj; /* '<Root>/TCP//IP Send2' */
  codertarget_internal_androidT_T obj_l;/* '<Root>/TCP//IP Send1' */
  codertarget_internal_androidT_T obj_b;/* '<Root>/TCP//IP Send' */
} DW_untitled1_T;

/* Real-time Model Data Structure */
struct tag_RTM_untitled1_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_untitled1_T untitled1_B;

/* Block states (default storage) */
extern DW_untitled1_T untitled1_DW;

/* Model entry point functions */
extern void untitled1_initialize(void);
extern void untitled1_step(void);
extern void untitled1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled1_T *const untitled1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'untitled1'
 * '<S1>'   : 'untitled1/Camera'
 * '<S2>'   : 'untitled1/Data Display'
 * '<S3>'   : 'untitled1/MATLAB Function1'
 * '<S4>'   : 'untitled1/MATLAB Function2'
 * '<S5>'   : 'untitled1/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_untitled1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
