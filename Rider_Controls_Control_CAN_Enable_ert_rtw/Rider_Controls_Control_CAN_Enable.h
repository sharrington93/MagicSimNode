/*
 * File: Rider_Controls_Control_CAN_Enable.h
 *
 * Code generated for Simulink model 'Rider_Controls_Control_CAN_Enable'.
 *
 * Model version                  : 1.103
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Sun Mar 01 11:59:39 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_Control_CAN_Enable_h_
#define RTW_HEADER_Rider_Controls_Control_CAN_Enable_h_
#include <stddef.h>
#include <string.h>
#ifndef Rider_Controls_Control_CAN_Enable_COMMON_INCLUDES_
# define Rider_Controls_Control_CAN_Enable_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "can_message.h"
#include "DSP2803x_Device.h"
#endif                                 /* Rider_Controls_Control_CAN_Enable_COMMON_INCLUDES_ */

#include "Rider_Controls_Control_CAN_Enable_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Child system includes */
#define Rider_Controls_Control_MDLREF_HIDE_CHILD_
#include "Rider_Controls_Control.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#define Rider_Controls_Control_CAN_Enable_M (Rider_Controls_Control_CAN_E_M)

extern void enable_interrupts(void);
extern void init_eCAN_A ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam);

/* user code (top of export header file) */
#include "can_message.h"
#include "can_message.h"

/* Block signals (auto storage) */
typedef struct {
  CAN_DATATYPE eCANReceive_o2;         /* '<Root>/eCAN Receive' */
  CAN_DATATYPE eCANReceive1_o2;        /* '<Root>/eCAN Receive1' */
  CAN_DATATYPE CANPack;                /* '<Root>/CAN Pack' */
  CAN_DATATYPE CANPack1;               /* '<Root>/CAN Pack1' */
  real32_T CANUnpack_o1;               /* '<Root>/CAN Unpack' */
  real32_T CANUnpack_o2;               /* '<Root>/CAN Unpack' */
  real32_T CANUnpack1;                 /* '<Root>/CAN Unpack1' */
  real32_T Software_o1;                /* '<Root>/Software' */
  real32_T Software_o2;                /* '<Root>/Software' */
  real32_T Software_o3;                /* '<Root>/Software' */
} BlockIO_Rider_Controls_Control_;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<Root>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<Root>/CAN Unpack1' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  int_T CANPack1_ModeSignalID;         /* '<Root>/CAN Pack1' */
} D_Work_Rider_Controls_Control_C;

/* Real-time Model Data Structure */
struct tag_RTM_Rider_Controls_Control_ {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_Rider_Controls_Control_ Rider_Controls_Control_CAN_En_B;

/* Block states (auto storage) */
extern D_Work_Rider_Controls_Control_C Rider_Controls_Control_CA_DWork;

/* Model entry point functions */
extern void Rider_Controls_Control_CAN_Enable_initialize(void);
extern void Rider_Controls_Control_CAN_Enable_step(void);
extern void Rider_Controls_Control_CAN_Enable_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rider_Controls_Contr_d *const Rider_Controls_Control_CAN_E_M;

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
 * '<Root>' : 'Rider_Controls_Control_CAN_Enable'
 */
#endif                                 /* RTW_HEADER_Rider_Controls_Control_CAN_Enable_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
