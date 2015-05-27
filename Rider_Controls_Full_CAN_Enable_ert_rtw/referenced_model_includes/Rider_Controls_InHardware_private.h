/*
 * File: Rider_Controls_InHardware_private.h
 *
 * Code generated for Simulink model 'Rider_Controls_InHardware'.
 *
 * Model version                  : 1.310
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Wed May 27 15:53:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_InHardware_private_h_
#define RTW_HEADER_Rider_Controls_InHardware_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "can_message.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsSampleHit
# define rtmIsSampleHit(sti, tid)      (Rider_Controls_InH_TimingBridge->taskCounter[Rider_Controls_InHard_GlobalTID[sti]] == 0)
#endif

#ifndef rtmIsSpecialSampleHit
# define rtmIsSpecialSampleHit(sti, prom_sti, tid) ( *((Rider_Controls_InH_TimingBridge->rateTransition)[Rider_Controls_InHard_GlobalTID[sti] + Rider_Controls_InH_TimingBridge->nTasks*Rider_Controls_InHard_GlobalTID[prom_sti]]) )
#endif

void config_eCAN_A_mbx (uint16_T mbxType, uint16_T mbxNo, uint32_T msgID,
  uint16_T msgType);
void InitAdc (void);
void config_ADC_SOC0 (void);

/* Macros for accessing real-time model data structure */
#ifndef rtmGetClockTick0
# define rtmGetClockTick0()            ( *((Rider_Controls_InH_TimingBridge->clockTick[Rider_Controls_InHard_GlobalTID[0]])) )
#endif

#ifndef rtmGetClockTick1
# define rtmGetClockTick1()            ( *((Rider_Controls_InH_TimingBridge->clockTick[Rider_Controls_InHard_GlobalTID[1]])) )
#endif

#ifndef rtmGetClockTick2
# define rtmGetClockTick2()            ( *((Rider_Controls_InH_TimingBridge->clockTick[Rider_Controls_InHard_GlobalTID[2]])) )
#endif

#ifndef rtmGetClockTickH0
# define rtmGetClockTickH0()           ( *(Rider_Controls_InH_TimingBridge->clockTickH[Rider_Controls_InHard_GlobalTID[0]]) )
#endif

#ifndef rtmGetClockTickH1
# define rtmGetClockTickH1()           ( *(Rider_Controls_InH_TimingBridge->clockTickH[Rider_Controls_InHard_GlobalTID[1]]) )
#endif

#ifndef rtmGetClockTickH2
# define rtmGetClockTickH2()           ( *(Rider_Controls_InH_TimingBridge->clockTickH[Rider_Controls_InHard_GlobalTID[2]]) )
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT()                     (*(Rider_Controls_InH_TimingBridge->taskTime[0]))
#endif

extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern int_T Rider_Controls_InHard_GlobalTID[3];
extern const rtTimingBridge *Rider_Controls_InH_TimingBridge;

#endif                                 /* RTW_HEADER_Rider_Controls_InHardware_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
