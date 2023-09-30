/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: reciever.h
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

#ifndef RTW_HEADER_reciever_h_
#define RTW_HEADER_reciever_h_
#ifndef reciever_COMMON_INCLUDES_
#define reciever_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_audioplayback.h"
#include "driver_android_datadisplay.h"
#include "driver_android_videodisplay.h"
#include "MW_TCPSendReceive.h"
#include "driver_android_tcp_log.h"
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

/* Block signals (default storage) */
typedef struct {
  uint8_T u0_tmp[101376];
  char_T str_data[12];
  uint8_T TCPIPReceive2_o1;            /* '<Root>/TCP//IP Receive2' */
} B_reciever_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidA_T obj; /* '<S1>/Audio Playback' */
  codertarget_internal_androidT_T obj_h;/* '<Root>/TCP//IP Receive2' */
  codertarget_internal_androidT_T obj_h5;/* '<Root>/TCP//IP Receive1' */
  codertarget_internal_androidT_T obj_p;/* '<Root>/TCP//IP Receive' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
} DW_reciever_T;

/* Parameters (default storage) */
struct P_reciever_T_ {
  real_T AudioPlayback_SampleFreq;     /* Expression: SampleFreq
                                        * Referenced by: '<S1>/Audio Playback'
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
  uint8_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_reciever_T {
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
extern P_reciever_T reciever_P;

/* Block signals (default storage) */
extern B_reciever_T reciever_B;

/* Block states (default storage) */
extern DW_reciever_T reciever_DW;

/* Model entry point functions */
extern void reciever_initialize(void);
extern void reciever_step(void);
extern void reciever_terminate(void);

/* Real-time Model object */
extern RT_MODEL_reciever_T *const reciever_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
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
 * '<Root>' : 'reciever'
 * '<S1>'   : 'reciever/Audio Playback'
 * '<S2>'   : 'reciever/Current Lattitude of child'
 * '<S3>'   : 'reciever/Current Longitude of child'
 * '<S4>'   : 'reciever/Current Speed of child'
 * '<S5>'   : 'reciever/Current distance of child from home'
 * '<S6>'   : 'reciever/Footage from child's phone'
 * '<S7>'   : 'reciever/MATLAB Function'
 * '<S8>'   : 'reciever/MATLAB Function1'
 * '<S9>'   : 'reciever/MATLAB Function2'
 * '<S10>'  : 'reciever/MATLAB Function3'
 * '<S11>'  : 'reciever/Met with an accident => 1            Riding safely =>  0'
 */
#endif                                 /* RTW_HEADER_reciever_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
