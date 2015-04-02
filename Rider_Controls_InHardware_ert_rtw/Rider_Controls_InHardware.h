/*
 * File: Rider_Controls_InHardware.h
 *
 * Code generated for Simulink model 'Rider_Controls_InHardware'.
 *
 * Model version                  : 1.125
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Mar 31 20:24:26 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rider_Controls_InHardware_h_
#define RTW_HEADER_Rider_Controls_InHardware_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Rider_Controls_InHardware_COMMON_INCLUDES_
# define Rider_Controls_InHardware_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include "can_message.h"
#include "DSP2803x_Gpio.h"
#endif                                 /* Rider_Controls_InHardware_COMMON_INCLUDES_ */

#include "Rider_Controls_InHardware_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

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
  CAN_DATATYPE eCANReceive2_o2;        /* '<Root>/eCAN Receive2' */
  CAN_DATATYPE eCANReceive3_o2;        /* '<Root>/eCAN Receive3' */
  CAN_DATATYPE eCANReceive4_o2;        /* '<Root>/eCAN Receive4' */
  CAN_DATATYPE eCANReceive5_o2;        /* '<Root>/eCAN Receive5' */
  CAN_DATATYPE eCANReceive6_o2;        /* '<Root>/eCAN Receive6' */
  CAN_DATATYPE eCANReceive7_o2;        /* '<Root>/eCAN Receive7' */
  CAN_DATATYPE eCANReceive8_o2;        /* '<Root>/eCAN Receive8' */
  CAN_DATATYPE eCANReceive9_o2;        /* '<Root>/eCAN Receive9' */
  CAN_DATATYPE eCANReceive10_o2;       /* '<Root>/eCAN Receive10' */
  CAN_DATATYPE eCANReceive11_o2;       /* '<Root>/eCAN Receive11' */
  CAN_DATATYPE eCANReceive12_o2;       /* '<Root>/eCAN Receive12' */
  CAN_DATATYPE eCANReceive13_o2;       /* '<Root>/eCAN Receive13' */
  CAN_DATATYPE eCANReceive14_o2;       /* '<Root>/eCAN Receive14' */
  CAN_DATATYPE eCANReceive15_o2;       /* '<Root>/eCAN Receive15' */
  boolean_T RelationalOperator[15];    /* '<Root>/Relational Operator' */
  real_T CANUnpack_o2;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o3;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack1_o1;                /* '<Root>/CAN Unpack1' */
  real_T CANUnpack1_o2;                /* '<Root>/CAN Unpack1' */
  real_T CANUnpack1_o3;                /* '<Root>/CAN Unpack1' */
  real_T CANUnpack1_o4;                /* '<Root>/CAN Unpack1' */
  real_T CANUnpack1_o5;                /* '<Root>/CAN Unpack1' */
  real_T CANUnpack2_o1;                /* '<Root>/CAN Unpack2' */
  real_T CANUnpack2_o2;                /* '<Root>/CAN Unpack2' */
  real_T CANUnpack2_o3;                /* '<Root>/CAN Unpack2' */
  real_T CANUnpack2_o4;                /* '<Root>/CAN Unpack2' */
  real_T CANUnpack2_o5;                /* '<Root>/CAN Unpack2' */
  real_T CANUnpack3_o1;                /* '<Root>/CAN Unpack3' */
  real_T CANUnpack3_o2;                /* '<Root>/CAN Unpack3' */
  real_T CANUnpack3_o3;                /* '<Root>/CAN Unpack3' */
  real_T CANUnpack3_o4;                /* '<Root>/CAN Unpack3' */
  real_T CANUnpack3_o5;                /* '<Root>/CAN Unpack3' */
  real_T CANUnpack4_o1;                /* '<Root>/CAN Unpack4' */
  real_T CANUnpack4_o2;                /* '<Root>/CAN Unpack4' */
  real_T CANUnpack4_o3;                /* '<Root>/CAN Unpack4' */
  real_T CANUnpack4_o4;                /* '<Root>/CAN Unpack4' */
  real_T CANUnpack4_o5;                /* '<Root>/CAN Unpack4' */
  real_T CANUnpack5_o1;                /* '<Root>/CAN Unpack5' */
  real_T CANUnpack5_o2;                /* '<Root>/CAN Unpack5' */
  real_T CANUnpack5_o3;                /* '<Root>/CAN Unpack5' */
  real_T CANUnpack5_o4;                /* '<Root>/CAN Unpack5' */
  real_T CANUnpack5_o5;                /* '<Root>/CAN Unpack5' */
  real_T CANUnpack6_o1;                /* '<Root>/CAN Unpack6' */
  real_T CANUnpack6_o2;                /* '<Root>/CAN Unpack6' */
  real_T CANUnpack6_o3;                /* '<Root>/CAN Unpack6' */
  real_T CANUnpack6_o4;                /* '<Root>/CAN Unpack6' */
  real_T CANUnpack6_o5;                /* '<Root>/CAN Unpack6' */
  real_T CANUnpack7_o1;                /* '<Root>/CAN Unpack7' */
  real_T CANUnpack7_o2;                /* '<Root>/CAN Unpack7' */
  real_T CANUnpack7_o3;                /* '<Root>/CAN Unpack7' */
  real_T CANUnpack7_o4;                /* '<Root>/CAN Unpack7' */
  real_T CANUnpack7_o5;                /* '<Root>/CAN Unpack7' */
  real_T CANUnpack8_o1;                /* '<Root>/CAN Unpack8' */
  real_T CANUnpack8_o2;                /* '<Root>/CAN Unpack8' */
  real_T CANUnpack8_o3;                /* '<Root>/CAN Unpack8' */
  real_T CANUnpack8_o4;                /* '<Root>/CAN Unpack8' */
  real_T CANUnpack8_o5;                /* '<Root>/CAN Unpack8' */
  real_T CANUnpack9_o1;                /* '<Root>/CAN Unpack9' */
  real_T CANUnpack9_o2;                /* '<Root>/CAN Unpack9' */
  real_T CANUnpack9_o3;                /* '<Root>/CAN Unpack9' */
  real_T CANUnpack9_o4;                /* '<Root>/CAN Unpack9' */
  real_T CANUnpack9_o5;                /* '<Root>/CAN Unpack9' */
  real_T CANUnpack10_o1;               /* '<Root>/CAN Unpack10' */
  real_T CANUnpack10_o2;               /* '<Root>/CAN Unpack10' */
  real_T CANUnpack10_o3;               /* '<Root>/CAN Unpack10' */
  real_T CANUnpack10_o4;               /* '<Root>/CAN Unpack10' */
  real_T CANUnpack10_o5;               /* '<Root>/CAN Unpack10' */
  real_T CANUnpack11_o1;               /* '<Root>/CAN Unpack11' */
  real_T CANUnpack11_o2;               /* '<Root>/CAN Unpack11' */
  real_T CANUnpack11_o3;               /* '<Root>/CAN Unpack11' */
  real_T CANUnpack11_o4;               /* '<Root>/CAN Unpack11' */
  real_T CANUnpack12_o1;               /* '<Root>/CAN Unpack12' */
  real_T CANUnpack12_o2;               /* '<Root>/CAN Unpack12' */
  real_T CANUnpack12_o3;               /* '<Root>/CAN Unpack12' */
  real_T CANUnpack12_o4;               /* '<Root>/CAN Unpack12' */
  real_T CANUnpack13_o1;               /* '<Root>/CAN Unpack13' */
  real_T CANUnpack13_o2;               /* '<Root>/CAN Unpack13' */
  real_T CANUnpack13_o3;               /* '<Root>/CAN Unpack13' */
  real_T CANUnpack13_o4;               /* '<Root>/CAN Unpack13' */
  real_T CANUnpack14_o1;               /* '<Root>/CAN Unpack14' */
  real_T CANUnpack14_o2;               /* '<Root>/CAN Unpack14' */
  real_T CANUnpack14_o3;               /* '<Root>/CAN Unpack14' */
  real_T CANUnpack14_o4;               /* '<Root>/CAN Unpack14' */
  real_T CANUnpack15_o1;               /* '<Root>/CAN Unpack15' */
  real_T CANUnpack15_o2;               /* '<Root>/CAN Unpack15' */
  real_T CANUnpack15_o3;               /* '<Root>/CAN Unpack15' */
  real_T CANUnpack15_o4;               /* '<Root>/CAN Unpack15' */
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T d0;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T d7;
  real32_T ADC;                        /* '<Root>/ADC' */
  real32_T RateTransition;             /* '<S1>/Rate Transition' */
  real32_T DigitalInput;               /* '<Root>/Digital Input' */
  real32_T RateTransition_l;           /* '<S2>/Rate Transition' */
} BlockIO_Rider_Controls_InHardwa;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S1>/Delay' */
  real32_T Delay_DSTATE_f;             /* '<S2>/Delay' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<Root>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<Root>/CAN Unpack1' */
  int_T CANUnpack2_ModeSignalID;       /* '<Root>/CAN Unpack2' */
  int_T CANUnpack2_StatusPortID;       /* '<Root>/CAN Unpack2' */
  int_T CANUnpack3_ModeSignalID;       /* '<Root>/CAN Unpack3' */
  int_T CANUnpack3_StatusPortID;       /* '<Root>/CAN Unpack3' */
  int_T CANUnpack4_ModeSignalID;       /* '<Root>/CAN Unpack4' */
  int_T CANUnpack4_StatusPortID;       /* '<Root>/CAN Unpack4' */
  int_T CANUnpack5_ModeSignalID;       /* '<Root>/CAN Unpack5' */
  int_T CANUnpack5_StatusPortID;       /* '<Root>/CAN Unpack5' */
  int_T CANUnpack6_ModeSignalID;       /* '<Root>/CAN Unpack6' */
  int_T CANUnpack6_StatusPortID;       /* '<Root>/CAN Unpack6' */
  int_T CANUnpack7_ModeSignalID;       /* '<Root>/CAN Unpack7' */
  int_T CANUnpack7_StatusPortID;       /* '<Root>/CAN Unpack7' */
  int_T CANUnpack8_ModeSignalID;       /* '<Root>/CAN Unpack8' */
  int_T CANUnpack8_StatusPortID;       /* '<Root>/CAN Unpack8' */
  int_T CANUnpack9_ModeSignalID;       /* '<Root>/CAN Unpack9' */
  int_T CANUnpack9_StatusPortID;       /* '<Root>/CAN Unpack9' */
  int_T CANUnpack10_ModeSignalID;      /* '<Root>/CAN Unpack10' */
  int_T CANUnpack10_StatusPortID;      /* '<Root>/CAN Unpack10' */
  int_T CANUnpack11_ModeSignalID;      /* '<Root>/CAN Unpack11' */
  int_T CANUnpack11_StatusPortID;      /* '<Root>/CAN Unpack11' */
  int_T CANUnpack12_ModeSignalID;      /* '<Root>/CAN Unpack12' */
  int_T CANUnpack12_StatusPortID;      /* '<Root>/CAN Unpack12' */
  int_T CANUnpack13_ModeSignalID;      /* '<Root>/CAN Unpack13' */
  int_T CANUnpack13_StatusPortID;      /* '<Root>/CAN Unpack13' */
  int_T CANUnpack14_ModeSignalID;      /* '<Root>/CAN Unpack14' */
  int_T CANUnpack14_StatusPortID;      /* '<Root>/CAN Unpack14' */
  int_T CANUnpack15_ModeSignalID;      /* '<Root>/CAN Unpack15' */
  int_T CANUnpack15_StatusPortID;      /* '<Root>/CAN Unpack15' */
} D_Work_Rider_Controls_InHardwar;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T Throttle;                   /* '<Root>/Throttle %' */
  real32_T RPM;                        /* '<Root>/RPM' */
  real32_T Temperatures[40];           /* '<Root>/Temperatures' */
  boolean_T EStop;                     /* '<Root>/E-Stop' */
  uint16_T BIMStatus;                  /* '<Root>/BIM Status' */
} ExternalOutputs_Rider_Controls_;

/* Real-time Model Data Structure */
struct tag_RTM_Rider_Controls_InHardwa {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_2;
      boolean_T TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block signals (auto storage) */
extern BlockIO_Rider_Controls_InHardwa Rider_Controls_InHardware_B;

/* Block states (auto storage) */
extern D_Work_Rider_Controls_InHardwar Rider_Controls_InHardware_DWork;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Rider_Controls_ Rider_Controls_InHardware_Y;

/* External function called from main */
extern void Rider_Controls_InHardware_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Rider_Controls_InHardware_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void Rider_Controls_InHardware_initialize(void);
extern void Rider_Controls_InHardware_step(int_T tid);
extern void Rider_Controls_InHardware_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rider_Controls_InHardw *const Rider_Controls_InHardware_M;

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
 * '<S2>'   : 'Rider_Controls_InHardware/Filter2'
 */
#endif                                 /* RTW_HEADER_Rider_Controls_InHardware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
