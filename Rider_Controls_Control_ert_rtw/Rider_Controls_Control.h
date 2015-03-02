/*
 * File: Rider_Controls_Control.h
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

#ifndef RTW_HEADER_Rider_Controls_Control_h_
#define RTW_HEADER_Rider_Controls_Control_h_
#include <stddef.h>
#include <string.h>
#ifndef Rider_Controls_Control_COMMON_INCLUDES_
# define Rider_Controls_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Rider_Controls_Control_COMMON_INCLUDES_ */

#include "Rider_Controls_Control_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

extern void enable_interrupts(void);

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T m_bpIndex;                  /* '<Root>/RPM to Max Motor Current' */
} D_Work_Rider_Controls_Control;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: RPM_Max_Current_y
   * Referenced by: '<Root>/RPM to Max Motor Current'
   */
  real32_T RPMtoMaxMotorCurrent_[4];

  /* Expression: RPM_Max_Current_x
   * Referenced by: '<Root>/RPM to Max Motor Current'
   */
  real32_T RPMtoMaxMotorCurren_o[4];
} ConstParam_Rider_Controls_Contr;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T Throttle;                   /* '<Root>/Throttle %' */
  real32_T RPM;                        /* '<Root>/RPM' */
} ExternalInputs_Rider_Controls_C;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T MotorCurrent;               /* '<Root>/Motor Current %' */
  real32_T Lookup;                     /* '<Root>/Lookup' */
} ExternalOutputs_Rider_Controls_;

/* Real-time Model Data Structure */
struct tag_RTM_Rider_Controls_Control {
  const char_T *errorStatus;
};

/* Block states (auto storage) */
extern D_Work_Rider_Controls_Control Rider_Controls_Control_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_Rider_Controls_C Rider_Controls_Control_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Rider_Controls_ Rider_Controls_Control_Y;

/* Constant parameters (auto storage) */
extern const ConstParam_Rider_Controls_Contr Rider_Controls_Control_ConstP;

/* Model entry point functions */
extern void Rider_Controls_Control_initialize(void);
extern void Rider_Controls_Control_step(void);
extern void Rider_Controls_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rider_Controls_Control *const Rider_Controls_Control_M;

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
 * '<S1>'   : 'Rider_Controls_Control/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_Rider_Controls_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
