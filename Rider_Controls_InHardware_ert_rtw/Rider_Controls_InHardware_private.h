/*
 * File: Rider_Controls_InHardware_private.h
 *
 * Code generated for Simulink model 'Rider_Controls_InHardware'.
 *
 * Model version                  : 1.316
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Thu Jun 18 12:58:10 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_InHardware_private_h_
#define RTW_HEADER_Rider_Controls_InHardware_private_h_
#include "rtwtypes.h"
#include "can_message.h"

void config_eCAN_A_mbx (uint16_T mbxType, uint16_T mbxNo, uint32_T msgID,
  uint16_T msgType);
void InitAdc (void);
void config_ADC_SOC0 (void);
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern void Rider_MessageReceived4_Init(rtDW_MessageReceived4_Rider_Con *localDW);
extern void Ri_MessageReceived4_Disable(rtB_MessageReceived4_Rider_Cont *localB);
extern void Rider_Cont_MessageReceived4(rtB_MessageReceived4_Rider_Cont *localB,
  rtDW_MessageReceived4_Rider_Con *localDW);
extern void Rider_Controls_InHardware_step0(void);
extern void Rider_Controls_InHardware_step1(void);
extern void Rider_Controls_InHardware_step2(void);

#endif                                 /* RTW_HEADER_Rider_Controls_InHardware_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
