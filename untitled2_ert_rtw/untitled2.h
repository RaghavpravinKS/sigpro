/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled2.h
 *
 * Code generated for Simulink model 'untitled2'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Sep 30 15:51:34 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled2_h_
#define RTW_HEADER_untitled2_h_
#ifndef untitled2_COMMON_INCLUDES_
#define untitled2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_accelerometer.h"
#include "driver_android_audioplayback.h"
#include "driver_android_datadisplay.h"
#endif                                 /* untitled2_COMMON_INCLUDES_ */

#include "untitled2_types.h"
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
  codertarget_internal_androi_i_T obj; /* '<S2>/Audio Playback' */
  codertarget_internal_androidA_T obj_f;/* '<S1>/Accelerometer' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
} DW_untitled2_T;

/* Parameters (default storage) */
struct P_untitled2_T_ {
  real_T AudioPlayback_SampleFreq;     /* Expression: SampleFreq
                                        * Referenced by: '<S2>/Audio Playback'
                                        */
  real_T SineWave_Amp;                 /* Expression: 10000/2
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 2.*pi.*10000
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled2_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_untitled2_T untitled2_P;

/* Block states (default storage) */
extern DW_untitled2_T untitled2_DW;

/* Model entry point functions */
extern void untitled2_initialize(void);
extern void untitled2_step(void);
extern void untitled2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled2_T *const untitled2_M;
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
 * '<Root>' : 'untitled2'
 * '<S1>'   : 'untitled2/Accelerometer'
 * '<S2>'   : 'untitled2/Audio Playback'
 * '<S3>'   : 'untitled2/Data Display'
 * '<S4>'   : 'untitled2/MATLAB Function'
 * '<S5>'   : 'untitled2/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_untitled2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
