/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: reciever.h
 *
 * Code generated for Simulink model 'reciever'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 16 16:35:17 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_reciever_h_
#define RTW_HEADER_reciever_h_
#ifndef reciever_COMMON_INCLUDES_
#define reciever_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_datadisplay.h"
#include "driver_android_thingspeak_read.h"
#endif                                 /* reciever_COMMON_INCLUDES_ */

#include "reciever_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_reciever_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void reciever_initialize(void);
extern void reciever_step(void);
extern void reciever_terminate(void);

/* Real-time Model object */
extern RT_MODEL_reciever_T *const reciever_M;
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
 * '<Root>' : 'reciever'
 * '<S1>'   : 'reciever/Data Display'
 * '<S2>'   : 'reciever/Data Display1'
 */
#endif                                 /* RTW_HEADER_reciever_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
