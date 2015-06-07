/*
 * File: Rider_Controls_Control_private.h
 *
 * Code generated for Simulink model 'Rider_Controls_Control'.
 *
 * Model version                  : 1.171
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Sat Jun 06 12:18:17 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_Control_private_h_
#define RTW_HEADER_Rider_Controls_Control_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"

/* Macros for accessing real-time model data structure */
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

extern const real32_T rtCP_pooled_kXF479Tr1zzv[5];
extern const real32_T rtCP_pooled_B0qELKmN8GAt[5];
extern const real32_T rtCP_pooled_oaa0NRPWZaqa[2];
extern const real32_T rtCP_pooled_RarCRswdQecv[2];

#define rtCP_BatteryTemptoCurrent_     rtCP_pooled_kXF479Tr1zzv  /* Expression: BattTemp_Current_y
                                                                  * Referenced by: '<S1>/Battery Temp to Current'
                                                                  */
#define rtCP_BatteryTemptoCurren_o     rtCP_pooled_B0qELKmN8GAt  /* Expression: BattTemp_Current_x
                                                                  * Referenced by: '<S1>/Battery Temp to Current'
                                                                  */
#define rtCP_RPMtoMaxMotorCurrent_     rtCP_pooled_oaa0NRPWZaqa  /* Expression: RPM_Max_Current_y
                                                                  * Referenced by: '<S2>/RPM to Max Motor Current'
                                                                  */
#define rtCP_RPMtoMaxMotorCurren_o     rtCP_pooled_RarCRswdQecv  /* Expression: RPM_Max_Current_x
                                                                  * Referenced by: '<S2>/RPM to Max Motor Current'
                                                                  */
#endif                                 /* RTW_HEADER_Rider_Controls_Control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
