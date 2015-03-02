/*
 * File: Rider_Controls_Control.c
 *
 * Code generated for Simulink model 'Rider_Controls_Control'.
 *
 * Model version                  : 1.96
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Feb 10 15:39:01 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Rider_Controls_Control.h"
#include "Rider_Controls_Control_private.h"

/* Block states (auto storage) */
D_Work_Rider_Controls_Control Rider_Controls_Control_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_Rider_Controls_C Rider_Controls_Control_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Rider_Controls_ Rider_Controls_Control_Y;

/* Real-time model */
RT_MODEL_Rider_Controls_Control Rider_Controls_Control_M_;
RT_MODEL_Rider_Controls_Control *const Rider_Controls_Control_M =
  &Rider_Controls_Control_M_;
real32_T look1_iflf_plinlgpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  uint32_T startIndex;

  /* Lookup 1-D
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  startIndex = prevIndex[0UL];

  /* Linear Search */
  while ((u0 < bp0[startIndex]) && (startIndex > 0UL)) {
    startIndex--;
  }

  while ((startIndex < maxIndex - 1UL) && (u0 >= bp0[startIndex + 1UL])) {
    startIndex++;
  }

  prevIndex[0UL] = startIndex;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (u0 - bp0[startIndex]) / (bp0[startIndex + 1UL] - bp0[startIndex]) *
    (table[startIndex + 1UL] - table[startIndex]) + table[startIndex];
}

/* Model step function */
void Rider_Controls_Control_step(void)
{
  real32_T rtb_RPMtoMaxMotorCurrent;
  real32_T rtb_Switch2;

  /* Lookup_n-D: '<Root>/RPM to Max Motor Current' incorporates:
   *  Inport: '<Root>/RPM'
   */
  rtb_RPMtoMaxMotorCurrent = look1_iflf_plinlgpw(Rider_Controls_Control_U.RPM,
    Rider_Controls_Control_ConstP.RPMtoMaxMotorCurren_o,
    Rider_Controls_Control_ConstP.RPMtoMaxMotorCurrent_,
    &Rider_Controls_Control_DWork.m_bpIndex, 3UL);

  /* Gain: '<Root>/To % Current' */
  rtb_Switch2 = 0.00333333341F * rtb_RPMtoMaxMotorCurrent;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Switch2 > 1.0F) {
    rtb_Switch2 = 1.0F;
  } else {
    if (rtb_Switch2 < 0.0F) {
      rtb_Switch2 = 0.0F;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Switch: '<S1>/Switch2' incorporates:
   *  Inport: '<Root>/Throttle %'
   *  RelationalOperator: '<S1>/LowerRelop1'
   */
  if (!(Rider_Controls_Control_U.Throttle > rtb_Switch2)) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  RelationalOperator: '<S1>/UpperRelop'
     */
    if (Rider_Controls_Control_U.Throttle < 0.0F) {
      rtb_Switch2 = 0.0F;
    } else {
      rtb_Switch2 = Rider_Controls_Control_U.Throttle;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Outport: '<Root>/Motor Current %' */
  Rider_Controls_Control_Y.MotorCurrent = rtb_Switch2;

  /* Outport: '<Root>/Lookup' */
  Rider_Controls_Control_Y.Lookup = rtb_RPMtoMaxMotorCurrent;
}

/* Model initialize function */
void Rider_Controls_Control_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Rider_Controls_Control_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Rider_Controls_Control_DWork, 0,
                sizeof(D_Work_Rider_Controls_Control));

  /* external inputs */
  Rider_Controls_Control_U.Throttle = 0.0F;
  Rider_Controls_Control_U.RPM = 0.0F;

  /* external outputs */
  Rider_Controls_Control_Y.MotorCurrent = 0.0F;
  Rider_Controls_Control_Y.Lookup = 0.0F;
}

/* Model terminate function */
void Rider_Controls_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
