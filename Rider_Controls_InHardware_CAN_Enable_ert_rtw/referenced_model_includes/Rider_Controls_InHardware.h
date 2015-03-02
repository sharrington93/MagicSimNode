/*
 * File: Rider_Controls_InHardware.h
 *
 * Code generated for Simulink model 'Rider_Controls_InHardware'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Feb 10 16:42:43 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_InHardware_h_
#define RTW_HEADER_Rider_Controls_InHardware_h_
#include <string.h>
#ifndef Rider_Controls_InHardware_COMMON_INCLUDES_
# define Rider_Controls_InHardware_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include "can_message.h"
#endif                                 /* Rider_Controls_InHardware_COMMON_INCLUDES_ */

#include "Rider_Controls_InHardware_types.h"

/* Shared type includes */
#include "model_reference_types.h"

extern void enable_interrupts(void);
extern void init_eCAN_A ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam);

/* user code (top of export header file) */
#include "can_message.h"
#include "can_message.h"

/* Block signals for model 'Rider_Controls_InHardware' */
#ifndef Rider_Controls_InHardware_MDLREF_HIDE_CHILD_

typedef struct {
  CAN_DATATYPE eCANReceive_o2;         /* '<Root>/eCAN Receive' */
  real_T CANUnpack_o2;                 /* '<Root>/CAN Unpack' */
} rtB_Rider_Controls_InHardware;

#endif                                 /*Rider_Controls_InHardware_MDLREF_HIDE_CHILD_*/

/* Block states (auto storage) for model 'Rider_Controls_InHardware' */
#ifndef Rider_Controls_InHardware_MDLREF_HIDE_CHILD_

typedef struct {
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
} rtDW_Rider_Controls_InHardware;

#endif                                 /*Rider_Controls_InHardware_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_InHardware_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_Rider_Controls_InHardwa {
  const char_T **errorStatus;
};

#endif                                 /*Rider_Controls_InHardware_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_InHardware_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_Rider_Controls_InHardw rtm;
} rtMdlrefDWork_Rider_Controls_In;

#endif                                 /*Rider_Controls_InHardware_MDLREF_HIDE_CHILD_*/

extern void Rider_Controls_InHardware_Start(void);
extern void Rider_Controls_InHardware(real32_T *rty_Throttle, real32_T *rty_RPM);

/* Model reference registration function */
extern void Rider_Controls_InHar_initialize(const char_T **rt_errorStatus);

#ifndef Rider_Controls_InHardware_MDLREF_HIDE_CHILD_

extern rtMdlrefDWork_Rider_Controls_In Rider_Controls_InHa_MdlrefDWork;

#endif                                 /*Rider_Controls_InHardware_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_InHardware_MDLREF_HIDE_CHILD_

/* Block signals (auto storage) */
extern rtB_Rider_Controls_InHardware Rider_Controls_InHardware_B;

/* Block states (auto storage) */
extern rtDW_Rider_Controls_InHardware Rider_Controls_InHardware_DWork;

#endif                                 /*Rider_Controls_InHardware_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Rider_Controls_InHardware'
 * '<S1>'   : 'Rider_Controls_InHardware/Filter1'
 */
#endif                                 /* RTW_HEADER_Rider_Controls_InHardware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
