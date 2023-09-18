/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: reciever.c
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

#include "reciever.h"
#include "rtwtypes.h"

/* Real-time model */
static RT_MODEL_reciever_T reciever_M_;
RT_MODEL_reciever_T *const reciever_M = &reciever_M_;

/* Model step function */
void reciever_step(void)
{
  real_T outData;
  int32_T i;
  real32_T Data;
  int16_T Status;
  char_T b_FormatStringTerminated[5];
  char_T b_FormatStringTerminated_0[5];

  /* MATLABSystem: '<Root>/ThingSpeak Read' */
  READ_THINGSPEAK_DATA(2272726U, &Data, &Status, 3);

  /* MATLABSystem: '<S1>/DataDisplay' incorporates:
   *  MATLABSystem: '<Root>/ThingSpeak Read'
   *  MATLABSystem: '<S2>/DataDisplay'
   */
  outData = Data;
  b_FormatStringTerminated_0[0] = '%';
  b_FormatStringTerminated_0[1] = '.';
  b_FormatStringTerminated_0[2] = '6';
  b_FormatStringTerminated_0[3] = 'f';
  b_FormatStringTerminated_0[4] = '\x00';
  for (i = 0; i < 5; i++) {
    b_FormatStringTerminated[i] = b_FormatStringTerminated_0[i];
  }

  PUT_DATADISPLAY_DATA(&outData, 1.0, 9, 1, &b_FormatStringTerminated[0]);

  /* End of MATLABSystem: '<S1>/DataDisplay' */

  /* MATLABSystem: '<S2>/DataDisplay' incorporates:
   *  MATLABSystem: '<Root>/ThingSpeak Read'
   */
  Data = Status;
  PUT_DATADISPLAY_DATA(&Data, 2.0, 8, 1, &b_FormatStringTerminated_0[0]);
}

/* Model initialize function */
void reciever_initialize(void)
{
  {
    int32_T i;
    char_T b[17];
    static const char_T tmp[17] = "8RPC9RT8II8J1ZYM";

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read' */
    for (i = 0; i < 17; i++) {
      b[i] = tmp[i];
    }

    INIT_THINGSPEAK_READ(2.272726E+6, &b[0], 3.0, 30.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read' */

    /* Start for MATLABSystem: '<S1>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<S2>/DataDisplay' */
    INITIALIZE_DATADISPLAY();
  }
}

/* Model terminate function */
void reciever_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
