/*
 * File: c280xx_asyncscheduling.h
 *
 * Code generated for Simulink model 'c280xx_asyncscheduling'.
 *
 * Model version                  : 1.213
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Fri Jun 05 22:34:06 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_c280xx_asyncscheduling_h_
#define RTW_HEADER_c280xx_asyncscheduling_h_
#include <stddef.h>
#include <string.h>
#ifndef c280xx_asyncscheduling_COMMON_INCLUDES_
# define c280xx_asyncscheduling_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "can_message.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* c280xx_asyncscheduling_COMMON_INCLUDES_ */

#include "c280xx_asyncscheduling_types.h"
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
extern void init_eCAN_A ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam);
extern void config_ePWM_GPIO (void);

/* user code (top of export header file) */
#include "can_message.h"
#include "can_message.h"

/* Block signals (auto storage) */
typedef struct {
  uint16_T eCANReceive_o2[4];          /* '<S3>/eCAN Receive' */
  uint16_T Output;                     /* '<S13>/Output' */
} BlockIO_c280xx_asyncscheduling;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint16_T Output_DSTATE;              /* '<S13>/Output' */
  uint16_T Output_DSTATE_a;            /* '<S7>/Output' */
  uint16_T Output_DSTATE_p;            /* '<S10>/Output' */
  int16_T RateTransition_ActiveBufIdx; /* '<Root>/Rate Transition' */
  int16_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  uint16_T RateTransition_Buffer[2];   /* '<Root>/Rate Transition' */
  uint16_T RateTransition1_Buffer[2];  /* '<Root>/Rate Transition1' */
} D_Work_c280xx_asyncscheduling;

/* Real-time Model Data Structure */
struct tag_RTM_c280xx_asyncscheduling {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_c280xx_asyncscheduling c280xx_asyncscheduling_B;

/* Block states (auto storage) */
extern D_Work_c280xx_asyncscheduling c280xx_asyncscheduling_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint16_T sig3;                  /* '<Root>/Add' */
extern uint16_T sig1;                  /* '<S7>/Output' */
extern uint16_T sig2;                  /* '<S10>/Output' */

/* Model entry point functions */
extern void c280xx_asyncscheduling_initialize(void);
extern void c280xx_asyncscheduling_step(void);
extern void c280xx_asyncscheduling_terminate(void);

/* Real-time Model object */
extern RT_MODEL_c280xx_asyncscheduling *const c280xx_asyncscheduling_M;

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
 * '<Root>' : 'c280xx_asyncscheduling'
 * '<S1>'   : 'c280xx_asyncscheduling/Function-Call Subsystem'
 * '<S2>'   : 'c280xx_asyncscheduling/Function-Call Subsystem1'
 * '<S3>'   : 'c280xx_asyncscheduling/Function-Call Subsystem2'
 * '<S4>'   : 'c280xx_asyncscheduling/PWM Duty Cycle Control Signal'
 * '<S5>'   : 'c280xx_asyncscheduling/Timer3'
 * '<S6>'   : 'c280xx_asyncscheduling/Timer4'
 * '<S7>'   : 'c280xx_asyncscheduling/Function-Call Subsystem/Counter Free-Running'
 * '<S8>'   : 'c280xx_asyncscheduling/Function-Call Subsystem/Counter Free-Running/Increment Real World'
 * '<S9>'   : 'c280xx_asyncscheduling/Function-Call Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S10>'  : 'c280xx_asyncscheduling/Function-Call Subsystem1/Counter Free-Running'
 * '<S11>'  : 'c280xx_asyncscheduling/Function-Call Subsystem1/Counter Free-Running/Increment Real World'
 * '<S12>'  : 'c280xx_asyncscheduling/Function-Call Subsystem1/Counter Free-Running/Wrap To Zero'
 * '<S13>'  : 'c280xx_asyncscheduling/PWM Duty Cycle Control Signal/Counter Limited'
 * '<S14>'  : 'c280xx_asyncscheduling/PWM Duty Cycle Control Signal/Counter Limited/Increment Real World'
 * '<S15>'  : 'c280xx_asyncscheduling/PWM Duty Cycle Control Signal/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_c280xx_asyncscheduling_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
