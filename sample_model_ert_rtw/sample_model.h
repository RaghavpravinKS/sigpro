/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sample_model.h
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

#ifndef RTW_HEADER_sample_model_h_
#define RTW_HEADER_sample_model_h_
#ifndef sample_model_COMMON_INCLUDES_
#define sample_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_datadisplay.h"
#include "driver_android_location.h"
#endif                                 /* sample_model_COMMON_INCLUDES_ */

#include "sample_model_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidL_T obj; /* '<S2>/Location Sensor' */
} DW_sample_model_T;

/* Real-time Model Data Structure */
struct tag_RTM_sample_model_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_sample_model_T sample_model_DW;

/* Model entry point functions */
extern void sample_model_initialize(void);
extern void sample_model_step(void);
extern void sample_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sample_model_T *const sample_model_M;
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
 * '<Root>' : 'sample_model'
 * '<S1>'   : 'sample_model/Ang. Vel - x1'
 * '<S2>'   : 'sample_model/Location Sensor'
 * '<S3>'   : 'sample_model/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_sample_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
