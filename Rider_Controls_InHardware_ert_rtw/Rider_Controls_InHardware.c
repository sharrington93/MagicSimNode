/*
 * File: Rider_Controls_InHardware.c
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

#include "Rider_Controls_InHardware.h"
#include "Rider_Controls_InHardware_private.h"

/* Block signals (auto storage) */
BlockIO_Rider_Controls_InHardwa Rider_Controls_InHardware_B;

/* Block states (auto storage) */
D_Work_Rider_Controls_InHardwar Rider_Controls_InHardware_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Rider_Controls_ Rider_Controls_InHardware_Y;

/* Real-time model */
RT_MODEL_Rider_Controls_InHardw Rider_Controls_InHardware_M_;
RT_MODEL_Rider_Controls_InHardw *const Rider_Controls_InHardware_M =
  &Rider_Controls_InHardware_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Rider_Controls_InHardware_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Rider_Controls_InHardware_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Rider_Controls_InHardware_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  Rider_Controls_InHardware_M->Timing.RateInteraction.TID0_1 =
    (Rider_Controls_InHardware_M->Timing.TaskCounters.TID[1] == 0);

  /* tid 1 shares data with slower tid rate: 2 */
  if (Rider_Controls_InHardware_M->Timing.TaskCounters.TID[1] == 0) {
    Rider_Controls_InHardware_M->Timing.RateInteraction.TID1_2 =
      (Rider_Controls_InHardware_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Rider_Controls_InHardware_M->Timing.TaskCounters.TID[1])++;
  if ((Rider_Controls_InHardware_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.01s, 0.0s] */
    Rider_Controls_InHardware_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Rider_Controls_InHardware_M->Timing.TaskCounters.TID[2])++;
  if ((Rider_Controls_InHardware_M->Timing.TaskCounters.TID[2]) > 99999) {/* Sample time: [1.0s, 0.0s] */
    Rider_Controls_InHardware_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Initial conditions for function-call system:
 *    '<S1>/Message Received4'
 *    '<S1>/Message Received11'
 *    '<S1>/Message Received12'
 *    '<S1>/Message Received13'
 *    '<S1>/Message Received14'
 *    '<S1>/Message Received15'
 *    '<S1>/Message Received1'
 *    '<S1>/Message Received16'
 *    '<S1>/Message Received17'
 *    '<S1>/Message Received18'
 *    ...
 */
void Rider_MessageReceived4_Init(rtDW_MessageReceived4_Rider_Con *localDW)
{
  /* InitializeConditions for S-Function (sdspcount2): '<S47>/Counter' */
  localDW->Counter_Count = 0U;
}

/*
 * Disable for function-call system:
 *    '<S1>/Message Received4'
 *    '<S1>/Message Received11'
 *    '<S1>/Message Received12'
 *    '<S1>/Message Received13'
 *    '<S1>/Message Received14'
 *    '<S1>/Message Received15'
 *    '<S1>/Message Received1'
 *    '<S1>/Message Received16'
 *    '<S1>/Message Received17'
 *    '<S1>/Message Received18'
 *    ...
 */
void Ri_MessageReceived4_Disable(rtB_MessageReceived4_Rider_Cont *localB)
{
  /* Disable for Outport: '<S47>/Result' */
  localB->Counter = 0U;
}

/*
 * Output and update for function-call system:
 *    '<S1>/Message Received4'
 *    '<S1>/Message Received11'
 *    '<S1>/Message Received12'
 *    '<S1>/Message Received13'
 *    '<S1>/Message Received14'
 *    '<S1>/Message Received15'
 *    '<S1>/Message Received1'
 *    '<S1>/Message Received16'
 *    '<S1>/Message Received17'
 *    '<S1>/Message Received18'
 *    ...
 */
void Rider_Cont_MessageReceived4(rtB_MessageReceived4_Rider_Cont *localB,
  rtDW_MessageReceived4_Rider_Con *localDW)
{
  /* S-Function (sdspcount2): '<S47>/Counter' */
  localDW->Counter_Count++;
  localB->Counter = localDW->Counter_Count;
}

/* Model step function for TID0 */
void Rider_Controls_InHardware_step0(void) /* Sample time: [1.0E-5s, 0.0s] */
{
  real32_T rtb_Sum;

  {                                    /* Sample time: [1.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (c2802xadc): '<Root>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC0 = 1;
    asm(" RPT #22 || NOP");
    Rider_Controls_InHardware_B.ADC = (AdcResult.ADCRESULT0);
  }

  /* Sum: '<S26>/Sum' incorporates:
   *  Delay: '<S26>/Delay'
   *  Gain: '<S26>/Gain1'
   *  Gain: '<S26>/Gain2'
   */
  rtb_Sum = 0.0609F * Rider_Controls_InHardware_B.ADC + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE;

  /* RateTransition: '<S26>/Rate Transition' */
  if (Rider_Controls_InHardware_M->Timing.RateInteraction.TID0_1) {
    Rider_Controls_InHardware_B.RateTransition = rtb_Sum;
  }

  /* End of RateTransition: '<S26>/Rate Transition' */

  /* Update for Delay: '<S26>/Delay' */
  Rider_Controls_InHardware_DWork.Delay_DSTATE = rtb_Sum;
}

/* Model step function for TID1 */
void Rider_Controls_InHardware_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  int16_T rtb_BitwiseOperator2;
  int16_T rtb_BitwiseOperator1;
  int16_T rtb_BitwiseOperator3;
  int16_T rtb_BitwiseOperator4;

  /* Outport: '<Root>/Throttle %' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  Rider_Controls_InHardware_Y.Throttle = 0.000244140625F *
    Rider_Controls_InHardware_B.RateTransition;

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP0) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP0 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive_o2.Length =
        ECanaMboxes.MBOX0.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive_o2.ID = 1027;
      Rider_Controls_InHardware_B.eCANReceive_o2.Data[3] =
        ECanaMboxes.MBOX0.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive_o2.Data[2] =
        ECanaMboxes.MBOX0.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive_o2.Data[1] =
        ECanaMboxes.MBOX0.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive_o2.Data[0] =
        ECanaMboxes.MBOX0.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive_o2.Data[7] =
        ECanaMboxes.MBOX0.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive_o2.Data[6] =
        ECanaMboxes.MBOX0.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive_o2.Data[5] =
        ECanaMboxes.MBOX0.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive_o2.Data[4] =
        ECanaMboxes.MBOX0.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived6,
        &Rider_Controls_InHardware_DWork.MessageReceived6);
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive_o2.ID != INVALID_CAN_ID) ) {
      if ((1027U == Rider_Controls_InHardware_B.eCANReceive_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real32_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real32_T) (typeUnpackedValue);
                }
              }

              {
                real32_T result = (real32_T) outValue;
                Rider_Controls_InHardware_Y.RPM = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive1' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP1) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP1 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Length =
        ECanaMboxes.MBOX1.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive1_o2.ID = 812;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3] =
        ECanaMboxes.MBOX1.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2] =
        ECanaMboxes.MBOX1.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1] =
        ECanaMboxes.MBOX1.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0] =
        ECanaMboxes.MBOX1.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7] =
        ECanaMboxes.MBOX1.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6] =
        ECanaMboxes.MBOX1.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5] =
        ECanaMboxes.MBOX1.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4] =
        ECanaMboxes.MBOX1.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived4,
        &Rider_Controls_InHardware_DWork.MessageReceived4);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack1' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack1' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive1_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive1_o2.ID != INVALID_CAN_ID) ) {
      if ((812U == Rider_Controls_InHardware_B.eCANReceive1_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive1_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack1_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack1_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive2' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP2) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP2 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Length =
        ECanaMboxes.MBOX2.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive2_o2.ID = 813;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3] =
        ECanaMboxes.MBOX2.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2] =
        ECanaMboxes.MBOX2.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1] =
        ECanaMboxes.MBOX2.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0] =
        ECanaMboxes.MBOX2.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7] =
        ECanaMboxes.MBOX2.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6] =
        ECanaMboxes.MBOX2.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5] =
        ECanaMboxes.MBOX2.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4] =
        ECanaMboxes.MBOX2.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived1,
        &Rider_Controls_InHardware_DWork.MessageReceived1);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack2' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack2' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive2_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive2_o2.ID != INVALID_CAN_ID) ) {
      if ((813U == Rider_Controls_InHardware_B.eCANReceive2_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive2_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack2_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack2_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive3' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP3) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP3 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Length =
        ECanaMboxes.MBOX3.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive3_o2.ID = 814;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3] =
        ECanaMboxes.MBOX3.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2] =
        ECanaMboxes.MBOX3.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1] =
        ECanaMboxes.MBOX3.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0] =
        ECanaMboxes.MBOX3.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7] =
        ECanaMboxes.MBOX3.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6] =
        ECanaMboxes.MBOX3.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5] =
        ECanaMboxes.MBOX3.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4] =
        ECanaMboxes.MBOX3.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived2,
        &Rider_Controls_InHardware_DWork.MessageReceived2);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack3' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack3' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive3_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive3_o2.ID != INVALID_CAN_ID) ) {
      if ((814U == Rider_Controls_InHardware_B.eCANReceive3_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive3_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack3_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack3_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive4' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP4) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP4 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Length =
        ECanaMboxes.MBOX4.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive4_o2.ID = 815;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3] =
        ECanaMboxes.MBOX4.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2] =
        ECanaMboxes.MBOX4.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1] =
        ECanaMboxes.MBOX4.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0] =
        ECanaMboxes.MBOX4.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7] =
        ECanaMboxes.MBOX4.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6] =
        ECanaMboxes.MBOX4.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5] =
        ECanaMboxes.MBOX4.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4] =
        ECanaMboxes.MBOX4.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived3,
        &Rider_Controls_InHardware_DWork.MessageReceived3);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack4' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack4' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive4_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive4_o2.ID != INVALID_CAN_ID) ) {
      if ((815U == Rider_Controls_InHardware_B.eCANReceive4_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive4_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack4_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack4_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive5' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP5) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP5 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Length =
        ECanaMboxes.MBOX5.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive5_o2.ID = 816;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3] =
        ECanaMboxes.MBOX5.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2] =
        ECanaMboxes.MBOX5.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1] =
        ECanaMboxes.MBOX5.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0] =
        ECanaMboxes.MBOX5.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7] =
        ECanaMboxes.MBOX5.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6] =
        ECanaMboxes.MBOX5.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5] =
        ECanaMboxes.MBOX5.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4] =
        ECanaMboxes.MBOX5.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived5,
        &Rider_Controls_InHardware_DWork.MessageReceived5);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack5' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack5' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive5_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive5_o2.ID != INVALID_CAN_ID) ) {
      if ((816U == Rider_Controls_InHardware_B.eCANReceive5_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive5_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack5_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack5_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive6' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP6) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP6 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Length =
        ECanaMboxes.MBOX6.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive6_o2.ID = 817;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3] =
        ECanaMboxes.MBOX6.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2] =
        ECanaMboxes.MBOX6.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1] =
        ECanaMboxes.MBOX6.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0] =
        ECanaMboxes.MBOX6.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7] =
        ECanaMboxes.MBOX6.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6] =
        ECanaMboxes.MBOX6.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5] =
        ECanaMboxes.MBOX6.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4] =
        ECanaMboxes.MBOX6.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4
        (&Rider_Controls_InHardware_B.MessageReceived6_b,
         &Rider_Controls_InHardware_DWork.MessageReceived6_b);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack6' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack6' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive6_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive6_o2.ID != INVALID_CAN_ID) ) {
      if ((817U == Rider_Controls_InHardware_B.eCANReceive6_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive6_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack6_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack6_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive26' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP7) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP7 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Length =
        ECanaMboxes.MBOX7.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive26_o2.ID = 818;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3] =
        ECanaMboxes.MBOX7.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2] =
        ECanaMboxes.MBOX7.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1] =
        ECanaMboxes.MBOX7.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0] =
        ECanaMboxes.MBOX7.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7] =
        ECanaMboxes.MBOX7.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6] =
        ECanaMboxes.MBOX7.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5] =
        ECanaMboxes.MBOX7.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4] =
        ECanaMboxes.MBOX7.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived7,
        &Rider_Controls_InHardware_DWork.MessageReceived7);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack7' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack7' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive26_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive26_o2.ID != INVALID_CAN_ID) ) {
      if ((818U == Rider_Controls_InHardware_B.eCANReceive26_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive26_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack7_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack7_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive7' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP8) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP8 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Length =
        ECanaMboxes.MBOX8.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive7_o2.ID = 819;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3] =
        ECanaMboxes.MBOX8.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2] =
        ECanaMboxes.MBOX8.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1] =
        ECanaMboxes.MBOX8.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0] =
        ECanaMboxes.MBOX8.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7] =
        ECanaMboxes.MBOX8.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6] =
        ECanaMboxes.MBOX8.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5] =
        ECanaMboxes.MBOX8.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4] =
        ECanaMboxes.MBOX8.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived8,
        &Rider_Controls_InHardware_DWork.MessageReceived8);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack8' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack8' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive7_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive7_o2.ID != INVALID_CAN_ID) ) {
      if ((819U == Rider_Controls_InHardware_B.eCANReceive7_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive7_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack8_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack8_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive8' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP9) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP9 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Length =
        ECanaMboxes.MBOX9.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive8_o2.ID = 820;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3] =
        ECanaMboxes.MBOX9.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2] =
        ECanaMboxes.MBOX9.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1] =
        ECanaMboxes.MBOX9.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0] =
        ECanaMboxes.MBOX9.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7] =
        ECanaMboxes.MBOX9.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6] =
        ECanaMboxes.MBOX9.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5] =
        ECanaMboxes.MBOX9.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4] =
        ECanaMboxes.MBOX9.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived9,
        &Rider_Controls_InHardware_DWork.MessageReceived9);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack9' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack9' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive8_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive8_o2.ID != INVALID_CAN_ID) ) {
      if ((820U == Rider_Controls_InHardware_B.eCANReceive8_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive8_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack9_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack9_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive9' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP10) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP10 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Length =
        ECanaMboxes.MBOX10.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive9_o2.ID = 821;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived10,
        &Rider_Controls_InHardware_DWork.MessageReceived10);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack10' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack10' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive9_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive9_o2.ID != INVALID_CAN_ID) ) {
      if ((821U == Rider_Controls_InHardware_B.eCANReceive9_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive9_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack10_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack10_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive10' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP11) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP11 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Length =
        ECanaMboxes.MBOX11.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive10_o2.ID = 822;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3] =
        ECanaMboxes.MBOX11.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2] =
        ECanaMboxes.MBOX11.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1] =
        ECanaMboxes.MBOX11.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0] =
        ECanaMboxes.MBOX11.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7] =
        ECanaMboxes.MBOX11.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6] =
        ECanaMboxes.MBOX11.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5] =
        ECanaMboxes.MBOX11.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4] =
        ECanaMboxes.MBOX11.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived11,
        &Rider_Controls_InHardware_DWork.MessageReceived11);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack16' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack16' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive10_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive10_o2.ID != INVALID_CAN_ID) ) {
      if ((822U == Rider_Controls_InHardware_B.eCANReceive10_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive10_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack16_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack16_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive16' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP12) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP12 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Length =
        ECanaMboxes.MBOX12.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive16_o2.ID = 823;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3] =
        ECanaMboxes.MBOX12.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2] =
        ECanaMboxes.MBOX12.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1] =
        ECanaMboxes.MBOX12.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0] =
        ECanaMboxes.MBOX12.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7] =
        ECanaMboxes.MBOX12.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6] =
        ECanaMboxes.MBOX12.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5] =
        ECanaMboxes.MBOX12.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4] =
        ECanaMboxes.MBOX12.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived12,
        &Rider_Controls_InHardware_DWork.MessageReceived12);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack17' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack17' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive16_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive16_o2.ID != INVALID_CAN_ID) ) {
      if ((823U == Rider_Controls_InHardware_B.eCANReceive16_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive16_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack17_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack17_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive17' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP13) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP13 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Length =
        ECanaMboxes.MBOX13.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive17_o2.ID = 824;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3] =
        ECanaMboxes.MBOX13.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2] =
        ECanaMboxes.MBOX13.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1] =
        ECanaMboxes.MBOX13.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0] =
        ECanaMboxes.MBOX13.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7] =
        ECanaMboxes.MBOX13.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6] =
        ECanaMboxes.MBOX13.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5] =
        ECanaMboxes.MBOX13.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4] =
        ECanaMboxes.MBOX13.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived13,
        &Rider_Controls_InHardware_DWork.MessageReceived13);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack18' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack18' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive17_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive17_o2.ID != INVALID_CAN_ID) ) {
      if ((824U == Rider_Controls_InHardware_B.eCANReceive17_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive17_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack18_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack18_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive18' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP14) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP14 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Length =
        ECanaMboxes.MBOX14.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive18_o2.ID = 825;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3] =
        ECanaMboxes.MBOX14.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2] =
        ECanaMboxes.MBOX14.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1] =
        ECanaMboxes.MBOX14.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0] =
        ECanaMboxes.MBOX14.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7] =
        ECanaMboxes.MBOX14.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6] =
        ECanaMboxes.MBOX14.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5] =
        ECanaMboxes.MBOX14.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4] =
        ECanaMboxes.MBOX14.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived14,
        &Rider_Controls_InHardware_DWork.MessageReceived14);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack19' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack19' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive18_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive18_o2.ID != INVALID_CAN_ID) ) {
      if ((825U == Rider_Controls_InHardware_B.eCANReceive18_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive18_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack19_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack19_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive19' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP15) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP15 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Length =
        ECanaMboxes.MBOX15.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive19_o2.ID = 826;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3] =
        ECanaMboxes.MBOX15.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2] =
        ECanaMboxes.MBOX15.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1] =
        ECanaMboxes.MBOX15.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0] =
        ECanaMboxes.MBOX15.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7] =
        ECanaMboxes.MBOX15.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6] =
        ECanaMboxes.MBOX15.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5] =
        ECanaMboxes.MBOX15.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4] =
        ECanaMboxes.MBOX15.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived15,
        &Rider_Controls_InHardware_DWork.MessageReceived15);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack20' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack20' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive19_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive19_o2.ID != INVALID_CAN_ID) ) {
      if ((826U == Rider_Controls_InHardware_B.eCANReceive19_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive19_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack20_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack20_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive20' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP16) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP16 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Length =
        ECanaMboxes.MBOX16.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive20_o2.ID = 827;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3] =
        ECanaMboxes.MBOX16.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2] =
        ECanaMboxes.MBOX16.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1] =
        ECanaMboxes.MBOX16.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0] =
        ECanaMboxes.MBOX16.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7] =
        ECanaMboxes.MBOX16.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6] =
        ECanaMboxes.MBOX16.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5] =
        ECanaMboxes.MBOX16.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4] =
        ECanaMboxes.MBOX16.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived16,
        &Rider_Controls_InHardware_DWork.MessageReceived16);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack21' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack21' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive20_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive20_o2.ID != INVALID_CAN_ID) ) {
      if ((827U == Rider_Controls_InHardware_B.eCANReceive20_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive20_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack21_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack21_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive21' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP17) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP17 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Length =
        ECanaMboxes.MBOX17.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive21_o2.ID = 828;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3] =
        ECanaMboxes.MBOX17.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2] =
        ECanaMboxes.MBOX17.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1] =
        ECanaMboxes.MBOX17.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0] =
        ECanaMboxes.MBOX17.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7] =
        ECanaMboxes.MBOX17.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6] =
        ECanaMboxes.MBOX17.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5] =
        ECanaMboxes.MBOX17.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4] =
        ECanaMboxes.MBOX17.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived17,
        &Rider_Controls_InHardware_DWork.MessageReceived17);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack22' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack22' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive21_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive21_o2.ID != INVALID_CAN_ID) ) {
      if ((828U == Rider_Controls_InHardware_B.eCANReceive21_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive21_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack22_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack22_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<S1>/eCAN Receive22' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP18) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP18 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Length =
        ECanaMboxes.MBOX18.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive22_o2.ID = 829;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3] =
        ECanaMboxes.MBOX18.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2] =
        ECanaMboxes.MBOX18.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1] =
        ECanaMboxes.MBOX18.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0] =
        ECanaMboxes.MBOX18.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7] =
        ECanaMboxes.MBOX18.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6] =
        ECanaMboxes.MBOX18.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5] =
        ECanaMboxes.MBOX18.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4] =
        ECanaMboxes.MBOX18.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4(&Rider_Controls_InHardware_B.MessageReceived18,
        &Rider_Controls_InHardware_DWork.MessageReceived18);
    }
  }

  /* S-Function (scanunpack): '<S1>/CAN Unpack23' */
  {
    /* S-Function (scanunpack): '<S1>/CAN Unpack23' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive22_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive22_o2.ID != INVALID_CAN_ID) ) {
      if ((829U == Rider_Controls_InHardware_B.eCANReceive22_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive22_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack23_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SINGLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;
                  real32_T typeUnpackedValue;
                  real32_T* pInput;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  pInput = (real32_T*) (&unpackedValue);
                  typeUnpackedValue = *pInput;
                  outValue = (real64_T) (typeUnpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack23_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* Sum: '<S28>/Sum' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Delay: '<S28>/Delay'
   *  Gain: '<S28>/Gain1'
   *  Gain: '<S28>/Gain2'
   */
  Rider_Controls_InHardware_B.Sum_d[0] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack1_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[0];
  Rider_Controls_InHardware_B.Sum_d[1] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack1_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[1];
  Rider_Controls_InHardware_B.Sum_d[2] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack2_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[2];
  Rider_Controls_InHardware_B.Sum_d[3] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack2_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[3];
  Rider_Controls_InHardware_B.Sum_d[4] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack3_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[4];
  Rider_Controls_InHardware_B.Sum_d[5] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack3_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[5];
  Rider_Controls_InHardware_B.Sum_d[6] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack4_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[6];
  Rider_Controls_InHardware_B.Sum_d[7] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack4_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[7];
  Rider_Controls_InHardware_B.Sum_d[8] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack5_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[8];
  Rider_Controls_InHardware_B.Sum_d[9] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack5_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[9];
  Rider_Controls_InHardware_B.Sum_d[10] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack6_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[10];
  Rider_Controls_InHardware_B.Sum_d[11] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack6_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[11];
  Rider_Controls_InHardware_B.Sum_d[12] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack7_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[12];
  Rider_Controls_InHardware_B.Sum_d[13] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack7_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[13];
  Rider_Controls_InHardware_B.Sum_d[14] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack8_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[14];
  Rider_Controls_InHardware_B.Sum_d[15] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack8_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[15];
  Rider_Controls_InHardware_B.Sum_d[16] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack9_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[16];
  Rider_Controls_InHardware_B.Sum_d[17] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack9_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[17];
  Rider_Controls_InHardware_B.Sum_d[18] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack10_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[18];
  Rider_Controls_InHardware_B.Sum_d[19] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack10_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[19];
  Rider_Controls_InHardware_B.Sum_d[20] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack16_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[20];
  Rider_Controls_InHardware_B.Sum_d[21] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack16_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[21];
  Rider_Controls_InHardware_B.Sum_d[22] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack17_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[22];
  Rider_Controls_InHardware_B.Sum_d[23] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack17_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[23];
  Rider_Controls_InHardware_B.Sum_d[24] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack18_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[24];
  Rider_Controls_InHardware_B.Sum_d[25] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack18_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[25];
  Rider_Controls_InHardware_B.Sum_d[26] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack19_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[26];
  Rider_Controls_InHardware_B.Sum_d[27] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack19_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[27];
  Rider_Controls_InHardware_B.Sum_d[28] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack20_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[28];
  Rider_Controls_InHardware_B.Sum_d[29] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack20_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[29];
  Rider_Controls_InHardware_B.Sum_d[30] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack21_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[30];
  Rider_Controls_InHardware_B.Sum_d[31] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack21_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[31];
  Rider_Controls_InHardware_B.Sum_d[32] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack22_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[32];
  Rider_Controls_InHardware_B.Sum_d[33] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack22_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[33];
  Rider_Controls_InHardware_B.Sum_d[34] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack23_o1 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[34];
  Rider_Controls_InHardware_B.Sum_d[35] = 0.0609F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack23_o2 + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_o[35];

  /* Outport: '<Root>/Temperatures' */
  memcpy(&Rider_Controls_InHardware_Y.Temperatures[0],
         &Rider_Controls_InHardware_B.Sum_d[0], 36U * sizeof(real32_T));

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive11' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP21) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP21 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Length =
        ECanaMboxes.MBOX21.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive11_o2.ID = 832;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3] =
        ECanaMboxes.MBOX21.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2] =
        ECanaMboxes.MBOX21.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1] =
        ECanaMboxes.MBOX21.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0] =
        ECanaMboxes.MBOX21.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[7] =
        ECanaMboxes.MBOX21.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[6] =
        ECanaMboxes.MBOX21.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5] =
        ECanaMboxes.MBOX21.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4] =
        ECanaMboxes.MBOX21.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4
        (&Rider_Controls_InHardware_B.MessageReceived4_b,
         &Rider_Controls_InHardware_DWork.MessageReceived4_b);
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack11' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack11' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive11_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive11_o2.ID != INVALID_CAN_ID) ) {
      if ((832U == Rider_Controls_InHardware_B.eCANReceive11_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive11_o2.Extended) ) {
        (void) memcpy(&Rider_Controls_InHardware_B.CANUnpack11_o1[0],
                      Rider_Controls_InHardware_B.eCANReceive11_o2.Data,
                      8 * sizeof(uint8_T));

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack11_o2 =
          Rider_Controls_InHardware_B.eCANReceive11_o2.Timestamp;
      }
    }
  }

  /* S-Function (sfix_bitop): '<Root>/Bitwise Operator2' */
  rtb_BitwiseOperator2 = (int16_T)(Rider_Controls_InHardware_B.CANUnpack11_o1[4]
    & 1U);

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive12' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP22) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP22 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Length =
        ECanaMboxes.MBOX22.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive12_o2.ID = 833;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3] =
        ECanaMboxes.MBOX22.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2] =
        ECanaMboxes.MBOX22.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1] =
        ECanaMboxes.MBOX22.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0] =
        ECanaMboxes.MBOX22.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[7] =
        ECanaMboxes.MBOX22.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[6] =
        ECanaMboxes.MBOX22.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5] =
        ECanaMboxes.MBOX22.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4] =
        ECanaMboxes.MBOX22.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4
        (&Rider_Controls_InHardware_B.MessageReceived3_b,
         &Rider_Controls_InHardware_DWork.MessageReceived3_b);
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack12' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack12' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive12_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive12_o2.ID != INVALID_CAN_ID) ) {
      if ((833U == Rider_Controls_InHardware_B.eCANReceive12_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive12_o2.Extended) ) {
        (void) memcpy(&Rider_Controls_InHardware_B.CANUnpack12[0],
                      Rider_Controls_InHardware_B.eCANReceive12_o2.Data,
                      8 * sizeof(uint8_T));
      }
    }
  }

  /* S-Function (sfix_bitop): '<Root>/Bitwise Operator1' */
  rtb_BitwiseOperator1 = (int16_T)(Rider_Controls_InHardware_B.CANUnpack12[4] &
    1U);

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive13' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP23) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP23 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Length =
        ECanaMboxes.MBOX23.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive13_o2.ID = 834;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3] =
        ECanaMboxes.MBOX23.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2] =
        ECanaMboxes.MBOX23.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1] =
        ECanaMboxes.MBOX23.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0] =
        ECanaMboxes.MBOX23.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[7] =
        ECanaMboxes.MBOX23.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[6] =
        ECanaMboxes.MBOX23.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5] =
        ECanaMboxes.MBOX23.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4] =
        ECanaMboxes.MBOX23.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4
        (&Rider_Controls_InHardware_B.MessageReceived2_a,
         &Rider_Controls_InHardware_DWork.MessageReceived2_a);
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack13' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack13' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive13_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive13_o2.ID != INVALID_CAN_ID) ) {
      if ((834U == Rider_Controls_InHardware_B.eCANReceive13_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive13_o2.Extended) ) {
        (void) memcpy(&Rider_Controls_InHardware_B.CANUnpack13[0],
                      Rider_Controls_InHardware_B.eCANReceive13_o2.Data,
                      8 * sizeof(uint8_T));
      }
    }
  }

  /* S-Function (sfix_bitop): '<Root>/Bitwise Operator3' */
  rtb_BitwiseOperator3 = (int16_T)(Rider_Controls_InHardware_B.CANUnpack13[4] &
    1U);

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive14' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP24) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP24 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Length =
        ECanaMboxes.MBOX24.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive14_o2.ID = 835;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3] =
        ECanaMboxes.MBOX24.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2] =
        ECanaMboxes.MBOX24.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1] =
        ECanaMboxes.MBOX24.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0] =
        ECanaMboxes.MBOX24.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[7] =
        ECanaMboxes.MBOX24.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[6] =
        ECanaMboxes.MBOX24.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5] =
        ECanaMboxes.MBOX24.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4] =
        ECanaMboxes.MBOX24.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4
        (&Rider_Controls_InHardware_B.MessageReceived1_c,
         &Rider_Controls_InHardware_DWork.MessageReceived1_c);
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack14' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack14' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive14_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive14_o2.ID != INVALID_CAN_ID) ) {
      if ((835U == Rider_Controls_InHardware_B.eCANReceive14_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive14_o2.Extended) ) {
        (void) memcpy(&Rider_Controls_InHardware_B.CANUnpack14[0],
                      Rider_Controls_InHardware_B.eCANReceive14_o2.Data,
                      8 * sizeof(uint8_T));
      }
    }
  }

  /* S-Function (sfix_bitop): '<Root>/Bitwise Operator4' */
  rtb_BitwiseOperator4 = (int16_T)(Rider_Controls_InHardware_B.CANUnpack14[4] &
    1U);

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive15' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP25) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP25 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Length =
        ECanaMboxes.MBOX25.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive15_o2.ID = 836;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3] =
        ECanaMboxes.MBOX25.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2] =
        ECanaMboxes.MBOX25.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1] =
        ECanaMboxes.MBOX25.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0] =
        ECanaMboxes.MBOX25.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[7] =
        ECanaMboxes.MBOX25.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[6] =
        ECanaMboxes.MBOX25.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5] =
        ECanaMboxes.MBOX25.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4] =
        ECanaMboxes.MBOX25.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
      Rider_Cont_MessageReceived4
        (&Rider_Controls_InHardware_B.MessageReceived5_n,
         &Rider_Controls_InHardware_DWork.MessageReceived5_n);
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack15' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack15' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive15_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive15_o2.ID != INVALID_CAN_ID) ) {
      if ((836U == Rider_Controls_InHardware_B.eCANReceive15_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive15_o2.Extended) ) {
        (void) memcpy(&Rider_Controls_InHardware_B.CANUnpack15_o1[0],
                      Rider_Controls_InHardware_B.eCANReceive15_o2.Data,
                      8 * sizeof(uint8_T));

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack15_o2 =
          Rider_Controls_InHardware_B.eCANReceive15_o2.Timestamp;
      }
    }
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (Rider_Controls_InHardware_M->Timing.RateInteraction.TID1_2) {
    Rider_Controls_InHardware_B.RateTransition_lz =
      Rider_Controls_InHardware_DWork.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Outport: '<Root>/BIM Status' incorporates:
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Logic: '<Root>/Logical Operator1'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator5'
   *  Sum: '<Root>/Add'
   */
  Rider_Controls_InHardware_Y.BIMStatus = (uint16_T)((((((uint16_T)
    rtb_BitwiseOperator2 + rtb_BitwiseOperator1) + rtb_BitwiseOperator3) +
    rtb_BitwiseOperator4) + (Rider_Controls_InHardware_B.CANUnpack15_o1[4] & 1U)
    != 5U) || Rider_Controls_InHardware_B.RateTransition_lz);

  /* RateTransition: '<S2>/Rate Transition' */
  if (Rider_Controls_InHardware_M->Timing.RateInteraction.TID1_2) {
    Rider_Controls_InHardware_B.RateTransition_n =
      Rider_Controls_InHardware_B.MessageReceived5_n.Counter;

    /* RateTransition: '<S3>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_c =
      Rider_Controls_InHardware_B.MessageReceived5.Counter;

    /* RateTransition: '<S4>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_a =
      Rider_Controls_InHardware_B.MessageReceived6_b.Counter;

    /* RateTransition: '<S5>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_o =
      Rider_Controls_InHardware_B.MessageReceived7.Counter;

    /* RateTransition: '<S6>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_at =
      Rider_Controls_InHardware_B.MessageReceived8.Counter;

    /* RateTransition: '<S7>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_h =
      Rider_Controls_InHardware_B.MessageReceived9.Counter;

    /* RateTransition: '<S8>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_m =
      Rider_Controls_InHardware_B.MessageReceived10.Counter;

    /* RateTransition: '<S9>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_d =
      Rider_Controls_InHardware_B.MessageReceived11.Counter;

    /* RateTransition: '<S10>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_ag =
      Rider_Controls_InHardware_B.MessageReceived12.Counter;

    /* RateTransition: '<S11>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_l =
      Rider_Controls_InHardware_B.MessageReceived13.Counter;

    /* RateTransition: '<S12>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_p =
      Rider_Controls_InHardware_B.MessageReceived14.Counter;

    /* RateTransition: '<S13>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_mc =
      Rider_Controls_InHardware_B.MessageReceived1_c.Counter;

    /* RateTransition: '<S14>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_ar =
      Rider_Controls_InHardware_B.MessageReceived15.Counter;

    /* RateTransition: '<S15>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_k =
      Rider_Controls_InHardware_B.MessageReceived16.Counter;

    /* RateTransition: '<S16>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_e =
      Rider_Controls_InHardware_B.MessageReceived17.Counter;

    /* RateTransition: '<S17>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_h4 =
      Rider_Controls_InHardware_B.MessageReceived18.Counter;

    /* RateTransition: '<S18>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_b =
      Rider_Controls_InHardware_B.MessageReceived6.Counter;

    /* RateTransition: '<S19>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_f =
      Rider_Controls_InHardware_B.MessageReceived2_a.Counter;

    /* RateTransition: '<S20>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_a5 =
      Rider_Controls_InHardware_B.MessageReceived3_b.Counter;

    /* RateTransition: '<S21>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_al =
      Rider_Controls_InHardware_B.MessageReceived4_b.Counter;

    /* RateTransition: '<S22>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_pj =
      Rider_Controls_InHardware_B.MessageReceived4.Counter;

    /* RateTransition: '<S23>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_nw =
      Rider_Controls_InHardware_B.MessageReceived1.Counter;

    /* RateTransition: '<S24>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_i =
      Rider_Controls_InHardware_B.MessageReceived2.Counter;

    /* RateTransition: '<S25>/Rate Transition' */
    Rider_Controls_InHardware_B.RateTransition_ov =
      Rider_Controls_InHardware_B.MessageReceived3.Counter;
  }

  /* End of RateTransition: '<S2>/Rate Transition' */

  /* S-Function (c280xgpio_di): '<Root>/Digital Input' */
  {
    Rider_Controls_InHardware_B.DigitalInput = GpioDataRegs.GPADAT.bit.GPIO26;
  }

  /* Outport: '<Root>/E-Stop' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion40'
   *  Logic: '<Root>/Logical Operator2'
   */
  Rider_Controls_InHardware_Y.EStop = (uint16_T)
    !Rider_Controls_InHardware_B.DigitalInput;

  /* Update for Delay: '<S28>/Delay' */
  memcpy(&Rider_Controls_InHardware_DWork.Delay_DSTATE_o[0],
         &Rider_Controls_InHardware_B.Sum_d[0], 36U * sizeof(real32_T));
}

/* Model step function for TID2 */
void Rider_Controls_InHardware_step2(void) /* Sample time: [1.0s, 0.0s] */
{
  uint16_T rtb_Counter;
  boolean_T rtb_RelationalOperator_m5;
  boolean_T rtb_RelationalOperator_j;
  boolean_T rtb_RelationalOperator_gk;
  boolean_T rtb_RelationalOperator_po;
  boolean_T rtb_RelationalOperator_or;
  boolean_T rtb_RelationalOperator_d;
  boolean_T rtb_RelationalOperator_bd;
  boolean_T rtb_RelationalOperator_e;
  boolean_T rtb_RelationalOperator_i;
  boolean_T rtb_RelationalOperator_i4;
  boolean_T rtb_RelationalOperator_kj;
  boolean_T rtb_RelationalOperator_l0;
  boolean_T rtb_RelationalOperator_k;
  boolean_T rtb_RelationalOperator_ll;
  boolean_T rtb_RelationalOperator_m;
  boolean_T rtb_RelationalOperator_ad;
  boolean_T rtb_RelationalOperator_bl;
  boolean_T rtb_RelationalOperator_a;
  boolean_T rtb_RelationalOperator_g;
  boolean_T rtb_RelationalOperator_n;
  boolean_T rtb_RelationalOperator_f;
  boolean_T rtb_RelationalOperator_no;
  boolean_T rtb_RelationalOperator_h;

  /* S-Function (sdspcount2): '<S2>/Counter' incorporates:
   *  RelationalOperator: '<S53>/FixPt Relational Operator'
   *  UnitDelay: '<S53>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_n !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE) {
    Rider_Controls_InHardware_DWork.Counter_Count = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count;
  Rider_Controls_InHardware_DWork.Counter_Count++;

  /* End of S-Function (sdspcount2): '<S2>/Counter' */

  /* RelationalOperator: '<S2>/Relational Operator' */
  rtb_RelationalOperator_m5 = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S3>/Counter' incorporates:
   *  RelationalOperator: '<S54>/FixPt Relational Operator'
   *  UnitDelay: '<S54>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_c !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_f) {
    Rider_Controls_InHardware_DWork.Counter_Count_l = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_l;
  Rider_Controls_InHardware_DWork.Counter_Count_l++;

  /* End of S-Function (sdspcount2): '<S3>/Counter' */

  /* RelationalOperator: '<S3>/Relational Operator' */
  rtb_RelationalOperator_j = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S4>/Counter' incorporates:
   *  RelationalOperator: '<S55>/FixPt Relational Operator'
   *  UnitDelay: '<S55>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_a !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_e) {
    Rider_Controls_InHardware_DWork.Counter_Count_i = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_i;
  Rider_Controls_InHardware_DWork.Counter_Count_i++;

  /* End of S-Function (sdspcount2): '<S4>/Counter' */

  /* RelationalOperator: '<S4>/Relational Operator' */
  rtb_RelationalOperator_gk = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S5>/Counter' incorporates:
   *  RelationalOperator: '<S56>/FixPt Relational Operator'
   *  UnitDelay: '<S56>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_o !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_m) {
    Rider_Controls_InHardware_DWork.Counter_Count_d = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_d;
  Rider_Controls_InHardware_DWork.Counter_Count_d++;

  /* End of S-Function (sdspcount2): '<S5>/Counter' */

  /* RelationalOperator: '<S5>/Relational Operator' */
  rtb_RelationalOperator_po = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S6>/Counter' incorporates:
   *  RelationalOperator: '<S57>/FixPt Relational Operator'
   *  UnitDelay: '<S57>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_at !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_d) {
    Rider_Controls_InHardware_DWork.Counter_Count_k = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_k;
  Rider_Controls_InHardware_DWork.Counter_Count_k++;

  /* End of S-Function (sdspcount2): '<S6>/Counter' */

  /* RelationalOperator: '<S6>/Relational Operator' */
  rtb_RelationalOperator_or = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S7>/Counter' incorporates:
   *  RelationalOperator: '<S58>/FixPt Relational Operator'
   *  UnitDelay: '<S58>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_h !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_h) {
    Rider_Controls_InHardware_DWork.Counter_Count_c = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_c;
  Rider_Controls_InHardware_DWork.Counter_Count_c++;

  /* End of S-Function (sdspcount2): '<S7>/Counter' */

  /* RelationalOperator: '<S7>/Relational Operator' */
  rtb_RelationalOperator_d = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S8>/Counter' incorporates:
   *  RelationalOperator: '<S59>/FixPt Relational Operator'
   *  UnitDelay: '<S59>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_m !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_l) {
    Rider_Controls_InHardware_DWork.Counter_Count_h = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_h;
  Rider_Controls_InHardware_DWork.Counter_Count_h++;

  /* End of S-Function (sdspcount2): '<S8>/Counter' */

  /* RelationalOperator: '<S8>/Relational Operator' */
  rtb_RelationalOperator_bd = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S9>/Counter' incorporates:
   *  RelationalOperator: '<S60>/FixPt Relational Operator'
   *  UnitDelay: '<S60>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_d !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_mj) {
    Rider_Controls_InHardware_DWork.Counter_Count_f = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_f;
  Rider_Controls_InHardware_DWork.Counter_Count_f++;

  /* End of S-Function (sdspcount2): '<S9>/Counter' */

  /* RelationalOperator: '<S9>/Relational Operator' */
  rtb_RelationalOperator_e = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S10>/Counter' incorporates:
   *  RelationalOperator: '<S61>/FixPt Relational Operator'
   *  UnitDelay: '<S61>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_ag !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c) {
    Rider_Controls_InHardware_DWork.Counter_Count_im = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_im;
  Rider_Controls_InHardware_DWork.Counter_Count_im++;

  /* End of S-Function (sdspcount2): '<S10>/Counter' */

  /* RelationalOperator: '<S10>/Relational Operator' */
  rtb_RelationalOperator_i = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S11>/Counter' incorporates:
   *  RelationalOperator: '<S62>/FixPt Relational Operator'
   *  UnitDelay: '<S62>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_l !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_b) {
    Rider_Controls_InHardware_DWork.Counter_Count_p = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_p;
  Rider_Controls_InHardware_DWork.Counter_Count_p++;

  /* End of S-Function (sdspcount2): '<S11>/Counter' */

  /* RelationalOperator: '<S11>/Relational Operator' */
  rtb_RelationalOperator_i4 = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S12>/Counter' incorporates:
   *  RelationalOperator: '<S63>/FixPt Relational Operator'
   *  UnitDelay: '<S63>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_p !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_p) {
    Rider_Controls_InHardware_DWork.Counter_Count_a = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_a;
  Rider_Controls_InHardware_DWork.Counter_Count_a++;

  /* End of S-Function (sdspcount2): '<S12>/Counter' */

  /* RelationalOperator: '<S12>/Relational Operator' */
  rtb_RelationalOperator_kj = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S13>/Counter' incorporates:
   *  RelationalOperator: '<S64>/FixPt Relational Operator'
   *  UnitDelay: '<S64>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_mc !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dv) {
    Rider_Controls_InHardware_DWork.Counter_Count_ls = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_ls;
  Rider_Controls_InHardware_DWork.Counter_Count_ls++;

  /* End of S-Function (sdspcount2): '<S13>/Counter' */

  /* RelationalOperator: '<S13>/Relational Operator' */
  rtb_RelationalOperator_l0 = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S14>/Counter' incorporates:
   *  RelationalOperator: '<S65>/FixPt Relational Operator'
   *  UnitDelay: '<S65>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_ar !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_cs) {
    Rider_Controls_InHardware_DWork.Counter_Count_ll = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_ll;
  Rider_Controls_InHardware_DWork.Counter_Count_ll++;

  /* End of S-Function (sdspcount2): '<S14>/Counter' */

  /* RelationalOperator: '<S14>/Relational Operator' */
  rtb_RelationalOperator_k = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S15>/Counter' incorporates:
   *  RelationalOperator: '<S66>/FixPt Relational Operator'
   *  UnitDelay: '<S66>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_k !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_k) {
    Rider_Controls_InHardware_DWork.Counter_Count_d0 = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_d0;
  Rider_Controls_InHardware_DWork.Counter_Count_d0++;

  /* End of S-Function (sdspcount2): '<S15>/Counter' */

  /* RelationalOperator: '<S15>/Relational Operator' */
  rtb_RelationalOperator_ll = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S16>/Counter' incorporates:
   *  RelationalOperator: '<S67>/FixPt Relational Operator'
   *  UnitDelay: '<S67>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_e !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_g) {
    Rider_Controls_InHardware_DWork.Counter_Count_hr = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_hr;
  Rider_Controls_InHardware_DWork.Counter_Count_hr++;

  /* End of S-Function (sdspcount2): '<S16>/Counter' */

  /* RelationalOperator: '<S16>/Relational Operator' */
  rtb_RelationalOperator_m = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S17>/Counter' incorporates:
   *  RelationalOperator: '<S68>/FixPt Relational Operator'
   *  UnitDelay: '<S68>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_h4 !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c0) {
    Rider_Controls_InHardware_DWork.Counter_Count_ix = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_ix;
  Rider_Controls_InHardware_DWork.Counter_Count_ix++;

  /* End of S-Function (sdspcount2): '<S17>/Counter' */

  /* RelationalOperator: '<S17>/Relational Operator' */
  rtb_RelationalOperator_ad = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S18>/Counter' incorporates:
   *  RelationalOperator: '<S69>/FixPt Relational Operator'
   *  UnitDelay: '<S69>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_b !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_o) {
    Rider_Controls_InHardware_DWork.Counter_Count_ce = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_ce;
  Rider_Controls_InHardware_DWork.Counter_Count_ce++;

  /* End of S-Function (sdspcount2): '<S18>/Counter' */

  /* RelationalOperator: '<S18>/Relational Operator' */
  rtb_RelationalOperator_bl = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S19>/Counter' incorporates:
   *  RelationalOperator: '<S70>/FixPt Relational Operator'
   *  UnitDelay: '<S70>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_f !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_n) {
    Rider_Controls_InHardware_DWork.Counter_Count_e = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_e;
  Rider_Controls_InHardware_DWork.Counter_Count_e++;

  /* End of S-Function (sdspcount2): '<S19>/Counter' */

  /* RelationalOperator: '<S19>/Relational Operator' */
  rtb_RelationalOperator_a = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S20>/Counter' incorporates:
   *  RelationalOperator: '<S71>/FixPt Relational Operator'
   *  UnitDelay: '<S71>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_a5 !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dt) {
    Rider_Controls_InHardware_DWork.Counter_Count_ha = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_ha;
  Rider_Controls_InHardware_DWork.Counter_Count_ha++;

  /* End of S-Function (sdspcount2): '<S20>/Counter' */

  /* RelationalOperator: '<S20>/Relational Operator' */
  rtb_RelationalOperator_g = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S21>/Counter' incorporates:
   *  RelationalOperator: '<S72>/FixPt Relational Operator'
   *  UnitDelay: '<S72>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_al !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dy) {
    Rider_Controls_InHardware_DWork.Counter_Count_g = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_g;
  Rider_Controls_InHardware_DWork.Counter_Count_g++;

  /* End of S-Function (sdspcount2): '<S21>/Counter' */

  /* RelationalOperator: '<S21>/Relational Operator' */
  rtb_RelationalOperator_n = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S22>/Counter' incorporates:
   *  RelationalOperator: '<S73>/FixPt Relational Operator'
   *  UnitDelay: '<S73>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_pj !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_ey) {
    Rider_Controls_InHardware_DWork.Counter_Count_h1 = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_h1;
  Rider_Controls_InHardware_DWork.Counter_Count_h1++;

  /* End of S-Function (sdspcount2): '<S22>/Counter' */

  /* RelationalOperator: '<S22>/Relational Operator' */
  rtb_RelationalOperator_f = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S23>/Counter' incorporates:
   *  RelationalOperator: '<S74>/FixPt Relational Operator'
   *  UnitDelay: '<S74>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_nw !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c2) {
    Rider_Controls_InHardware_DWork.Counter_Count_ks = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_ks;
  Rider_Controls_InHardware_DWork.Counter_Count_ks++;

  /* End of S-Function (sdspcount2): '<S23>/Counter' */

  /* RelationalOperator: '<S23>/Relational Operator' */
  rtb_RelationalOperator_no = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S24>/Counter' incorporates:
   *  RelationalOperator: '<S75>/FixPt Relational Operator'
   *  UnitDelay: '<S75>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_i !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_j) {
    Rider_Controls_InHardware_DWork.Counter_Count_ca = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_ca;
  Rider_Controls_InHardware_DWork.Counter_Count_ca++;

  /* End of S-Function (sdspcount2): '<S24>/Counter' */

  /* RelationalOperator: '<S24>/Relational Operator' */
  rtb_RelationalOperator_h = (rtb_Counter >= 3U);

  /* S-Function (sdspcount2): '<S25>/Counter' incorporates:
   *  RelationalOperator: '<S76>/FixPt Relational Operator'
   *  UnitDelay: '<S76>/Delay Input1'
   */
  if (Rider_Controls_InHardware_B.RateTransition_ov !=
      Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_kj) {
    Rider_Controls_InHardware_DWork.Counter_Count_i1 = 0U;
  }

  rtb_Counter = Rider_Controls_InHardware_DWork.Counter_Count_i1;
  Rider_Controls_InHardware_DWork.Counter_Count_i1++;

  /* End of S-Function (sdspcount2): '<S25>/Counter' */

  /* Update for RateTransition: '<Root>/Rate Transition' incorporates:
   *  Logic: '<Root>/Logical Operator'
   *  RelationalOperator: '<S25>/Relational Operator'
   */
  Rider_Controls_InHardware_DWork.RateTransition_Buffer0 =
    (rtb_RelationalOperator_m5 || rtb_RelationalOperator_l0 ||
     rtb_RelationalOperator_a || rtb_RelationalOperator_g ||
     rtb_RelationalOperator_n || rtb_RelationalOperator_f ||
     rtb_RelationalOperator_no || rtb_RelationalOperator_h || (rtb_Counter >= 3U)
     || rtb_RelationalOperator_j || rtb_RelationalOperator_gk ||
     rtb_RelationalOperator_po || rtb_RelationalOperator_or ||
     rtb_RelationalOperator_d || rtb_RelationalOperator_bd ||
     rtb_RelationalOperator_e || rtb_RelationalOperator_i ||
     rtb_RelationalOperator_i4 || rtb_RelationalOperator_kj ||
     rtb_RelationalOperator_k || rtb_RelationalOperator_ll ||
     rtb_RelationalOperator_m || rtb_RelationalOperator_ad ||
     rtb_RelationalOperator_bl);

  /* Update for UnitDelay: '<S53>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE =
    Rider_Controls_InHardware_B.RateTransition_n;

  /* Update for UnitDelay: '<S54>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_f =
    Rider_Controls_InHardware_B.RateTransition_c;

  /* Update for UnitDelay: '<S55>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_e =
    Rider_Controls_InHardware_B.RateTransition_a;

  /* Update for UnitDelay: '<S56>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_m =
    Rider_Controls_InHardware_B.RateTransition_o;

  /* Update for UnitDelay: '<S57>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_d =
    Rider_Controls_InHardware_B.RateTransition_at;

  /* Update for UnitDelay: '<S58>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_h =
    Rider_Controls_InHardware_B.RateTransition_h;

  /* Update for UnitDelay: '<S59>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_l =
    Rider_Controls_InHardware_B.RateTransition_m;

  /* Update for UnitDelay: '<S60>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_mj =
    Rider_Controls_InHardware_B.RateTransition_d;

  /* Update for UnitDelay: '<S61>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c =
    Rider_Controls_InHardware_B.RateTransition_ag;

  /* Update for UnitDelay: '<S62>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_b =
    Rider_Controls_InHardware_B.RateTransition_l;

  /* Update for UnitDelay: '<S63>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_p =
    Rider_Controls_InHardware_B.RateTransition_p;

  /* Update for UnitDelay: '<S64>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dv =
    Rider_Controls_InHardware_B.RateTransition_mc;

  /* Update for UnitDelay: '<S65>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_cs =
    Rider_Controls_InHardware_B.RateTransition_ar;

  /* Update for UnitDelay: '<S66>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_k =
    Rider_Controls_InHardware_B.RateTransition_k;

  /* Update for UnitDelay: '<S67>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_g =
    Rider_Controls_InHardware_B.RateTransition_e;

  /* Update for UnitDelay: '<S68>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c0 =
    Rider_Controls_InHardware_B.RateTransition_h4;

  /* Update for UnitDelay: '<S69>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_o =
    Rider_Controls_InHardware_B.RateTransition_b;

  /* Update for UnitDelay: '<S70>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_n =
    Rider_Controls_InHardware_B.RateTransition_f;

  /* Update for UnitDelay: '<S71>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dt =
    Rider_Controls_InHardware_B.RateTransition_a5;

  /* Update for UnitDelay: '<S72>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dy =
    Rider_Controls_InHardware_B.RateTransition_al;

  /* Update for UnitDelay: '<S73>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_ey =
    Rider_Controls_InHardware_B.RateTransition_pj;

  /* Update for UnitDelay: '<S74>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c2 =
    Rider_Controls_InHardware_B.RateTransition_nw;

  /* Update for UnitDelay: '<S75>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_j =
    Rider_Controls_InHardware_B.RateTransition_i;

  /* Update for UnitDelay: '<S76>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_kj =
    Rider_Controls_InHardware_B.RateTransition_ov;
}

/* Model step wrapper function for compatibility with a static main program */
void Rider_Controls_InHardware_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Rider_Controls_InHardware_step0();
    break;

   case 1 :
    Rider_Controls_InHardware_step1();
    break;

   case 2 :
    Rider_Controls_InHardware_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Rider_Controls_InHardware_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Rider_Controls_InHardware_M, 0,
                sizeof(RT_MODEL_Rider_Controls_InHardw));

  /* block I/O */
  (void) memset(((void *) &Rider_Controls_InHardware_B), 0,
                sizeof(BlockIO_Rider_Controls_InHardwa));

  {
    Rider_Controls_InHardware_B.eCANReceive_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive1_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive2_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive3_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive4_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive5_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive6_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive26_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive7_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive8_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive9_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive10_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive16_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive17_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive18_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive19_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive20_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive21_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive22_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive11_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive12_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive13_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive14_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive15_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.CANUnpack_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack1_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack1_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack2_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack2_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack3_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack3_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack4_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack4_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack5_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack5_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack6_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack6_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack7_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack7_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack8_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack8_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack9_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack9_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack10_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack10_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack16_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack16_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack17_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack17_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack18_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack18_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack19_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack19_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack20_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack20_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack21_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack21_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack22_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack22_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack23_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack23_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack11_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack15_o2 = 0.0;
    Rider_Controls_InHardware_B.ADC = 0.0F;
    Rider_Controls_InHardware_B.RateTransition = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&Rider_Controls_InHardware_DWork, 0,
                sizeof(D_Work_Rider_Controls_InHardwar));
  Rider_Controls_InHardware_DWork.Delay_DSTATE = 0.0F;

  {
    int_T i;
    for (i = 0; i < 36; i++) {
      Rider_Controls_InHardware_DWork.Delay_DSTATE_o[i] = 0.0F;
    }
  }

  /* external outputs */
  (void) memset((void *)&Rider_Controls_InHardware_Y, 0,
                sizeof(ExternalOutputs_Rider_Controls_));
  Rider_Controls_InHardware_Y.Throttle = 0.0F;
  Rider_Controls_InHardware_Y.RPM = 0.0F;

  {
    int_T i;
    for (i = 0; i < 36; i++) {
      Rider_Controls_InHardware_Y.Temperatures[i] = 0.0F;
    }
  }

  /* Start for S-Function (c2802xadc): '<Root>/ADC' */
  InitAdc();
  config_ADC_SOC0 ();

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive' */
  /* Configure mailbox 0 to receive messages with the ID: 1027 */
  config_eCAN_A_mbx (0U, 0, 1027, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive_o2.ID = 1027;
    Rider_Controls_InHardware_B.eCANReceive_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive1' */
  /* Configure mailbox 1 to receive messages with the ID: 812 */
  config_eCAN_A_mbx (0U, 1, 812, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive1_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive1_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive1_o2.ID = 812;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack1 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive2' */
  /* Configure mailbox 2 to receive messages with the ID: 813 */
  config_eCAN_A_mbx (0U, 2, 813, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive2_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive2_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive2_o2.ID = 813;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack2 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive3' */
  /* Configure mailbox 3 to receive messages with the ID: 814 */
  config_eCAN_A_mbx (0U, 3, 814, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive3_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive3_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive3_o2.ID = 814;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack3 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive4' */
  /* Configure mailbox 4 to receive messages with the ID: 815 */
  config_eCAN_A_mbx (0U, 4, 815, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive4_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive4_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive4_o2.ID = 815;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack4 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive5' */
  /* Configure mailbox 5 to receive messages with the ID: 816 */
  config_eCAN_A_mbx (0U, 5, 816, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive5_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive5_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive5_o2.ID = 816;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack5 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive6' */
  /* Configure mailbox 6 to receive messages with the ID: 817 */
  config_eCAN_A_mbx (0U, 6, 817, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive6_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive6_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive6_o2.ID = 817;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack6 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive26' */
  /* Configure mailbox 7 to receive messages with the ID: 818 */
  config_eCAN_A_mbx (0U, 7, 818, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive26_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive26_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive26_o2.ID = 818;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive26_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack7 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive7' */
  /* Configure mailbox 8 to receive messages with the ID: 819 */
  config_eCAN_A_mbx (0U, 8, 819, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive7_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive7_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive7_o2.ID = 819;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack8 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive8' */
  /* Configure mailbox 9 to receive messages with the ID: 820 */
  config_eCAN_A_mbx (0U, 9, 820, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive8_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive8_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive8_o2.ID = 820;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack9 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive9' */
  /* Configure mailbox 10 to receive messages with the ID: 821 */
  config_eCAN_A_mbx (0U, 10, 821, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive9_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive9_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive9_o2.ID = 821;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack10 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive10' */
  /* Configure mailbox 11 to receive messages with the ID: 822 */
  config_eCAN_A_mbx (0U, 11, 822, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive10_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive10_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive10_o2.ID = 822;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack16 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive16' */
  /* Configure mailbox 12 to receive messages with the ID: 823 */
  config_eCAN_A_mbx (0U, 12, 823, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive16_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive16_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive16_o2.ID = 823;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive16_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack17 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive17' */
  /* Configure mailbox 13 to receive messages with the ID: 824 */
  config_eCAN_A_mbx (0U, 13, 824, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive17_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive17_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive17_o2.ID = 824;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive17_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack18 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive18' */
  /* Configure mailbox 14 to receive messages with the ID: 825 */
  config_eCAN_A_mbx (0U, 14, 825, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive18_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive18_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive18_o2.ID = 825;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive18_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack19 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive19' */
  /* Configure mailbox 15 to receive messages with the ID: 826 */
  config_eCAN_A_mbx (0U, 15, 826, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive19_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive19_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive19_o2.ID = 826;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive19_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack20 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive20' */
  /* Configure mailbox 16 to receive messages with the ID: 827 */
  config_eCAN_A_mbx (0U, 16, 827, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive20_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive20_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive20_o2.ID = 827;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive20_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack21 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive21' */
  /* Configure mailbox 17 to receive messages with the ID: 828 */
  config_eCAN_A_mbx (0U, 17, 828, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive21_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive21_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive21_o2.ID = 828;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive21_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack22 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<S1>/eCAN Receive22' */
  /* Configure mailbox 18 to receive messages with the ID: 829 */
  config_eCAN_A_mbx (0U, 18, 829, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive22_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive22_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive22_o2.ID = 829;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive22_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <S1>/CAN Unpack23 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive11' */
  /* Configure mailbox 21 to receive messages with the ID: 832 */
  config_eCAN_A_mbx (0U, 21, 832, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive11_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive11_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive11_o2.ID = 832;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack11 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive12' */
  /* Configure mailbox 22 to receive messages with the ID: 833 */
  config_eCAN_A_mbx (0U, 22, 833, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive12_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive12_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive12_o2.ID = 833;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack12 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive13' */
  /* Configure mailbox 23 to receive messages with the ID: 834 */
  config_eCAN_A_mbx (0U, 23, 834, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive13_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive13_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive13_o2.ID = 834;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack13 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive14' */
  /* Configure mailbox 24 to receive messages with the ID: 835 */
  config_eCAN_A_mbx (0U, 24, 835, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive14_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive14_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive14_o2.ID = 835;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack14 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive15' */
  /* Configure mailbox 25 to receive messages with the ID: 836 */
  config_eCAN_A_mbx (0U, 25, 836, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive15_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive15_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive15_o2.ID = 836;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack15 -----------------*/

  /* Start for S-Function (c280xgpio_di): '<Root>/Digital Input' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 4291821567U;
  GpioCtrlRegs.GPADIR.all &= 4227858431U;
  EDIS;

  /* InitializeConditions for S-Function (c280xcanrcv): '<Root>/eCAN Receive' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/Message Received6'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived6);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive1' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received4'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived4);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive2' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received1'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived1);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive3' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received2'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived2);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive4' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received3'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived3);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive5' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received5'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived5);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive6' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received6'
   */
  Rider_MessageReceived4_Init
    (&Rider_Controls_InHardware_DWork.MessageReceived6_b);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive26' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received7'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived7);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive7' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received8'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived8);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive8' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received9'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived9);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive9' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received10'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived10);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive10' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received11'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived11);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive16' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received12'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived12);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive17' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received13'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived13);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive18' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received14'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived14);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive19' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received15'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived15);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive20' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received16'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived16);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive21' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received17'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived17);

  /* InitializeConditions for S-Function (c280xcanrcv): '<S1>/eCAN Receive22' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Message Received18'
   */
  Rider_MessageReceived4_Init(&Rider_Controls_InHardware_DWork.MessageReceived18);

  /* InitializeConditions for S-Function (c280xcanrcv): '<Root>/eCAN Receive11' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/Message Received4'
   */
  Rider_MessageReceived4_Init
    (&Rider_Controls_InHardware_DWork.MessageReceived4_b);

  /* InitializeConditions for S-Function (c280xcanrcv): '<Root>/eCAN Receive12' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/Message Received3'
   */
  Rider_MessageReceived4_Init
    (&Rider_Controls_InHardware_DWork.MessageReceived3_b);

  /* InitializeConditions for S-Function (c280xcanrcv): '<Root>/eCAN Receive13' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/Message Received2'
   */
  Rider_MessageReceived4_Init
    (&Rider_Controls_InHardware_DWork.MessageReceived2_a);

  /* InitializeConditions for S-Function (c280xcanrcv): '<Root>/eCAN Receive14' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/Message Received1'
   */
  Rider_MessageReceived4_Init
    (&Rider_Controls_InHardware_DWork.MessageReceived1_c);

  /* InitializeConditions for S-Function (c280xcanrcv): '<Root>/eCAN Receive15' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/Message Received5'
   */
  Rider_MessageReceived4_Init
    (&Rider_Controls_InHardware_DWork.MessageReceived5_n);

  /* InitializeConditions for UnitDelay: '<S53>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S2>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count = 0U;

  /* InitializeConditions for UnitDelay: '<S54>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_f = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S3>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_l = 0U;

  /* InitializeConditions for UnitDelay: '<S55>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_e = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S4>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_i = 0U;

  /* InitializeConditions for UnitDelay: '<S56>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_m = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S5>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_d = 0U;

  /* InitializeConditions for UnitDelay: '<S57>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_d = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S6>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_k = 0U;

  /* InitializeConditions for UnitDelay: '<S58>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_h = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S7>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_c = 0U;

  /* InitializeConditions for UnitDelay: '<S59>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_l = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S8>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_h = 0U;

  /* InitializeConditions for UnitDelay: '<S60>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_mj = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S9>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_f = 0U;

  /* InitializeConditions for UnitDelay: '<S61>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S10>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_im = 0U;

  /* InitializeConditions for UnitDelay: '<S62>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_b = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S11>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_p = 0U;

  /* InitializeConditions for UnitDelay: '<S63>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_p = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S12>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_a = 0U;

  /* InitializeConditions for UnitDelay: '<S64>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dv = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S13>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_ls = 0U;

  /* InitializeConditions for UnitDelay: '<S65>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_cs = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S14>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_ll = 0U;

  /* InitializeConditions for UnitDelay: '<S66>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_k = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S15>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_d0 = 0U;

  /* InitializeConditions for UnitDelay: '<S67>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_g = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S16>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_hr = 0U;

  /* InitializeConditions for UnitDelay: '<S68>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c0 = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S17>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_ix = 0U;

  /* InitializeConditions for UnitDelay: '<S69>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_o = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S18>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_ce = 0U;

  /* InitializeConditions for UnitDelay: '<S70>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_n = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S19>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_e = 0U;

  /* InitializeConditions for UnitDelay: '<S71>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dt = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S20>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_ha = 0U;

  /* InitializeConditions for UnitDelay: '<S72>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_dy = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S21>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_g = 0U;

  /* InitializeConditions for UnitDelay: '<S73>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_ey = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S22>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_h1 = 0U;

  /* InitializeConditions for UnitDelay: '<S74>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_c2 = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S23>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_ks = 0U;

  /* InitializeConditions for UnitDelay: '<S75>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_j = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S24>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_ca = 0U;

  /* InitializeConditions for UnitDelay: '<S76>/Delay Input1' */
  Rider_Controls_InHardware_DWork.DelayInput1_DSTATE_kj = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S25>/Counter' */
  Rider_Controls_InHardware_DWork.Counter_Count_i1 = 0U;
}

/* Model terminate function */
void Rider_Controls_InHardware_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
