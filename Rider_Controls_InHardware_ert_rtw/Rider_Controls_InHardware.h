/*
 * File: Rider_Controls_InHardware.h
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

#ifndef RTW_HEADER_Rider_Controls_InHardware_h_
#define RTW_HEADER_Rider_Controls_InHardware_h_
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

/* Block signals for system '<S1>/Message Received4' */
typedef struct {
  uint16_T Counter;                    /* '<S47>/Counter' */
} rtB_MessageReceived4_Rider_Cont;

/* Block states (auto storage) for system '<S1>/Message Received4' */
typedef struct {
  uint16_T Counter_Count;              /* '<S47>/Counter' */
} rtDW_MessageReceived4_Rider_Con;

/* Block signals (auto storage) */
typedef struct {
  real32_T Sum_d[36];                  /* '<S28>/Sum' */
  CAN_DATATYPE eCANReceive_o2;         /* '<Root>/eCAN Receive' */
  CAN_DATATYPE eCANReceive1_o2;        /* '<S1>/eCAN Receive1' */
  CAN_DATATYPE eCANReceive2_o2;        /* '<S1>/eCAN Receive2' */
  CAN_DATATYPE eCANReceive3_o2;        /* '<S1>/eCAN Receive3' */
  CAN_DATATYPE eCANReceive4_o2;        /* '<S1>/eCAN Receive4' */
  CAN_DATATYPE eCANReceive5_o2;        /* '<S1>/eCAN Receive5' */
  CAN_DATATYPE eCANReceive6_o2;        /* '<S1>/eCAN Receive6' */
  CAN_DATATYPE eCANReceive26_o2;       /* '<S1>/eCAN Receive26' */
  CAN_DATATYPE eCANReceive7_o2;        /* '<S1>/eCAN Receive7' */
  CAN_DATATYPE eCANReceive8_o2;        /* '<S1>/eCAN Receive8' */
  CAN_DATATYPE eCANReceive9_o2;        /* '<S1>/eCAN Receive9' */
  CAN_DATATYPE eCANReceive10_o2;       /* '<S1>/eCAN Receive10' */
  CAN_DATATYPE eCANReceive16_o2;       /* '<S1>/eCAN Receive16' */
  CAN_DATATYPE eCANReceive17_o2;       /* '<S1>/eCAN Receive17' */
  CAN_DATATYPE eCANReceive18_o2;       /* '<S1>/eCAN Receive18' */
  CAN_DATATYPE eCANReceive19_o2;       /* '<S1>/eCAN Receive19' */
  CAN_DATATYPE eCANReceive20_o2;       /* '<S1>/eCAN Receive20' */
  CAN_DATATYPE eCANReceive21_o2;       /* '<S1>/eCAN Receive21' */
  CAN_DATATYPE eCANReceive22_o2;       /* '<S1>/eCAN Receive22' */
  CAN_DATATYPE eCANReceive11_o2;       /* '<Root>/eCAN Receive11' */
  CAN_DATATYPE eCANReceive12_o2;       /* '<Root>/eCAN Receive12' */
  CAN_DATATYPE eCANReceive13_o2;       /* '<Root>/eCAN Receive13' */
  CAN_DATATYPE eCANReceive14_o2;       /* '<Root>/eCAN Receive14' */
  CAN_DATATYPE eCANReceive15_o2;       /* '<Root>/eCAN Receive15' */
  real_T CANUnpack_o2;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack1_o1;                /* '<S1>/CAN Unpack1' */
  real_T CANUnpack1_o2;                /* '<S1>/CAN Unpack1' */
  real_T CANUnpack2_o1;                /* '<S1>/CAN Unpack2' */
  real_T CANUnpack2_o2;                /* '<S1>/CAN Unpack2' */
  real_T CANUnpack3_o1;                /* '<S1>/CAN Unpack3' */
  real_T CANUnpack3_o2;                /* '<S1>/CAN Unpack3' */
  real_T CANUnpack4_o1;                /* '<S1>/CAN Unpack4' */
  real_T CANUnpack4_o2;                /* '<S1>/CAN Unpack4' */
  real_T CANUnpack5_o1;                /* '<S1>/CAN Unpack5' */
  real_T CANUnpack5_o2;                /* '<S1>/CAN Unpack5' */
  real_T CANUnpack6_o1;                /* '<S1>/CAN Unpack6' */
  real_T CANUnpack6_o2;                /* '<S1>/CAN Unpack6' */
  real_T CANUnpack7_o1;                /* '<S1>/CAN Unpack7' */
  real_T CANUnpack7_o2;                /* '<S1>/CAN Unpack7' */
  real_T CANUnpack8_o1;                /* '<S1>/CAN Unpack8' */
  real_T CANUnpack8_o2;                /* '<S1>/CAN Unpack8' */
  real_T CANUnpack9_o1;                /* '<S1>/CAN Unpack9' */
  real_T CANUnpack9_o2;                /* '<S1>/CAN Unpack9' */
  real_T CANUnpack10_o1;               /* '<S1>/CAN Unpack10' */
  real_T CANUnpack10_o2;               /* '<S1>/CAN Unpack10' */
  real_T CANUnpack16_o1;               /* '<S1>/CAN Unpack16' */
  real_T CANUnpack16_o2;               /* '<S1>/CAN Unpack16' */
  real_T CANUnpack17_o1;               /* '<S1>/CAN Unpack17' */
  real_T CANUnpack17_o2;               /* '<S1>/CAN Unpack17' */
  real_T CANUnpack18_o1;               /* '<S1>/CAN Unpack18' */
  real_T CANUnpack18_o2;               /* '<S1>/CAN Unpack18' */
  real_T CANUnpack19_o1;               /* '<S1>/CAN Unpack19' */
  real_T CANUnpack19_o2;               /* '<S1>/CAN Unpack19' */
  real_T CANUnpack20_o1;               /* '<S1>/CAN Unpack20' */
  real_T CANUnpack20_o2;               /* '<S1>/CAN Unpack20' */
  real_T CANUnpack21_o1;               /* '<S1>/CAN Unpack21' */
  real_T CANUnpack21_o2;               /* '<S1>/CAN Unpack21' */
  real_T CANUnpack22_o1;               /* '<S1>/CAN Unpack22' */
  real_T CANUnpack22_o2;               /* '<S1>/CAN Unpack22' */
  real_T CANUnpack23_o1;               /* '<S1>/CAN Unpack23' */
  real_T CANUnpack23_o2;               /* '<S1>/CAN Unpack23' */
  real_T CANUnpack11_o2;               /* '<Root>/CAN Unpack11' */
  real_T CANUnpack15_o2;               /* '<Root>/CAN Unpack15' */
  real32_T ADC;                        /* '<Root>/ADC' */
  real32_T RateTransition;             /* '<S26>/Rate Transition' */
  uint16_T RateTransition_n;           /* '<S2>/Rate Transition' */
  uint16_T RateTransition_c;           /* '<S3>/Rate Transition' */
  uint16_T RateTransition_a;           /* '<S4>/Rate Transition' */
  uint16_T RateTransition_o;           /* '<S5>/Rate Transition' */
  uint16_T RateTransition_at;          /* '<S6>/Rate Transition' */
  uint16_T RateTransition_h;           /* '<S7>/Rate Transition' */
  uint16_T RateTransition_m;           /* '<S8>/Rate Transition' */
  uint16_T RateTransition_d;           /* '<S9>/Rate Transition' */
  uint16_T RateTransition_ag;          /* '<S10>/Rate Transition' */
  uint16_T RateTransition_l;           /* '<S11>/Rate Transition' */
  uint16_T RateTransition_p;           /* '<S12>/Rate Transition' */
  uint16_T RateTransition_mc;          /* '<S13>/Rate Transition' */
  uint16_T RateTransition_ar;          /* '<S14>/Rate Transition' */
  uint16_T RateTransition_k;           /* '<S15>/Rate Transition' */
  uint16_T RateTransition_e;           /* '<S16>/Rate Transition' */
  uint16_T RateTransition_h4;          /* '<S17>/Rate Transition' */
  uint16_T RateTransition_b;           /* '<S18>/Rate Transition' */
  uint16_T RateTransition_f;           /* '<S19>/Rate Transition' */
  uint16_T RateTransition_a5;          /* '<S20>/Rate Transition' */
  uint16_T RateTransition_al;          /* '<S21>/Rate Transition' */
  uint16_T RateTransition_pj;          /* '<S22>/Rate Transition' */
  uint16_T RateTransition_nw;          /* '<S23>/Rate Transition' */
  uint16_T RateTransition_i;           /* '<S24>/Rate Transition' */
  uint16_T RateTransition_ov;          /* '<S25>/Rate Transition' */
  uint16_T CANUnpack11_o1[8];          /* '<Root>/CAN Unpack11' */
  uint16_T CANUnpack12[8];             /* '<Root>/CAN Unpack12' */
  uint16_T CANUnpack13[8];             /* '<Root>/CAN Unpack13' */
  uint16_T CANUnpack14[8];             /* '<Root>/CAN Unpack14' */
  uint16_T CANUnpack15_o1[8];          /* '<Root>/CAN Unpack15' */
  boolean_T RateTransition_lz;         /* '<Root>/Rate Transition' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
  rtB_MessageReceived4_Rider_Cont MessageReceived5_n;/* '<Root>/Message Received5' */
  rtB_MessageReceived4_Rider_Cont MessageReceived1_c;/* '<Root>/Message Received1' */
  rtB_MessageReceived4_Rider_Cont MessageReceived2_a;/* '<Root>/Message Received2' */
  rtB_MessageReceived4_Rider_Cont MessageReceived3_b;/* '<Root>/Message Received3' */
  rtB_MessageReceived4_Rider_Cont MessageReceived4_b;/* '<Root>/Message Received4' */
  rtB_MessageReceived4_Rider_Cont MessageReceived6;/* '<Root>/Message Received6' */
  rtB_MessageReceived4_Rider_Cont MessageReceived10;/* '<S1>/Message Received10' */
  rtB_MessageReceived4_Rider_Cont MessageReceived9;/* '<S1>/Message Received9' */
  rtB_MessageReceived4_Rider_Cont MessageReceived8;/* '<S1>/Message Received8' */
  rtB_MessageReceived4_Rider_Cont MessageReceived6_b;/* '<S1>/Message Received6' */
  rtB_MessageReceived4_Rider_Cont MessageReceived5;/* '<S1>/Message Received5' */
  rtB_MessageReceived4_Rider_Cont MessageReceived3;/* '<S1>/Message Received3' */
  rtB_MessageReceived4_Rider_Cont MessageReceived2;/* '<S1>/Message Received2' */
  rtB_MessageReceived4_Rider_Cont MessageReceived7;/* '<S1>/Message Received7' */
  rtB_MessageReceived4_Rider_Cont MessageReceived18;/* '<S1>/Message Received18' */
  rtB_MessageReceived4_Rider_Cont MessageReceived17;/* '<S1>/Message Received17' */
  rtB_MessageReceived4_Rider_Cont MessageReceived16;/* '<S1>/Message Received16' */
  rtB_MessageReceived4_Rider_Cont MessageReceived1;/* '<S1>/Message Received1' */
  rtB_MessageReceived4_Rider_Cont MessageReceived15;/* '<S1>/Message Received15' */
  rtB_MessageReceived4_Rider_Cont MessageReceived14;/* '<S1>/Message Received14' */
  rtB_MessageReceived4_Rider_Cont MessageReceived13;/* '<S1>/Message Received13' */
  rtB_MessageReceived4_Rider_Cont MessageReceived12;/* '<S1>/Message Received12' */
  rtB_MessageReceived4_Rider_Cont MessageReceived11;/* '<S1>/Message Received11' */
  rtB_MessageReceived4_Rider_Cont MessageReceived4;/* '<S1>/Message Received4' */
} BlockIO_Rider_Controls_InHardwa;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S26>/Delay' */
  real32_T Delay_DSTATE_o[36];         /* '<S28>/Delay' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<S1>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<S1>/CAN Unpack1' */
  int_T CANUnpack2_ModeSignalID;       /* '<S1>/CAN Unpack2' */
  int_T CANUnpack2_StatusPortID;       /* '<S1>/CAN Unpack2' */
  int_T CANUnpack3_ModeSignalID;       /* '<S1>/CAN Unpack3' */
  int_T CANUnpack3_StatusPortID;       /* '<S1>/CAN Unpack3' */
  int_T CANUnpack4_ModeSignalID;       /* '<S1>/CAN Unpack4' */
  int_T CANUnpack4_StatusPortID;       /* '<S1>/CAN Unpack4' */
  int_T CANUnpack5_ModeSignalID;       /* '<S1>/CAN Unpack5' */
  int_T CANUnpack5_StatusPortID;       /* '<S1>/CAN Unpack5' */
  int_T CANUnpack6_ModeSignalID;       /* '<S1>/CAN Unpack6' */
  int_T CANUnpack6_StatusPortID;       /* '<S1>/CAN Unpack6' */
  int_T CANUnpack7_ModeSignalID;       /* '<S1>/CAN Unpack7' */
  int_T CANUnpack7_StatusPortID;       /* '<S1>/CAN Unpack7' */
  int_T CANUnpack8_ModeSignalID;       /* '<S1>/CAN Unpack8' */
  int_T CANUnpack8_StatusPortID;       /* '<S1>/CAN Unpack8' */
  int_T CANUnpack9_ModeSignalID;       /* '<S1>/CAN Unpack9' */
  int_T CANUnpack9_StatusPortID;       /* '<S1>/CAN Unpack9' */
  int_T CANUnpack10_ModeSignalID;      /* '<S1>/CAN Unpack10' */
  int_T CANUnpack10_StatusPortID;      /* '<S1>/CAN Unpack10' */
  int_T CANUnpack16_ModeSignalID;      /* '<S1>/CAN Unpack16' */
  int_T CANUnpack16_StatusPortID;      /* '<S1>/CAN Unpack16' */
  int_T CANUnpack17_ModeSignalID;      /* '<S1>/CAN Unpack17' */
  int_T CANUnpack17_StatusPortID;      /* '<S1>/CAN Unpack17' */
  int_T CANUnpack18_ModeSignalID;      /* '<S1>/CAN Unpack18' */
  int_T CANUnpack18_StatusPortID;      /* '<S1>/CAN Unpack18' */
  int_T CANUnpack19_ModeSignalID;      /* '<S1>/CAN Unpack19' */
  int_T CANUnpack19_StatusPortID;      /* '<S1>/CAN Unpack19' */
  int_T CANUnpack20_ModeSignalID;      /* '<S1>/CAN Unpack20' */
  int_T CANUnpack20_StatusPortID;      /* '<S1>/CAN Unpack20' */
  int_T CANUnpack21_ModeSignalID;      /* '<S1>/CAN Unpack21' */
  int_T CANUnpack21_StatusPortID;      /* '<S1>/CAN Unpack21' */
  int_T CANUnpack22_ModeSignalID;      /* '<S1>/CAN Unpack22' */
  int_T CANUnpack22_StatusPortID;      /* '<S1>/CAN Unpack22' */
  int_T CANUnpack23_ModeSignalID;      /* '<S1>/CAN Unpack23' */
  int_T CANUnpack23_StatusPortID;      /* '<S1>/CAN Unpack23' */
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
  uint16_T DelayInput1_DSTATE;         /* '<S53>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_f;       /* '<S54>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_e;       /* '<S55>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_m;       /* '<S56>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_d;       /* '<S57>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_h;       /* '<S58>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_l;       /* '<S59>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_mj;      /* '<S60>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_c;       /* '<S61>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_b;       /* '<S62>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_p;       /* '<S63>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_dv;      /* '<S64>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_cs;      /* '<S65>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_k;       /* '<S66>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_g;       /* '<S67>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_c0;      /* '<S68>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_o;       /* '<S69>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_n;       /* '<S70>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_dt;      /* '<S71>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_dy;      /* '<S72>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_ey;      /* '<S73>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_c2;      /* '<S74>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_j;       /* '<S75>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_kj;      /* '<S76>/Delay Input1' */
  uint16_T Counter_Count;              /* '<S2>/Counter' */
  uint16_T Counter_Count_l;            /* '<S3>/Counter' */
  uint16_T Counter_Count_i;            /* '<S4>/Counter' */
  uint16_T Counter_Count_d;            /* '<S5>/Counter' */
  uint16_T Counter_Count_k;            /* '<S6>/Counter' */
  uint16_T Counter_Count_c;            /* '<S7>/Counter' */
  uint16_T Counter_Count_h;            /* '<S8>/Counter' */
  uint16_T Counter_Count_f;            /* '<S9>/Counter' */
  uint16_T Counter_Count_im;           /* '<S10>/Counter' */
  uint16_T Counter_Count_p;            /* '<S11>/Counter' */
  uint16_T Counter_Count_a;            /* '<S12>/Counter' */
  uint16_T Counter_Count_ls;           /* '<S13>/Counter' */
  uint16_T Counter_Count_ll;           /* '<S14>/Counter' */
  uint16_T Counter_Count_d0;           /* '<S15>/Counter' */
  uint16_T Counter_Count_hr;           /* '<S16>/Counter' */
  uint16_T Counter_Count_ix;           /* '<S17>/Counter' */
  uint16_T Counter_Count_ce;           /* '<S18>/Counter' */
  uint16_T Counter_Count_e;            /* '<S19>/Counter' */
  uint16_T Counter_Count_ha;           /* '<S20>/Counter' */
  uint16_T Counter_Count_g;            /* '<S21>/Counter' */
  uint16_T Counter_Count_h1;           /* '<S22>/Counter' */
  uint16_T Counter_Count_ks;           /* '<S23>/Counter' */
  uint16_T Counter_Count_ca;           /* '<S24>/Counter' */
  uint16_T Counter_Count_i1;           /* '<S25>/Counter' */
  boolean_T RateTransition_Buffer0;    /* '<Root>/Rate Transition' */
  rtDW_MessageReceived4_Rider_Con MessageReceived5_n;/* '<Root>/Message Received5' */
  rtDW_MessageReceived4_Rider_Con MessageReceived1_c;/* '<Root>/Message Received1' */
  rtDW_MessageReceived4_Rider_Con MessageReceived2_a;/* '<Root>/Message Received2' */
  rtDW_MessageReceived4_Rider_Con MessageReceived3_b;/* '<Root>/Message Received3' */
  rtDW_MessageReceived4_Rider_Con MessageReceived4_b;/* '<Root>/Message Received4' */
  rtDW_MessageReceived4_Rider_Con MessageReceived6;/* '<Root>/Message Received6' */
  rtDW_MessageReceived4_Rider_Con MessageReceived10;/* '<S1>/Message Received10' */
  rtDW_MessageReceived4_Rider_Con MessageReceived9;/* '<S1>/Message Received9' */
  rtDW_MessageReceived4_Rider_Con MessageReceived8;/* '<S1>/Message Received8' */
  rtDW_MessageReceived4_Rider_Con MessageReceived6_b;/* '<S1>/Message Received6' */
  rtDW_MessageReceived4_Rider_Con MessageReceived5;/* '<S1>/Message Received5' */
  rtDW_MessageReceived4_Rider_Con MessageReceived3;/* '<S1>/Message Received3' */
  rtDW_MessageReceived4_Rider_Con MessageReceived2;/* '<S1>/Message Received2' */
  rtDW_MessageReceived4_Rider_Con MessageReceived7;/* '<S1>/Message Received7' */
  rtDW_MessageReceived4_Rider_Con MessageReceived18;/* '<S1>/Message Received18' */
  rtDW_MessageReceived4_Rider_Con MessageReceived17;/* '<S1>/Message Received17' */
  rtDW_MessageReceived4_Rider_Con MessageReceived16;/* '<S1>/Message Received16' */
  rtDW_MessageReceived4_Rider_Con MessageReceived1;/* '<S1>/Message Received1' */
  rtDW_MessageReceived4_Rider_Con MessageReceived15;/* '<S1>/Message Received15' */
  rtDW_MessageReceived4_Rider_Con MessageReceived14;/* '<S1>/Message Received14' */
  rtDW_MessageReceived4_Rider_Con MessageReceived13;/* '<S1>/Message Received13' */
  rtDW_MessageReceived4_Rider_Con MessageReceived12;/* '<S1>/Message Received12' */
  rtDW_MessageReceived4_Rider_Con MessageReceived11;/* '<S1>/Message Received11' */
  rtDW_MessageReceived4_Rider_Con MessageReceived4;/* '<S1>/Message Received4' */
} D_Work_Rider_Controls_InHardwar;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T Throttle;                   /* '<Root>/Throttle %' */
  real32_T RPM;                        /* '<Root>/RPM' */
  real32_T Temperatures[36];           /* '<Root>/Temperatures' */
  uint16_T EStop;                      /* '<Root>/E-Stop' */
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
    struct {
      uint32_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
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
 * '<S1>'   : 'Rider_Controls_InHardware/CAN Battery Messages'
 * '<S2>'   : 'Rider_Controls_InHardware/Check CAN Time1'
 * '<S3>'   : 'Rider_Controls_InHardware/Check CAN Time10'
 * '<S4>'   : 'Rider_Controls_InHardware/Check CAN Time11'
 * '<S5>'   : 'Rider_Controls_InHardware/Check CAN Time12'
 * '<S6>'   : 'Rider_Controls_InHardware/Check CAN Time13'
 * '<S7>'   : 'Rider_Controls_InHardware/Check CAN Time14'
 * '<S8>'   : 'Rider_Controls_InHardware/Check CAN Time15'
 * '<S9>'   : 'Rider_Controls_InHardware/Check CAN Time16'
 * '<S10>'  : 'Rider_Controls_InHardware/Check CAN Time17'
 * '<S11>'  : 'Rider_Controls_InHardware/Check CAN Time18'
 * '<S12>'  : 'Rider_Controls_InHardware/Check CAN Time19'
 * '<S13>'  : 'Rider_Controls_InHardware/Check CAN Time2'
 * '<S14>'  : 'Rider_Controls_InHardware/Check CAN Time20'
 * '<S15>'  : 'Rider_Controls_InHardware/Check CAN Time21'
 * '<S16>'  : 'Rider_Controls_InHardware/Check CAN Time22'
 * '<S17>'  : 'Rider_Controls_InHardware/Check CAN Time23'
 * '<S18>'  : 'Rider_Controls_InHardware/Check CAN Time26'
 * '<S19>'  : 'Rider_Controls_InHardware/Check CAN Time3'
 * '<S20>'  : 'Rider_Controls_InHardware/Check CAN Time4'
 * '<S21>'  : 'Rider_Controls_InHardware/Check CAN Time5'
 * '<S22>'  : 'Rider_Controls_InHardware/Check CAN Time6'
 * '<S23>'  : 'Rider_Controls_InHardware/Check CAN Time7'
 * '<S24>'  : 'Rider_Controls_InHardware/Check CAN Time8'
 * '<S25>'  : 'Rider_Controls_InHardware/Check CAN Time9'
 * '<S26>'  : 'Rider_Controls_InHardware/Filter1'
 * '<S27>'  : 'Rider_Controls_InHardware/Filter2'
 * '<S28>'  : 'Rider_Controls_InHardware/Filter3'
 * '<S29>'  : 'Rider_Controls_InHardware/Message Received1'
 * '<S30>'  : 'Rider_Controls_InHardware/Message Received2'
 * '<S31>'  : 'Rider_Controls_InHardware/Message Received3'
 * '<S32>'  : 'Rider_Controls_InHardware/Message Received4'
 * '<S33>'  : 'Rider_Controls_InHardware/Message Received5'
 * '<S34>'  : 'Rider_Controls_InHardware/Message Received6'
 * '<S35>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received1'
 * '<S36>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received10'
 * '<S37>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received11'
 * '<S38>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received12'
 * '<S39>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received13'
 * '<S40>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received14'
 * '<S41>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received15'
 * '<S42>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received16'
 * '<S43>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received17'
 * '<S44>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received18'
 * '<S45>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received2'
 * '<S46>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received3'
 * '<S47>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received4'
 * '<S48>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received5'
 * '<S49>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received6'
 * '<S50>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received7'
 * '<S51>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received8'
 * '<S52>'  : 'Rider_Controls_InHardware/CAN Battery Messages/Message Received9'
 * '<S53>'  : 'Rider_Controls_InHardware/Check CAN Time1/Detect Change'
 * '<S54>'  : 'Rider_Controls_InHardware/Check CAN Time10/Detect Change'
 * '<S55>'  : 'Rider_Controls_InHardware/Check CAN Time11/Detect Change'
 * '<S56>'  : 'Rider_Controls_InHardware/Check CAN Time12/Detect Change'
 * '<S57>'  : 'Rider_Controls_InHardware/Check CAN Time13/Detect Change'
 * '<S58>'  : 'Rider_Controls_InHardware/Check CAN Time14/Detect Change'
 * '<S59>'  : 'Rider_Controls_InHardware/Check CAN Time15/Detect Change'
 * '<S60>'  : 'Rider_Controls_InHardware/Check CAN Time16/Detect Change'
 * '<S61>'  : 'Rider_Controls_InHardware/Check CAN Time17/Detect Change'
 * '<S62>'  : 'Rider_Controls_InHardware/Check CAN Time18/Detect Change'
 * '<S63>'  : 'Rider_Controls_InHardware/Check CAN Time19/Detect Change'
 * '<S64>'  : 'Rider_Controls_InHardware/Check CAN Time2/Detect Change'
 * '<S65>'  : 'Rider_Controls_InHardware/Check CAN Time20/Detect Change'
 * '<S66>'  : 'Rider_Controls_InHardware/Check CAN Time21/Detect Change'
 * '<S67>'  : 'Rider_Controls_InHardware/Check CAN Time22/Detect Change'
 * '<S68>'  : 'Rider_Controls_InHardware/Check CAN Time23/Detect Change'
 * '<S69>'  : 'Rider_Controls_InHardware/Check CAN Time26/Detect Change'
 * '<S70>'  : 'Rider_Controls_InHardware/Check CAN Time3/Detect Change'
 * '<S71>'  : 'Rider_Controls_InHardware/Check CAN Time4/Detect Change'
 * '<S72>'  : 'Rider_Controls_InHardware/Check CAN Time5/Detect Change'
 * '<S73>'  : 'Rider_Controls_InHardware/Check CAN Time6/Detect Change'
 * '<S74>'  : 'Rider_Controls_InHardware/Check CAN Time7/Detect Change'
 * '<S75>'  : 'Rider_Controls_InHardware/Check CAN Time8/Detect Change'
 * '<S76>'  : 'Rider_Controls_InHardware/Check CAN Time9/Detect Change'
 */
#endif                                 /* RTW_HEADER_Rider_Controls_InHardware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
