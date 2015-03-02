/*
 * File: Rider_Controls_InHardware_CAN_Enable_private.h
 *
 * Code generated for Simulink model 'Rider_Controls_InHardware_CAN_Enable'.
 *
 * Model version                  : 1.98
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Feb 10 16:43:01 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_InHardware_CAN_Enable_private_h_
#define RTW_HEADER_Rider_Controls_InHardware_CAN_Enable_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "can_message.h"

void config_eCAN_A_mbx (uint16_T mbxType, uint16_T mbxNo, uint32_T msgID,
  uint16_T msgType);
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;

#endif                                 /* RTW_HEADER_Rider_Controls_InHardware_CAN_Enable_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
