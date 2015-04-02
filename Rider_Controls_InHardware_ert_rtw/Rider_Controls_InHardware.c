/*
 * File: Rider_Controls_InHardware.c
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

  /* tid 0 shares data with slower tid rate: 2 */
  Rider_Controls_InHardware_M->Timing.RateInteraction.TID0_2 =
    (Rider_Controls_InHardware_M->Timing.TaskCounters.TID[2] == 0);

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
  if ((Rider_Controls_InHardware_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.001s, 0.0s] */
    Rider_Controls_InHardware_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Rider_Controls_InHardware_M->Timing.TaskCounters.TID[2])++;
  if ((Rider_Controls_InHardware_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [0.01s, 0.0s] */
    Rider_Controls_InHardware_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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

  /* Sum: '<S1>/Sum' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   */
  rtb_Sum = 0.0609F * Rider_Controls_InHardware_B.ADC + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE;

  /* RateTransition: '<S1>/Rate Transition' */
  if (Rider_Controls_InHardware_M->Timing.RateInteraction.TID0_2) {
    Rider_Controls_InHardware_B.RateTransition = rtb_Sum;
  }

  /* End of RateTransition: '<S1>/Rate Transition' */

  /* Update for Delay: '<S1>/Delay' */
  Rider_Controls_InHardware_DWork.Delay_DSTATE = rtb_Sum;
}

/* Model step function for TID1 */
void Rider_Controls_InHardware_step1(void) /* Sample time: [0.001s, 0.0s] */
{
  real32_T rtb_Sum;

  /* S-Function (c280xgpio_di): '<Root>/Digital Input' */
  {
    Rider_Controls_InHardware_B.DigitalInput = GpioDataRegs.GPADAT.bit.GPIO26;
  }

  /* Sum: '<S2>/Sum' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain2'
   */
  rtb_Sum = 0.0609F * Rider_Controls_InHardware_B.DigitalInput + 0.9391F *
    Rider_Controls_InHardware_DWork.Delay_DSTATE_f;

  /* RateTransition: '<S2>/Rate Transition' */
  if (Rider_Controls_InHardware_M->Timing.RateInteraction.TID1_2) {
    Rider_Controls_InHardware_B.RateTransition_l = rtb_Sum;
  }

  /* End of RateTransition: '<S2>/Rate Transition' */

  /* Update for Delay: '<S2>/Delay' */
  Rider_Controls_InHardware_DWork.Delay_DSTATE_f = rtb_Sum;
}

/* Model step function for TID2 */
void Rider_Controls_InHardware_step2(void) /* Sample time: [0.01s, 0.0s] */
{
  int32_T bitIdx;
  int16_T i;
  uint32_T intVal;
  uint16_T rtb_BittoIntegerConverter;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;

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

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack_o3 =
          Rider_Controls_InHardware_B.eCANReceive_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive1' */
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
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack1' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack1' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive1_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive1_o2.ID != INVALID_CAN_ID) ) {
      if ((812U == Rider_Controls_InHardware_B.eCANReceive1_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive1_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack1_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack1_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack1_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive1_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack1_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack1_o5 =
          Rider_Controls_InHardware_B.eCANReceive1_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive2' */
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
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack2' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack2' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive2_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive2_o2.ID != INVALID_CAN_ID) ) {
      if ((813U == Rider_Controls_InHardware_B.eCANReceive2_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive2_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack2_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack2_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack2_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive2_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack2_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack2_o5 =
          Rider_Controls_InHardware_B.eCANReceive2_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive3' */
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
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack3' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack3' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive3_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive3_o2.ID != INVALID_CAN_ID) ) {
      if ((814U == Rider_Controls_InHardware_B.eCANReceive3_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive3_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
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
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack3_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack3_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive3_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack3_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack3_o5 =
          Rider_Controls_InHardware_B.eCANReceive3_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive4' */
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
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack4' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack4' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive4_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive4_o2.ID != INVALID_CAN_ID) ) {
      if ((815U == Rider_Controls_InHardware_B.eCANReceive4_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive4_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack4_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack4_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack4_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive4_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack4_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack4_o5 =
          Rider_Controls_InHardware_B.eCANReceive4_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive5' */
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
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack5' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack5' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive5_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive5_o2.ID != INVALID_CAN_ID) ) {
      if ((816U == Rider_Controls_InHardware_B.eCANReceive5_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive5_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack5_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack5_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack5_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive5_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack5_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack5_o5 =
          Rider_Controls_InHardware_B.eCANReceive5_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive6' */
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
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack6' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack6' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive6_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive6_o2.ID != INVALID_CAN_ID) ) {
      if ((817U == Rider_Controls_InHardware_B.eCANReceive6_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive6_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack6_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack6_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack6_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive6_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack6_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack6_o5 =
          Rider_Controls_InHardware_B.eCANReceive6_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive7' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP7) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP7 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Length =
        ECanaMboxes.MBOX7.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive7_o2.ID = 818;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3] =
        ECanaMboxes.MBOX7.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2] =
        ECanaMboxes.MBOX7.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1] =
        ECanaMboxes.MBOX7.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0] =
        ECanaMboxes.MBOX7.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7] =
        ECanaMboxes.MBOX7.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6] =
        ECanaMboxes.MBOX7.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5] =
        ECanaMboxes.MBOX7.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4] =
        ECanaMboxes.MBOX7.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack7' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack7' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive7_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive7_o2.ID != INVALID_CAN_ID) ) {
      if ((818U == Rider_Controls_InHardware_B.eCANReceive7_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive7_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack7_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack7_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack7_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack7_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack7_o5 =
          Rider_Controls_InHardware_B.eCANReceive7_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive8' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP8) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP8 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Length =
        ECanaMboxes.MBOX8.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive8_o2.ID = 819;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3] =
        ECanaMboxes.MBOX8.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2] =
        ECanaMboxes.MBOX8.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1] =
        ECanaMboxes.MBOX8.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0] =
        ECanaMboxes.MBOX8.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7] =
        ECanaMboxes.MBOX8.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6] =
        ECanaMboxes.MBOX8.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5] =
        ECanaMboxes.MBOX8.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4] =
        ECanaMboxes.MBOX8.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack8' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack8' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive8_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive8_o2.ID != INVALID_CAN_ID) ) {
      if ((819U == Rider_Controls_InHardware_B.eCANReceive8_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive8_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack8_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack8_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack8_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack8_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack8_o5 =
          Rider_Controls_InHardware_B.eCANReceive8_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive9' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP9) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP9 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Length =
        ECanaMboxes.MBOX9.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive9_o2.ID = 820;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3] =
        ECanaMboxes.MBOX9.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2] =
        ECanaMboxes.MBOX9.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1] =
        ECanaMboxes.MBOX9.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0] =
        ECanaMboxes.MBOX9.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7] =
        ECanaMboxes.MBOX9.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6] =
        ECanaMboxes.MBOX9.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5] =
        ECanaMboxes.MBOX9.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4] =
        ECanaMboxes.MBOX9.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack9' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack9' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive9_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive9_o2.ID != INVALID_CAN_ID) ) {
      if ((820U == Rider_Controls_InHardware_B.eCANReceive9_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive9_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack9_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack9_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack9_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7]) &
                         (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack9_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack9_o5 =
          Rider_Controls_InHardware_B.eCANReceive9_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive10' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP10) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP10 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Length =
        ECanaMboxes.MBOX10.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive10_o2.ID = 821;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack10' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack10' */
    if ((8 == Rider_Controls_InHardware_B.eCANReceive10_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive10_o2.ID != INVALID_CAN_ID) ) {
      if ((821U == Rider_Controls_InHardware_B.eCANReceive10_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive10_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0])
                         & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1])
                         & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack10_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2])
                         & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3])
                         & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack10_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4])
                         & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5])
                         & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack10_o3 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 16
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6])
                         & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                        ((Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7])
                         & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack10_o4 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack10_o5 =
          Rider_Controls_InHardware_B.eCANReceive10_o2.Timestamp;
      }
    }
  }

  /* Outport: '<Root>/Temperatures' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   *  DataTypeConversion: '<Root>/Data Type Conversion11'
   *  DataTypeConversion: '<Root>/Data Type Conversion12'
   *  DataTypeConversion: '<Root>/Data Type Conversion13'
   *  DataTypeConversion: '<Root>/Data Type Conversion14'
   *  DataTypeConversion: '<Root>/Data Type Conversion15'
   *  DataTypeConversion: '<Root>/Data Type Conversion16'
   *  DataTypeConversion: '<Root>/Data Type Conversion17'
   *  DataTypeConversion: '<Root>/Data Type Conversion18'
   *  DataTypeConversion: '<Root>/Data Type Conversion19'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion20'
   *  DataTypeConversion: '<Root>/Data Type Conversion21'
   *  DataTypeConversion: '<Root>/Data Type Conversion22'
   *  DataTypeConversion: '<Root>/Data Type Conversion23'
   *  DataTypeConversion: '<Root>/Data Type Conversion24'
   *  DataTypeConversion: '<Root>/Data Type Conversion25'
   *  DataTypeConversion: '<Root>/Data Type Conversion26'
   *  DataTypeConversion: '<Root>/Data Type Conversion27'
   *  DataTypeConversion: '<Root>/Data Type Conversion28'
   *  DataTypeConversion: '<Root>/Data Type Conversion29'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  DataTypeConversion: '<Root>/Data Type Conversion30'
   *  DataTypeConversion: '<Root>/Data Type Conversion31'
   *  DataTypeConversion: '<Root>/Data Type Conversion32'
   *  DataTypeConversion: '<Root>/Data Type Conversion33'
   *  DataTypeConversion: '<Root>/Data Type Conversion34'
   *  DataTypeConversion: '<Root>/Data Type Conversion35'
   *  DataTypeConversion: '<Root>/Data Type Conversion36'
   *  DataTypeConversion: '<Root>/Data Type Conversion37'
   *  DataTypeConversion: '<Root>/Data Type Conversion38'
   *  DataTypeConversion: '<Root>/Data Type Conversion39'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   *  Gain: '<Root>/Conversion to celcius'
   */
  Rider_Controls_InHardware_Y.Temperatures[0] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack1_o1;
  Rider_Controls_InHardware_Y.Temperatures[1] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack1_o2;
  Rider_Controls_InHardware_Y.Temperatures[2] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack1_o3;
  Rider_Controls_InHardware_Y.Temperatures[3] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack1_o4;
  Rider_Controls_InHardware_Y.Temperatures[4] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack2_o1;
  Rider_Controls_InHardware_Y.Temperatures[5] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack2_o2;
  Rider_Controls_InHardware_Y.Temperatures[6] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack2_o3;
  Rider_Controls_InHardware_Y.Temperatures[7] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack2_o4;
  Rider_Controls_InHardware_Y.Temperatures[8] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack3_o1;
  Rider_Controls_InHardware_Y.Temperatures[9] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack3_o2;
  Rider_Controls_InHardware_Y.Temperatures[10] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack3_o3;
  Rider_Controls_InHardware_Y.Temperatures[11] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack3_o4;
  Rider_Controls_InHardware_Y.Temperatures[12] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack4_o1;
  Rider_Controls_InHardware_Y.Temperatures[13] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack4_o2;
  Rider_Controls_InHardware_Y.Temperatures[14] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack4_o3;
  Rider_Controls_InHardware_Y.Temperatures[15] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack4_o4;
  Rider_Controls_InHardware_Y.Temperatures[16] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack5_o1;
  Rider_Controls_InHardware_Y.Temperatures[17] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack5_o2;
  Rider_Controls_InHardware_Y.Temperatures[18] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack5_o3;
  Rider_Controls_InHardware_Y.Temperatures[19] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack5_o4;
  Rider_Controls_InHardware_Y.Temperatures[20] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack6_o1;
  Rider_Controls_InHardware_Y.Temperatures[21] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack6_o2;
  Rider_Controls_InHardware_Y.Temperatures[22] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack6_o3;
  Rider_Controls_InHardware_Y.Temperatures[23] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack6_o4;
  Rider_Controls_InHardware_Y.Temperatures[24] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack7_o1;
  Rider_Controls_InHardware_Y.Temperatures[25] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack7_o2;
  Rider_Controls_InHardware_Y.Temperatures[26] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack7_o3;
  Rider_Controls_InHardware_Y.Temperatures[27] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack7_o4;
  Rider_Controls_InHardware_Y.Temperatures[28] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack8_o1;
  Rider_Controls_InHardware_Y.Temperatures[29] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack8_o2;
  Rider_Controls_InHardware_Y.Temperatures[30] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack8_o3;
  Rider_Controls_InHardware_Y.Temperatures[31] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack8_o4;
  Rider_Controls_InHardware_Y.Temperatures[32] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack9_o1;
  Rider_Controls_InHardware_Y.Temperatures[33] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack9_o2;
  Rider_Controls_InHardware_Y.Temperatures[34] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack9_o3;
  Rider_Controls_InHardware_Y.Temperatures[35] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack9_o4;
  Rider_Controls_InHardware_Y.Temperatures[36] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack10_o1;
  Rider_Controls_InHardware_Y.Temperatures[37] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack10_o2;
  Rider_Controls_InHardware_Y.Temperatures[38] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack10_o3;
  Rider_Controls_InHardware_Y.Temperatures[39] = 0.001F * (real32_T)
    Rider_Controls_InHardware_B.CANUnpack10_o4;

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive11' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP11) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP11 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Length =
        ECanaMboxes.MBOX11.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive11_o2.ID = 823;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3] =
        ECanaMboxes.MBOX11.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2] =
        ECanaMboxes.MBOX11.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1] =
        ECanaMboxes.MBOX11.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0] =
        ECanaMboxes.MBOX11.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[7] =
        ECanaMboxes.MBOX11.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[6] =
        ECanaMboxes.MBOX11.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5] =
        ECanaMboxes.MBOX11.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4] =
        ECanaMboxes.MBOX11.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack11' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack11' */
    if ((6 == Rider_Controls_InHardware_B.eCANReceive11_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive11_o2.ID != INVALID_CAN_ID) ) {
      if ((823U == Rider_Controls_InHardware_B.eCANReceive11_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive11_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack11_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack11_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive11_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack11_o3 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack11_o4 =
          Rider_Controls_InHardware_B.eCANReceive11_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive12' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP12) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP12 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Length =
        ECanaMboxes.MBOX12.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive12_o2.ID = 824;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3] =
        ECanaMboxes.MBOX12.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2] =
        ECanaMboxes.MBOX12.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1] =
        ECanaMboxes.MBOX12.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0] =
        ECanaMboxes.MBOX12.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[7] =
        ECanaMboxes.MBOX12.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[6] =
        ECanaMboxes.MBOX12.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5] =
        ECanaMboxes.MBOX12.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4] =
        ECanaMboxes.MBOX12.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack12' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack12' */
    if ((6 == Rider_Controls_InHardware_B.eCANReceive12_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive12_o2.ID != INVALID_CAN_ID) ) {
      if ((824U == Rider_Controls_InHardware_B.eCANReceive12_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive12_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack12_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack12_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive12_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack12_o3 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack12_o4 =
          Rider_Controls_InHardware_B.eCANReceive12_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive13' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP13) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP13 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Length =
        ECanaMboxes.MBOX13.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive13_o2.ID = 825;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3] =
        ECanaMboxes.MBOX13.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2] =
        ECanaMboxes.MBOX13.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1] =
        ECanaMboxes.MBOX13.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0] =
        ECanaMboxes.MBOX13.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[7] =
        ECanaMboxes.MBOX13.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[6] =
        ECanaMboxes.MBOX13.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5] =
        ECanaMboxes.MBOX13.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4] =
        ECanaMboxes.MBOX13.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack13' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack13' */
    if ((6 == Rider_Controls_InHardware_B.eCANReceive13_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive13_o2.ID != INVALID_CAN_ID) ) {
      if ((825U == Rider_Controls_InHardware_B.eCANReceive13_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive13_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack13_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack13_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive13_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack13_o3 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack13_o4 =
          Rider_Controls_InHardware_B.eCANReceive13_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive14' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP14) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP14 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Length =
        ECanaMboxes.MBOX14.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive14_o2.ID = 826;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3] =
        ECanaMboxes.MBOX14.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2] =
        ECanaMboxes.MBOX14.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1] =
        ECanaMboxes.MBOX14.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0] =
        ECanaMboxes.MBOX14.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[7] =
        ECanaMboxes.MBOX14.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[6] =
        ECanaMboxes.MBOX14.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5] =
        ECanaMboxes.MBOX14.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4] =
        ECanaMboxes.MBOX14.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack14' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack14' */
    if ((6 == Rider_Controls_InHardware_B.eCANReceive14_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive14_o2.ID != INVALID_CAN_ID) ) {
      if ((826U == Rider_Controls_InHardware_B.eCANReceive14_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive14_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack14_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack14_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive14_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack14_o3 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack14_o4 =
          Rider_Controls_InHardware_B.eCANReceive14_o2.Timestamp;
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive15' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP15) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP15 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Extended = 0;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Length =
        ECanaMboxes.MBOX15.MSGCTRL.bit.DLC;
      Rider_Controls_InHardware_B.eCANReceive15_o2.ID = 827;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3] =
        ECanaMboxes.MBOX15.MDL.byte.BYTE0;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2] =
        ECanaMboxes.MBOX15.MDL.byte.BYTE1;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1] =
        ECanaMboxes.MBOX15.MDL.byte.BYTE2;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0] =
        ECanaMboxes.MBOX15.MDL.byte.BYTE3;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[7] =
        ECanaMboxes.MBOX15.MDH.byte.BYTE4;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[6] =
        ECanaMboxes.MBOX15.MDH.byte.BYTE5;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5] =
        ECanaMboxes.MBOX15.MDH.byte.BYTE6;
      Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4] =
        ECanaMboxes.MBOX15.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack15' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack15' */
    if ((6 == Rider_Controls_InHardware_B.eCANReceive15_o2.Length) &&
        (Rider_Controls_InHardware_B.eCANReceive15_o2.ID != INVALID_CAN_ID) ) {
      if ((827U == Rider_Controls_InHardware_B.eCANReceive15_o2.ID) && (0U ==
           Rider_Controls_InHardware_B.eCANReceive15_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[4])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack15_o1 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[5])
                         & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack15_o2 = result;
              }
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            {
              real64_T outValue = 0;

              {
                {
                  uint32_T unpackedValue = 0;

                  {
                    uint32_T tempValue = (uint32_T) (0);

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_InHardware_B.eCANReceive15_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_InHardware_B.CANUnpack15_o3 = result;
              }
            }
          }
        }

        /* Extract the Timestamp */
        Rider_Controls_InHardware_B.CANUnpack15_o4 =
          Rider_Controls_InHardware_B.eCANReceive15_o2.Timestamp;
      }
    }
  }

  /* DigitalClock: '<Root>/Digital Clock' */
  Rider_Controls_InHardware_B.Subtract =
    (((Rider_Controls_InHardware_M->Timing.clockTick2+
       Rider_Controls_InHardware_M->Timing.clockTickH2* 4294967296.0)) * 0.01);

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Rider_Controls_InHardware_B.Subtract -= 2.0;

  /* RelationalOperator: '<Root>/Relational Operator' */
  Rider_Controls_InHardware_B.RelationalOperator[0] =
    (Rider_Controls_InHardware_B.CANUnpack11_o4 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[1] =
    (Rider_Controls_InHardware_B.CANUnpack12_o4 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[2] =
    (Rider_Controls_InHardware_B.CANUnpack13_o4 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[3] =
    (Rider_Controls_InHardware_B.CANUnpack14_o4 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[4] =
    (Rider_Controls_InHardware_B.CANUnpack15_o4 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[5] =
    (Rider_Controls_InHardware_B.CANUnpack1_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[6] =
    (Rider_Controls_InHardware_B.CANUnpack2_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[7] =
    (Rider_Controls_InHardware_B.CANUnpack3_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[8] =
    (Rider_Controls_InHardware_B.CANUnpack4_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[9] =
    (Rider_Controls_InHardware_B.CANUnpack5_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[10] =
    (Rider_Controls_InHardware_B.CANUnpack6_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[11] =
    (Rider_Controls_InHardware_B.CANUnpack7_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[12] =
    (Rider_Controls_InHardware_B.CANUnpack8_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[13] =
    (Rider_Controls_InHardware_B.CANUnpack9_o5 <
     Rider_Controls_InHardware_B.Subtract);
  Rider_Controls_InHardware_B.RelationalOperator[14] =
    (Rider_Controls_InHardware_B.CANUnpack10_o5 <
     Rider_Controls_InHardware_B.Subtract);

  /* S-Function (scominttobit): '<Root>/Bit to Integer Converter' */
  /* Bit to Integer Conversion */
  bitIdx = 0L;
  i = 0;
  while (i < 1) {
    intVal = 0UL;
    for (i = 0; i < 15; i++) {
      /* Input bit order is MSB first */
      intVal <<= 1UL;
      intVal |= Rider_Controls_InHardware_B.RelationalOperator[bitIdx];
      bitIdx++;
    }

    rtb_BittoIntegerConverter = (uint16_T)intVal;
    i = 1;
  }

  /* End of S-Function (scominttobit): '<Root>/Bit to Integer Converter' */

  /* DataTypeConversion: '<Root>/Data Type Conversion41' */
  Rider_Controls_InHardware_B.Subtract = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack11_o1);
  if (rtIsNaN(Rider_Controls_InHardware_B.Subtract) || rtIsInf
      (Rider_Controls_InHardware_B.Subtract)) {
    Rider_Controls_InHardware_B.Subtract = 0.0;
  } else {
    Rider_Controls_InHardware_B.Subtract = fmod
      (Rider_Controls_InHardware_B.Subtract, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion42' */
  Rider_Controls_InHardware_B.d0 = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack11_o2);
  if (rtIsNaN(Rider_Controls_InHardware_B.d0) || rtIsInf
      (Rider_Controls_InHardware_B.d0)) {
    Rider_Controls_InHardware_B.d0 = 0.0;
  } else {
    Rider_Controls_InHardware_B.d0 = fmod(Rider_Controls_InHardware_B.d0,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion43' */
  Rider_Controls_InHardware_B.d1 = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack11_o3);
  if (rtIsNaN(Rider_Controls_InHardware_B.d1) || rtIsInf
      (Rider_Controls_InHardware_B.d1)) {
    Rider_Controls_InHardware_B.d1 = 0.0;
  } else {
    Rider_Controls_InHardware_B.d1 = fmod(Rider_Controls_InHardware_B.d1,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion44' */
  Rider_Controls_InHardware_B.d2 = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack12_o1);
  if (rtIsNaN(Rider_Controls_InHardware_B.d2) || rtIsInf
      (Rider_Controls_InHardware_B.d2)) {
    Rider_Controls_InHardware_B.d2 = 0.0;
  } else {
    Rider_Controls_InHardware_B.d2 = fmod(Rider_Controls_InHardware_B.d2,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion45' */
  Rider_Controls_InHardware_B.d3 = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack12_o2);
  if (rtIsNaN(Rider_Controls_InHardware_B.d3) || rtIsInf
      (Rider_Controls_InHardware_B.d3)) {
    Rider_Controls_InHardware_B.d3 = 0.0;
  } else {
    Rider_Controls_InHardware_B.d3 = fmod(Rider_Controls_InHardware_B.d3,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion46' */
  Rider_Controls_InHardware_B.d4 = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack12_o3);
  if (rtIsNaN(Rider_Controls_InHardware_B.d4) || rtIsInf
      (Rider_Controls_InHardware_B.d4)) {
    Rider_Controls_InHardware_B.d4 = 0.0;
  } else {
    Rider_Controls_InHardware_B.d4 = fmod(Rider_Controls_InHardware_B.d4,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion47' */
  Rider_Controls_InHardware_B.d5 = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack13_o1);
  if (rtIsNaN(Rider_Controls_InHardware_B.d5) || rtIsInf
      (Rider_Controls_InHardware_B.d5)) {
    Rider_Controls_InHardware_B.d5 = 0.0;
  } else {
    Rider_Controls_InHardware_B.d5 = fmod(Rider_Controls_InHardware_B.d5,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion48' */
  Rider_Controls_InHardware_B.d6 = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack13_o2);
  if (rtIsNaN(Rider_Controls_InHardware_B.d6) || rtIsInf
      (Rider_Controls_InHardware_B.d6)) {
    Rider_Controls_InHardware_B.d6 = 0.0;
  } else {
    Rider_Controls_InHardware_B.d6 = fmod(Rider_Controls_InHardware_B.d6,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion49' */
  Rider_Controls_InHardware_B.d7 = rt_roundd_snf
    (Rider_Controls_InHardware_B.CANUnpack13_o3);
  if (rtIsNaN(Rider_Controls_InHardware_B.d7) || rtIsInf
      (Rider_Controls_InHardware_B.d7)) {
    Rider_Controls_InHardware_B.d7 = 0.0;
  } else {
    Rider_Controls_InHardware_B.d7 = fmod(Rider_Controls_InHardware_B.d7,
      65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion50' */
  tmp = rt_roundd_snf(Rider_Controls_InHardware_B.CANUnpack14_o1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion51' */
  tmp_0 = rt_roundd_snf(Rider_Controls_InHardware_B.CANUnpack14_o2);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion52' */
  tmp_1 = rt_roundd_snf(Rider_Controls_InHardware_B.CANUnpack14_o3);
  if (rtIsNaN(tmp_1) || rtIsInf(tmp_1)) {
    tmp_1 = 0.0;
  } else {
    tmp_1 = fmod(tmp_1, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion53' */
  tmp_2 = rt_roundd_snf(Rider_Controls_InHardware_B.CANUnpack15_o1);
  if (rtIsNaN(tmp_2) || rtIsInf(tmp_2)) {
    tmp_2 = 0.0;
  } else {
    tmp_2 = fmod(tmp_2, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion54' */
  tmp_3 = rt_roundd_snf(Rider_Controls_InHardware_B.CANUnpack15_o2);
  if (rtIsNaN(tmp_3) || rtIsInf(tmp_3)) {
    tmp_3 = 0.0;
  } else {
    tmp_3 = fmod(tmp_3, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion55' */
  tmp_4 = rt_roundd_snf(Rider_Controls_InHardware_B.CANUnpack15_o3);
  if (rtIsNaN(tmp_4) || rtIsInf(tmp_4)) {
    tmp_4 = 0.0;
  } else {
    tmp_4 = fmod(tmp_4, 65536.0);
  }

  /* Outport: '<Root>/BIM Status' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion41'
   *  DataTypeConversion: '<Root>/Data Type Conversion42'
   *  DataTypeConversion: '<Root>/Data Type Conversion43'
   *  DataTypeConversion: '<Root>/Data Type Conversion44'
   *  DataTypeConversion: '<Root>/Data Type Conversion45'
   *  DataTypeConversion: '<Root>/Data Type Conversion46'
   *  DataTypeConversion: '<Root>/Data Type Conversion47'
   *  DataTypeConversion: '<Root>/Data Type Conversion48'
   *  DataTypeConversion: '<Root>/Data Type Conversion49'
   *  DataTypeConversion: '<Root>/Data Type Conversion50'
   *  DataTypeConversion: '<Root>/Data Type Conversion51'
   *  DataTypeConversion: '<Root>/Data Type Conversion52'
   *  DataTypeConversion: '<Root>/Data Type Conversion53'
   *  DataTypeConversion: '<Root>/Data Type Conversion54'
   *  DataTypeConversion: '<Root>/Data Type Conversion55'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator'
   */
  Rider_Controls_InHardware_Y.BIMStatus = (Rider_Controls_InHardware_B.Subtract <
    0.0 ? (uint16_T)-(int16_T)(uint16_T)-Rider_Controls_InHardware_B.Subtract :
    (uint16_T)Rider_Controls_InHardware_B.Subtract) |
    (Rider_Controls_InHardware_B.d0 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)
     -Rider_Controls_InHardware_B.d0 : (uint16_T)Rider_Controls_InHardware_B.d0)
    | (Rider_Controls_InHardware_B.d1 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)
       -Rider_Controls_InHardware_B.d1 : (uint16_T)
       Rider_Controls_InHardware_B.d1) | (Rider_Controls_InHardware_B.d2 < 0.0 ?
    (uint16_T)-(int16_T)(uint16_T)-Rider_Controls_InHardware_B.d2 : (uint16_T)
    Rider_Controls_InHardware_B.d2) | (Rider_Controls_InHardware_B.d3 < 0.0 ?
    (uint16_T)-(int16_T)(uint16_T)-Rider_Controls_InHardware_B.d3 : (uint16_T)
    Rider_Controls_InHardware_B.d3) | (Rider_Controls_InHardware_B.d4 < 0.0 ?
    (uint16_T)-(int16_T)(uint16_T)-Rider_Controls_InHardware_B.d4 : (uint16_T)
    Rider_Controls_InHardware_B.d4) | (Rider_Controls_InHardware_B.d5 < 0.0 ?
    (uint16_T)-(int16_T)(uint16_T)-Rider_Controls_InHardware_B.d5 : (uint16_T)
    Rider_Controls_InHardware_B.d5) | (Rider_Controls_InHardware_B.d6 < 0.0 ?
    (uint16_T)-(int16_T)(uint16_T)-Rider_Controls_InHardware_B.d6 : (uint16_T)
    Rider_Controls_InHardware_B.d6) | (Rider_Controls_InHardware_B.d7 < 0.0 ?
    (uint16_T)-(int16_T)(uint16_T)-Rider_Controls_InHardware_B.d7 : (uint16_T)
    Rider_Controls_InHardware_B.d7) | (tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)
    -tmp : (uint16_T)tmp) | (tmp_0 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp_0 :
                             (uint16_T)tmp_0) | (tmp_1 < 0.0 ? (uint16_T)
    -(int16_T)(uint16_T)-tmp_1 : (uint16_T)tmp_1) | (tmp_2 < 0.0 ? (uint16_T)
    -(int16_T)(uint16_T)-tmp_2 : (uint16_T)tmp_2) | (tmp_3 < 0.0 ? (uint16_T)
    -(int16_T)(uint16_T)-tmp_3 : (uint16_T)tmp_3) | (tmp_4 < 0.0 ? (uint16_T)
    -(int16_T)(uint16_T)-tmp_4 : (uint16_T)tmp_4) | rtb_BittoIntegerConverter;

  /* Outport: '<Root>/E-Stop' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion40'
   */
  Rider_Controls_InHardware_Y.EStop =
    (Rider_Controls_InHardware_B.RateTransition_l != 0.0F);

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  Rider_Controls_InHardware_M->Timing.clockTick2++;
  if (!Rider_Controls_InHardware_M->Timing.clockTick2) {
    Rider_Controls_InHardware_M->Timing.clockTickH2++;
  }
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

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Rider_Controls_InHardware_M, 0,
                sizeof(RT_MODEL_Rider_Controls_InHardw));

  /* block I/O */
  {
    Rider_Controls_InHardware_B.eCANReceive_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive1_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive2_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive3_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive4_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive5_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive6_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive7_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive8_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive9_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive10_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive11_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive12_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive13_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive14_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.eCANReceive15_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_B.CANUnpack_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack1_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack1_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack1_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack1_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack1_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack2_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack2_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack2_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack2_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack2_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack3_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack3_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack3_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack3_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack3_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack4_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack4_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack4_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack4_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack4_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack5_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack5_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack5_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack5_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack5_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack6_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack6_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack6_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack6_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack6_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack7_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack7_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack7_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack7_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack7_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack8_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack8_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack8_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack8_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack8_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack9_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack9_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack9_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack9_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack9_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack10_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack10_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack10_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack10_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack10_o5 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack11_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack11_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack11_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack11_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack12_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack12_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack12_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack12_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack13_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack13_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack13_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack13_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack14_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack14_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack14_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack14_o4 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack15_o1 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack15_o2 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack15_o3 = 0.0;
    Rider_Controls_InHardware_B.CANUnpack15_o4 = 0.0;
    Rider_Controls_InHardware_B.ADC = 0.0F;
    Rider_Controls_InHardware_B.RateTransition = 0.0F;
    Rider_Controls_InHardware_B.DigitalInput = 0.0F;
    Rider_Controls_InHardware_B.RateTransition_l = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&Rider_Controls_InHardware_DWork, 0,
                sizeof(D_Work_Rider_Controls_InHardwar));
  Rider_Controls_InHardware_DWork.Delay_DSTATE = 0.0F;
  Rider_Controls_InHardware_DWork.Delay_DSTATE_f = 0.0F;

  /* external outputs */
  (void) memset((void *)&Rider_Controls_InHardware_Y, 0,
                sizeof(ExternalOutputs_Rider_Controls_));
  Rider_Controls_InHardware_Y.Throttle = 0.0F;
  Rider_Controls_InHardware_Y.RPM = 0.0F;

  {
    int_T i;
    for (i = 0; i < 40; i++) {
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

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive1' */
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

  /*-----------S-Function Block: <Root>/CAN Unpack1 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive2' */
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

  /*-----------S-Function Block: <Root>/CAN Unpack2 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive3' */
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

  /*-----------S-Function Block: <Root>/CAN Unpack3 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive4' */
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

  /*-----------S-Function Block: <Root>/CAN Unpack4 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive5' */
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

  /*-----------S-Function Block: <Root>/CAN Unpack5 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive6' */
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

  /*-----------S-Function Block: <Root>/CAN Unpack6 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive7' */
  /* Configure mailbox 7 to receive messages with the ID: 818 */
  config_eCAN_A_mbx (0U, 7, 818, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive7_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive7_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive7_o2.ID = 818;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive7_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack7 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive8' */
  /* Configure mailbox 8 to receive messages with the ID: 819 */
  config_eCAN_A_mbx (0U, 8, 819, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive8_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive8_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive8_o2.ID = 819;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive8_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack8 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive9' */
  /* Configure mailbox 9 to receive messages with the ID: 820 */
  config_eCAN_A_mbx (0U, 9, 820, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive9_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive9_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive9_o2.ID = 820;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive9_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack9 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive10' */
  /* Configure mailbox 10 to receive messages with the ID: 821 */
  config_eCAN_A_mbx (0U, 10, 821, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive10_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive10_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive10_o2.ID = 821;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_InHardware_B.eCANReceive10_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack10 -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive11' */
  /* Configure mailbox 11 to receive messages with the ID: 823 */
  config_eCAN_A_mbx (0U, 11, 823, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive11_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive11_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive11_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive11_o2.ID = 823;
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
  /* Configure mailbox 12 to receive messages with the ID: 824 */
  config_eCAN_A_mbx (0U, 12, 824, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive12_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive12_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive12_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive12_o2.ID = 824;
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
  /* Configure mailbox 13 to receive messages with the ID: 825 */
  config_eCAN_A_mbx (0U, 13, 825, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive13_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive13_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive13_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive13_o2.ID = 825;
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
  /* Configure mailbox 14 to receive messages with the ID: 826 */
  config_eCAN_A_mbx (0U, 14, 826, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive14_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive14_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive14_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive14_o2.ID = 826;
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
  /* Configure mailbox 15 to receive messages with the ID: 827 */
  config_eCAN_A_mbx (0U, 15, 827, 0);

  /* Initialize Rider_Controls_InHardware_B.eCANReceive15_o2 */
  {
    Rider_Controls_InHardware_B.eCANReceive15_o2.Extended = 0;
    Rider_Controls_InHardware_B.eCANReceive15_o2.Length = 8;
    Rider_Controls_InHardware_B.eCANReceive15_o2.ID = 827;
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
