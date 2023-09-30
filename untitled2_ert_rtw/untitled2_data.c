/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled2_data.c
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

#include "untitled2.h"

/* Block parameters (default storage) */
P_untitled2_T untitled2_P = {
  /* Expression: SampleFreq
   * Referenced by: '<S2>/Audio Playback'
   */
  44100.0,

  /* Expression: 10000/2
   * Referenced by: '<Root>/Sine Wave'
   */
  5000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 2.*pi.*10000
   * Referenced by: '<Root>/Sine Wave'
   */
  62831.853071795864,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<Root>/Sine Wave'
   */
  0.98935542552457467,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.14551921517479305,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<Root>/Sine Wave'
   */
  -0.98935542552457467,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.14551921517479305
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
