/*
 * File: Rider_Controls_OutHardware.h
 *
 * Code generated for Simulink model 'Rider_Controls_OutHardware'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Wed Apr 01 18:49:14 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_OutHardware_h_
#define RTW_HEADER_Rider_Controls_OutHardware_h_
#include <string.h>
#ifndef Rider_Controls_OutHardware_COMMON_INCLUDES_
# define Rider_Controls_OutHardware_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "can_message.h"
#include "DSP2803x_Device.h"
#endif                                 /* Rider_Controls_OutHardware_COMMON_INCLUDES_ */

#include "Rider_Controls_OutHardware_types.h"

/* Shared type includes */
#include "model_reference_types.h"

extern void enable_interrupts(void);
extern void init_eCAN_A ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam);

/* user code (top of export header file) */
#include "can_message.h"
#include "can_message.h"

/* Block signals for model 'Rider_Controls_OutHardware' */
#ifndef Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_

typedef struct {
  CAN_DATATYPE CANPack1;               /* '<Root>/CAN Pack1' */
  CAN_DATATYPE CANPack;                /* '<Root>/CAN Pack' */
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<Root>/Data Type Conversion2' */
  real_T DataTypeConversion3;          /* '<Root>/Data Type Conversion3' */
} rtB_Rider_Controls_OutHardware;

#endif                                 /*Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_*/

/* Block states (auto storage) for model 'Rider_Controls_OutHardware' */
#ifndef Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_

typedef struct {
  int_T CANPack1_ModeSignalID;         /* '<Root>/CAN Pack1' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
} rtDW_Rider_Controls_OutHardware;

#endif                                 /*Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_Rider_Controls_OutHardw {
  const char_T **errorStatus;
};

#endif                                 /*Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_Rider_Controls_OutHard rtm;
} rtMdlrefDWork_Rider_Controls_Ou;

#endif                                 /*Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_*/

extern void Rider_Controls_OutHardwar_Start(void);
extern void Rider_Controls_OutHardware(const real32_T *rtu_MotorCurrent, const
  uint16_T *rtu_RPMLimit, const uint16_T *rtu_BatteryLimit, const uint16_T
  *rtu_ThrottleLock, const uint16_T *rtu_StatusLimit);

/* Model reference registration function */
extern void Rider_Controls_OutHa_initialize(const char_T **rt_errorStatus);

#ifndef Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_

extern rtMdlrefDWork_Rider_Controls_Ou Rider_Controls_OutH_MdlrefDWork;

#endif                                 /*Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_*/

#ifndef Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_

/* Block signals (auto storage) */
extern rtB_Rider_Controls_OutHardware Rider_Controls_OutHardware_B;

/* Block states (auto storage) */
extern rtDW_Rider_Controls_OutHardware Rider_Controls_OutHardwar_DWork;

#endif                                 /*Rider_Controls_OutHardware_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Rider_Controls_OutHardware'
 */
#endif                                 /* RTW_HEADER_Rider_Controls_OutHardware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
