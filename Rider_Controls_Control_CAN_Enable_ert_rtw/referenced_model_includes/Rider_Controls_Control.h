/*
 * File: Rider_Controls_Control.h
 *
 * Code generated for Simulink model 'Rider_Controls_Control'.
 *
 * Model version                  : 1.104
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Sun Mar 01 11:58:40 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_Control_h_
#define RTW_HEADER_Rider_Controls_Control_h_
#include <string.h>
#ifndef Rider_Controls_Control_COMMON_INCLUDES_
# define Rider_Controls_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Rider_Controls_Control_COMMON_INCLUDES_ */

#include "Rider_Controls_Control_types.h"

/* Shared type includes */
#include "model_reference_types.h"
#include "look1_iflf_plinlgpw.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

extern void enable_interrupts(void);

/* Block states (auto storage) for model 'Rider_Controls_Control' */
#ifndef Rider_Controls_Control_MDLREF_HIDE_CHILD_

typedef struct {
  uint32_T m_bpIndex;                  /* '<S1>/Battery Temp to Current' */
  uint32_T m_bpIndex_k;                /* '<S2>/RPM to Max Motor Current' */
} rtDW_Rider_Controls_Control;

#endif                                 /*Rider_Controls_Control_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_Control_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_Rider_Controls_Control {
  const char_T **errorStatus;
};

#endif                                 /*Rider_Controls_Control_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_Control_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_Rider_Controls_Control rtm;
} rtMdlrefDWork_Rider_Controls_Co;

#endif                                 /*Rider_Controls_Control_MDLREF_HIDE_CHILD_*/

extern void Rider_Controls_Control(const real32_T *rtu_Throttle, const real32_T *
  rtu_RPM, const real32_T *rtu_BatteryTempurature, real32_T *rty_MotorCurrent,
  real32_T *rty_RPM_Lookup, real32_T *rty_Batt_Lookup);

/* Model reference registration function */
extern void Rider_Controls_Contr_initialize(const char_T **rt_errorStatus);

#ifndef Rider_Controls_Control_MDLREF_HIDE_CHILD_

extern rtMdlrefDWork_Rider_Controls_Co Rider_Controls_Cont_MdlrefDWork;

#endif                                 /*Rider_Controls_Control_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_Control_MDLREF_HIDE_CHILD_

/* Block states (auto storage) */
extern rtDW_Rider_Controls_Control Rider_Controls_Control_DWork;

#endif                                 /*Rider_Controls_Control_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Rider_Controls_Control'
 * '<S1>'   : 'Rider_Controls_Control/Limit on Battery Temp'
 * '<S2>'   : 'Rider_Controls_Control/Limit on RPM'
 * '<S3>'   : 'Rider_Controls_Control/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_Rider_Controls_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
