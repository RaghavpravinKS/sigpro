/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: audio_sine_wave.h
 *
 * Code generated for Simulink model 'audio_sine_wave'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 20:11:37 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_audio_sine_wave_h_
#define RTW_HEADER_audio_sine_wave_h_
#ifndef audio_sine_wave_COMMON_INCLUDES_
#define audio_sine_wave_COMMON_INCLUDES_
#include "driver_android_plot.h"
#include "rtwtypes.h"
#include "driver_android_accelerometer.h"
#include "driver_android_datadisplay.h"
#endif                                 /* audio_sine_wave_COMMON_INCLUDES_ */

#include "audio_sine_wave_types.h"
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
  real32_T Accelerometer_o1;           /* '<S1>/Accelerometer' */
} B_audio_sine_wave_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidA_T obj; /* '<S1>/Accelerometer' */
  real32_T DigitalFilter_states[22];   /* '<S4>/Digital Filter' */
} DW_audio_sine_wave_T;

/* Parameters (default storage) */
struct P_audio_sine_wave_T_ {
  real32_T DigitalFilter_InitialStates;
                              /* Computed Parameter: DigitalFilter_InitialStates
                               * Referenced by: '<S4>/Digital Filter'
                               */
  real32_T DigitalFilter_Coefficients[23];
                               /* Computed Parameter: DigitalFilter_Coefficients
                                * Referenced by: '<S4>/Digital Filter'
                                */
};

/* Real-time Model Data Structure */
struct tag_RTM_audio_sine_wave_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_audio_sine_wave_T audio_sine_wave_P;

/* Block signals (default storage) */
extern B_audio_sine_wave_T audio_sine_wave_B;

/* Block states (default storage) */
extern DW_audio_sine_wave_T audio_sine_wave_DW;

/* Model entry point functions */
extern void audio_sine_wave_initialize(void);
extern void audio_sine_wave_step(void);
extern void audio_sine_wave_terminate(void);

/* Real-time Model object */
extern RT_MODEL_audio_sine_wave_T *const audio_sine_wave_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Check Signal Attributes' : Unused code path elimination
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
 * '<Root>' : 'audio_sine_wave'
 * '<S1>'   : 'audio_sine_wave/Accelerometer'
 * '<S2>'   : 'audio_sine_wave/Data Display'
 * '<S3>'   : 'audio_sine_wave/Data Display1'
 * '<S4>'   : 'audio_sine_wave/Digital Filter Design'
 * '<S5>'   : 'audio_sine_wave/Digital Filter Design/Check Signal Attributes'
 */
#endif                                 /* RTW_HEADER_audio_sine_wave_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
