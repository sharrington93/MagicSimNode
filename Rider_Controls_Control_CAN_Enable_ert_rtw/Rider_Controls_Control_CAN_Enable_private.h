/*
 * File: Rider_Controls_Control_CAN_Enable_private.h
 *
 * Code generated for Simulink model 'Rider_Controls_Control_CAN_Enable'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Mar 31 22:02:55 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_Control_CAN_Enable_private_h_
#define RTW_HEADER_Rider_Controls_Control_CAN_Enable_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "can_message.h"
#include "can_message.h"

void config_eCAN_A_mbx (uint16_T mbxType, uint16_T mbxNo, uint32_T msgID,
  uint16_T msgType);
extern const real32_T rtCP_pooled_7gWwqL6AKzQN[40];

#define rtCP_Constant_Value            rtCP_pooled_7gWwqL6AKzQN  /* Computed Parameter: Constant_Value
                                                                  * Referenced by: '<Root>/Constant'
                                                                  */

extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern rtTimingBridge Rider_Controls_C_TimingBridge_k;
extern void Rider_Controls_Control_CAN_Enable_step0(void);
extern void Rider_Controls_Control_CAN_Enable_step1(void);

#endif                                 /* RTW_HEADER_Rider_Controls_Control_CAN_Enable_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
