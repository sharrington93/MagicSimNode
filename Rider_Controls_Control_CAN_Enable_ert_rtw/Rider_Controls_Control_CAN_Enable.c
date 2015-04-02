/*
 * File: Rider_Controls_Control_CAN_Enable.c
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

#include "Rider_Controls_Control_CAN_Enable.h"
#include "Rider_Controls_Control_CAN_Enable_private.h"

rtTimingBridge Rider_Controls_C_TimingBridge_k;
const boolean_T Rider_Controls_Control_CAN_Enable_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
BlockIO_Rider_Controls_Control_ Rider_Controls_Control_CAN_En_B;

/* Block states (auto storage) */
D_Work_Rider_Controls_Control_C Rider_Controls_Control_CA_DWork;

/* Real-time model */
RT_MODEL_Rider_Controls_Contr_d Rider_Controls_Control_CAN_E_M_;
RT_MODEL_Rider_Controls_Contr_d *const Rider_Controls_Control_CAN_E_M =
  &Rider_Controls_Control_CAN_E_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Rider_Controls_Control_CAN_Enable_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Rider_Controls_Control_CAN_E_M, 1));
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
  Rider_Controls_Control_CAN_E_M->Timing.RateInteraction.TID0_1 =
    (Rider_Controls_Control_CAN_E_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Rider_Controls_Control_CAN_E_M->Timing.TaskCounters.TID[1])++;
  if ((Rider_Controls_Control_CAN_E_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [1.0s, 0.0s] */
    Rider_Controls_Control_CAN_E_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Rider_Controls_Control_CAN_Enable_step0(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_DataTypeConversion;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

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
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Extended = 0;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Length =
        ECanaMboxes.MBOX0.MSGCTRL.bit.DLC;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.ID = 0;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3] =
        ECanaMboxes.MBOX0.MDL.byte.BYTE0;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2] =
        ECanaMboxes.MBOX0.MDL.byte.BYTE1;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1] =
        ECanaMboxes.MBOX0.MDL.byte.BYTE2;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0] =
        ECanaMboxes.MBOX0.MDL.byte.BYTE3;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7] =
        ECanaMboxes.MBOX0.MDH.byte.BYTE4;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6] =
        ECanaMboxes.MBOX0.MDH.byte.BYTE5;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5] =
        ECanaMboxes.MBOX0.MDH.byte.BYTE6;
      Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4] =
        ECanaMboxes.MBOX0.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack' */
    if ((8 == Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Length) &&
        (Rider_Controls_Control_CAN_En_B.eCANReceive_o2.ID != INVALID_CAN_ID) )
    {
      if ((0U == Rider_Controls_Control_CAN_En_B.eCANReceive_o2.ID) && (0U ==
           Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Extended) ) {
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
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
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
                Rider_Controls_Control_CAN_En_B.CANUnpack_o1 = result;
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
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
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
                Rider_Controls_Control_CAN_En_B.CANUnpack_o2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive2' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP10) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP10 = 1;/* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Extended = 0;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Length =
        ECanaMboxes.MBOX10.MSGCTRL.bit.DLC;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.ID = 4;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE0;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE1;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE2;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0] =
        ECanaMboxes.MBOX10.MDL.byte.BYTE3;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[7] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE4;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[6] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE5;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[5] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE6;
      Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[4] =
        ECanaMboxes.MBOX10.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack2' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack2' */
    if ((8 == Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Length) &&
        (Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.ID != INVALID_CAN_ID) )
    {
      if ((4U == Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.ID) && (0U ==
           Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
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
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<0);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<1);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<2);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<3);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<4);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<5);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<6);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<7);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<8);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<9);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<10);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<11);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<12);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<13);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<14);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<15);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<16);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<17);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<18);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<19);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<20);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<21);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<22);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<23);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<24);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<25);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<26);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<27);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<28);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<29);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<30);
                    }

                    {
                      tempValue = tempValue | (uint32_T)((uint32_T)((uint32_T)
                        ((Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3])
                         & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<31);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }
              }

              {
                real64_T result = (real64_T) outValue;
                Rider_Controls_Control_CAN_En_B.CANUnpack2 = result;
              }
            }
          }
        }
      }
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_DataTypeConversion = (Rider_Controls_Control_CAN_En_B.CANUnpack2 != 0.0);

  /* ModelReference: '<Root>/Software' */
  Rider_Controls_ControlTID0(&Rider_Controls_Control_CAN_En_B.CANUnpack_o2,
    &Rider_Controls_Control_CAN_En_B.CANUnpack_o1, rtCP_Constant_Value,
    &rtb_DataTypeConversion, (boolean_T*)&Rider_Controls_Control_CAN_Enable_BGND,
    &Rider_Controls_Control_CAN_En_B.Software_o1,
    &Rider_Controls_Control_CAN_En_B.Software_o2,
    &Rider_Controls_Control_CAN_En_B.Software_o3,
    &Rider_Controls_Control_CAN_En_B.Software_o4,
    &Rider_Controls_Control_CAN_En_B.Software_o5,
    &Rider_Controls_Control_CAN_En_B.Software_o6,
    &Rider_Controls_Control_CAN_En_B.Software_o7);

  /* S-Function (scanpack): '<Root>/CAN Pack' */
  Rider_Controls_Control_CAN_En_B.CANPack.ID = 1U;
  Rider_Controls_Control_CAN_En_B.CANPack.Length = 8U;
  Rider_Controls_Control_CAN_En_B.CANPack.Extended = 0U;
  Rider_Controls_Control_CAN_En_B.CANPack.Remote = 0;
  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 32
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SINGLE
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = -10000.0
     *  maximum                 = 10000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = Rider_Controls_Control_CAN_En_B.Software_o2;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            real32_T typedValue;
            uint32_T* pInput;
            uint32_T typedIntValue;
            typedValue = (real32_T) (outValue);
            pInput = (uint32_T*) (&typedValue);
            typedIntValue = *pInput;

            {
              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[4] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[4] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[4] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[4] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[4] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[4] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[4] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[4] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[5] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[5] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[5] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[5] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[5] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[5] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[5] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[5] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 15)) >> 15)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[6] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 16)) >> 16)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[6] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 17)) >> 17)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[6] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 18)) >> 18)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[6] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 19)) >> 19)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[6] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 20)) >> 20)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[6] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 21)) >> 21)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[6] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 22)) >> 22)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[6] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 23)) >> 23)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[7] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 24)) >> 24)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[7] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 25)) >> 25)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[7] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 26)) >> 26)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[7] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 27)) >> 27)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[7] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 28)) >> 28)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[7] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 29)) >> 29)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[7] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 30)) >> 30)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[7] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 31)) >> 31)<<7);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 0
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SINGLE
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = -1000.0
     *  maximum                 = 1000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = Rider_Controls_Control_CAN_En_B.Software_o1;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            real32_T typedValue;
            uint32_T* pInput;
            uint32_T typedIntValue;
            typedValue = (real32_T) (outValue);
            pInput = (uint32_T*) (&typedValue);
            typedIntValue = *pInput;

            {
              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 15)) >> 15)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 16)) >> 16)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 17)) >> 17)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 18)) >> 18)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 19)) >> 19)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 20)) >> 20)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 21)) >> 21)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 22)) >> 22)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 23)) >> 23)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 24)) >> 24)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 25)) >> 25)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 26)) >> 26)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 27)) >> 27)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 28)) >> 28)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 29)) >> 29)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 30)) >> 30)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 31)) >> 31)<<7);
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanxmt): '<Root>/eCAN Transmit' */
  {
    EALLOW;
    ECanaMboxes.MBOX1.MSGCTRL.bit.DLC =
      Rider_Controls_Control_CAN_En_B.CANPack.Length;
    ECanaMboxes.MBOX1.MSGID.all = Rider_Controls_Control_CAN_En_B.CANPack.ID;
    ECanaMboxes.MBOX1.MDL.byte.BYTE0 =
      Rider_Controls_Control_CAN_En_B.CANPack.Data[3];
    ECanaMboxes.MBOX1.MDL.byte.BYTE1 =
      Rider_Controls_Control_CAN_En_B.CANPack.Data[2];
    ECanaMboxes.MBOX1.MDL.byte.BYTE2 =
      Rider_Controls_Control_CAN_En_B.CANPack.Data[1];
    ECanaMboxes.MBOX1.MDL.byte.BYTE3 =
      Rider_Controls_Control_CAN_En_B.CANPack.Data[0];
    ECanaMboxes.MBOX1.MDH.byte.BYTE4 =
      Rider_Controls_Control_CAN_En_B.CANPack.Data[7];
    ECanaMboxes.MBOX1.MDH.byte.BYTE5 =
      Rider_Controls_Control_CAN_En_B.CANPack.Data[6];
    ECanaMboxes.MBOX1.MDH.byte.BYTE6 =
      Rider_Controls_Control_CAN_En_B.CANPack.Data[5];
    ECanaMboxes.MBOX1.MDH.byte.BYTE7 =
      Rider_Controls_Control_CAN_En_B.CANPack.Data[4];
    ECanaRegs.CANTRS.all = (((uint32_T) 0x00000001) << 1);
    EDIS;
  }

  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  Rider_Controls_Control_CAN_En_B.CANPack1.ID = 3U;
  Rider_Controls_Control_CAN_En_B.CANPack1.Length = 8U;
  Rider_Controls_Control_CAN_En_B.CANPack1.Extended = 0U;
  Rider_Controls_Control_CAN_En_B.CANPack1.Remote = 0;
  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack1.Data[4] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack1.Data[5] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack1.Data[6] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SINGLE
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = -1000.0
     *  maximum                 = 10000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = Rider_Controls_Control_CAN_En_B.Software_o3;

          /* no scaling required */
          outValue = result;
        }

        {
          {
            real32_T typedValue;
            uint32_T* pInput;
            uint32_T typedIntValue;
            typedValue = (real32_T) (outValue);
            pInput = (uint32_T*) (&typedValue);
            typedIntValue = *pInput;

            {
              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 15)) >> 15)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 16)) >> 16)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 17)) >> 17)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 18)) >> 18)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 19)) >> 19)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 20)) >> 20)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 21)) >> 21)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 22)) >> 22)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 23)) >> 23)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 24)) >> 24)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 25)) >> 25)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 26)) >> 26)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 27)) >> 27)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 28)) >> 28)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 29)) >> 29)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 30)) >> 30)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 31)) >> 31)<<7);
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanxmt): '<Root>/eCAN Transmit1' */
  {
    EALLOW;
    ECanaMboxes.MBOX4.MSGCTRL.bit.DLC =
      Rider_Controls_Control_CAN_En_B.CANPack1.Length;
    ECanaMboxes.MBOX4.MSGID.all = Rider_Controls_Control_CAN_En_B.CANPack1.ID;
    ECanaMboxes.MBOX4.MDL.byte.BYTE0 =
      Rider_Controls_Control_CAN_En_B.CANPack1.Data[3];
    ECanaMboxes.MBOX4.MDL.byte.BYTE1 =
      Rider_Controls_Control_CAN_En_B.CANPack1.Data[2];
    ECanaMboxes.MBOX4.MDL.byte.BYTE2 =
      Rider_Controls_Control_CAN_En_B.CANPack1.Data[1];
    ECanaMboxes.MBOX4.MDL.byte.BYTE3 =
      Rider_Controls_Control_CAN_En_B.CANPack1.Data[0];
    ECanaMboxes.MBOX4.MDH.byte.BYTE4 =
      Rider_Controls_Control_CAN_En_B.CANPack1.Data[7];
    ECanaMboxes.MBOX4.MDH.byte.BYTE5 =
      Rider_Controls_Control_CAN_En_B.CANPack1.Data[6];
    ECanaMboxes.MBOX4.MDH.byte.BYTE6 =
      Rider_Controls_Control_CAN_En_B.CANPack1.Data[5];
    ECanaMboxes.MBOX4.MDH.byte.BYTE7 =
      Rider_Controls_Control_CAN_En_B.CANPack1.Data[4];
    ECanaRegs.CANTRS.all = (((uint32_T) 0x00000001) << 4);
    EDIS;
  }

  /* S-Function (c280xcanrcv): '<Root>/eCAN Receive1' */
  {
    struct ECAN_REGS ECanaShadow;
    if (ECanaRegs.CANRMP.bit.RMP3) {
      /* reenable the mailbox to receive the next message */
      EALLOW;
      ECanaShadow.CANRMP.all = 0x0;
      ECanaShadow.CANRMP.bit.RMP3 = 1; /* request clear RMP for this mailbox only*/
      ECanaRegs.CANRMP.all = ECanaShadow.CANRMP.all;/* 32-bit register access is reliable only                         */
      EDIS;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Extended = 0;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Length =
        ECanaMboxes.MBOX3.MSGCTRL.bit.DLC;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.ID = 2;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[3] =
        ECanaMboxes.MBOX3.MDL.byte.BYTE0;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[2] =
        ECanaMboxes.MBOX3.MDL.byte.BYTE1;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[1] =
        ECanaMboxes.MBOX3.MDL.byte.BYTE2;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[0] =
        ECanaMboxes.MBOX3.MDL.byte.BYTE3;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[7] =
        ECanaMboxes.MBOX3.MDH.byte.BYTE4;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[6] =
        ECanaMboxes.MBOX3.MDH.byte.BYTE5;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[5] =
        ECanaMboxes.MBOX3.MDH.byte.BYTE6;
      Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[4] =
        ECanaMboxes.MBOX3.MDH.byte.BYTE7;

      /* -- Call CAN RX Fcn-Call_0 -- */
    }
  }
}

/* Model step function for TID1 */
void Rider_Controls_Control_CAN_Enable_step1(void) /* Sample time: [1.0s, 0.0s] */
{
  /* ModelReference: '<Root>/Software' */
  Rider_Controls_ControlTID1();

  /* S-Function (scanpack): '<Root>/CAN Pack2' */
  Rider_Controls_Control_CAN_En_B.CANPack2.ID = 5U;
  Rider_Controls_Control_CAN_En_B.CANPack2.Length = 8U;
  Rider_Controls_Control_CAN_En_B.CANPack2.Extended = 0U;
  Rider_Controls_Control_CAN_En_B.CANPack2.Remote = 0;
  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack2.Data[4] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack2.Data[5] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack2.Data[6] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (Rider_Controls_Control_CAN_En_B.Software_o6);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint32_T packedValue;
            if (packingValue > (boolean_T)(4294967295U)) {
              packedValue = (uint32_T) 4294967295U;
            } else if (packingValue < (boolean_T)(0)) {
              packedValue = (uint32_T) 0;
            } else {
              packedValue = (uint32_T) (packingValue);
            }

            {
              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 15)) >> 15)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 16)) >> 16)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 17)) >> 17)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 18)) >> 18)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 19)) >> 19)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 20)) >> 20)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 21)) >> 21)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 22)) >> 22)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 23)) >> 23)<<7);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 24)) >> 24)<<0);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 25)) >> 25)<<1);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 26)) >> 26)<<2);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 27)) >> 27)<<3);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 28)) >> 28)<<4);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 29)) >> 29)<<5);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 30)) >> 30)<<6);
              }

              {
                Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] =
                  Rider_Controls_Control_CAN_En_B.CANPack2.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1))
                      << 31)) >> 31)<<7);
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanxmt): '<Root>/eCAN Transmit2' */
  {
    EALLOW;
    ECanaMboxes.MBOX14.MSGCTRL.bit.DLC =
      Rider_Controls_Control_CAN_En_B.CANPack2.Length;
    ECanaMboxes.MBOX14.MSGID.all = Rider_Controls_Control_CAN_En_B.CANPack2.ID;
    ECanaMboxes.MBOX14.MDL.byte.BYTE0 =
      Rider_Controls_Control_CAN_En_B.CANPack2.Data[3];
    ECanaMboxes.MBOX14.MDL.byte.BYTE1 =
      Rider_Controls_Control_CAN_En_B.CANPack2.Data[2];
    ECanaMboxes.MBOX14.MDL.byte.BYTE2 =
      Rider_Controls_Control_CAN_En_B.CANPack2.Data[1];
    ECanaMboxes.MBOX14.MDL.byte.BYTE3 =
      Rider_Controls_Control_CAN_En_B.CANPack2.Data[0];
    ECanaMboxes.MBOX14.MDH.byte.BYTE4 =
      Rider_Controls_Control_CAN_En_B.CANPack2.Data[7];
    ECanaMboxes.MBOX14.MDH.byte.BYTE5 =
      Rider_Controls_Control_CAN_En_B.CANPack2.Data[6];
    ECanaMboxes.MBOX14.MDH.byte.BYTE6 =
      Rider_Controls_Control_CAN_En_B.CANPack2.Data[5];
    ECanaMboxes.MBOX14.MDH.byte.BYTE7 =
      Rider_Controls_Control_CAN_En_B.CANPack2.Data[4];
    ECanaRegs.CANTRS.all = (((uint32_T) 0x00000001) << 14);
    EDIS;
  }

  /* S-Function (scanpack): '<Root>/CAN Pack3' */
  Rider_Controls_Control_CAN_En_B.CANPack3.ID = 483U;
  Rider_Controls_Control_CAN_En_B.CANPack3.Length = 8U;
  Rider_Controls_Control_CAN_En_B.CANPack3.Extended = 0U;
  Rider_Controls_Control_CAN_En_B.CANPack3.Remote = 0;
  Rider_Controls_Control_CAN_En_B.CANPack3.Data[0] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack3.Data[1] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack3.Data[2] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack3.Data[3] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack3.Data[4] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack3.Data[5] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack3.Data[6] = 0;
  Rider_Controls_Control_CAN_En_B.CANPack3.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 1
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (Rider_Controls_Control_CAN_En_B.Software_o5);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (boolean_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (packingValue < (boolean_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Rider_Controls_Control_CAN_En_B.CANPack3.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<1);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 2
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (Rider_Controls_Control_CAN_En_B.Software_o4);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (boolean_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (packingValue < (boolean_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Rider_Controls_Control_CAN_En_B.CANPack3.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<2);
              }
            }
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 3
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 0
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (Rider_Controls_Control_CAN_En_B.Software_o7);

          /* no scaling required */
          packingValue = result;
        }

        {
          {
            uint8_T packedValue;
            if (packingValue > (boolean_T)(1)) {
              packedValue = (uint8_T) 1;
            } else if (packingValue < (boolean_T)(0)) {
              packedValue = (uint8_T) 0;
            } else {
              packedValue = (uint8_T) (packingValue);
            }

            {
              {
                Rider_Controls_Control_CAN_En_B.CANPack3.Data[0] =
                  Rider_Controls_Control_CAN_En_B.CANPack3.Data[0] | (uint8_T)
                  ((uint8_T)((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) <<
                      0)) >> 0)<<0);
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (c280xcanxmt): '<Root>/eCAN Transmit3' */
  {
    EALLOW;
    ECanaMboxes.MBOX15.MSGCTRL.bit.DLC =
      Rider_Controls_Control_CAN_En_B.CANPack3.Length;
    ECanaMboxes.MBOX15.MSGID.all = Rider_Controls_Control_CAN_En_B.CANPack3.ID;
    ECanaMboxes.MBOX15.MDL.byte.BYTE0 =
      Rider_Controls_Control_CAN_En_B.CANPack3.Data[3];
    ECanaMboxes.MBOX15.MDL.byte.BYTE1 =
      Rider_Controls_Control_CAN_En_B.CANPack3.Data[2];
    ECanaMboxes.MBOX15.MDL.byte.BYTE2 =
      Rider_Controls_Control_CAN_En_B.CANPack3.Data[1];
    ECanaMboxes.MBOX15.MDL.byte.BYTE3 =
      Rider_Controls_Control_CAN_En_B.CANPack3.Data[0];
    ECanaMboxes.MBOX15.MDH.byte.BYTE4 =
      Rider_Controls_Control_CAN_En_B.CANPack3.Data[7];
    ECanaMboxes.MBOX15.MDH.byte.BYTE5 =
      Rider_Controls_Control_CAN_En_B.CANPack3.Data[6];
    ECanaMboxes.MBOX15.MDH.byte.BYTE6 =
      Rider_Controls_Control_CAN_En_B.CANPack3.Data[5];
    ECanaMboxes.MBOX15.MDH.byte.BYTE7 =
      Rider_Controls_Control_CAN_En_B.CANPack3.Data[4];
    ECanaRegs.CANTRS.all = (((uint32_T) 0x00000001) << 15);
    EDIS;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void Rider_Controls_Control_CAN_Enable_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Rider_Controls_Control_CAN_Enable_step0();
    break;

   case 1 :
    Rider_Controls_Control_CAN_Enable_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Rider_Controls_Control_CAN_Enable_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Rider_Controls_Control_CAN_E_M, 0,
                sizeof(RT_MODEL_Rider_Controls_Contr_d));

  /* block I/O */
  (void) memset(((void *) &Rider_Controls_Control_CAN_En_B), 0,
                sizeof(BlockIO_Rider_Controls_Control_));

  {
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_Control_CAN_En_B.CANPack = CAN_DATATYPE_GROUND;
    Rider_Controls_Control_CAN_En_B.CANPack1 = CAN_DATATYPE_GROUND;
    Rider_Controls_Control_CAN_En_B.CANPack2 = CAN_DATATYPE_GROUND;
    Rider_Controls_Control_CAN_En_B.CANPack3 = CAN_DATATYPE_GROUND;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2 = CAN_DATATYPE_GROUND;
    Rider_Controls_Control_CAN_En_B.CANUnpack2 = 0.0;
    Rider_Controls_Control_CAN_En_B.CANUnpack_o1 = 0.0F;
    Rider_Controls_Control_CAN_En_B.CANUnpack_o2 = 0.0F;
    Rider_Controls_Control_CAN_En_B.Software_o1 = 0.0F;
    Rider_Controls_Control_CAN_En_B.Software_o2 = 0.0F;
    Rider_Controls_Control_CAN_En_B.Software_o3 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&Rider_Controls_Control_CA_DWork, 0,
                sizeof(D_Work_Rider_Controls_Control_C));

  {
    static uint32_T *taskCounterPtrs;
    static boolean_T *rateTransitionPtrs[(2 * 2)];
    Rider_Controls_C_TimingBridge_k.nTasks = 2;
    Rider_Controls_C_TimingBridge_k.clockTick = (NULL);
    Rider_Controls_C_TimingBridge_k.clockTickH = (NULL);
    taskCounterPtrs = &(Rider_Controls_Control_CAN_E_M->Timing.TaskCounters.TID
                        [0]);
    Rider_Controls_C_TimingBridge_k.taskCounter = taskCounterPtrs;
    rateTransitionPtrs[0*2 + 1] =
      &(Rider_Controls_Control_CAN_E_M->Timing.RateInteraction.TID0_1);
    Rider_Controls_C_TimingBridge_k.rateTransition = rateTransitionPtrs;
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/Software' */
  Rider_Controls_C_initialize(rtmGetErrorStatusPointer
    (Rider_Controls_Control_CAN_E_M), &Rider_Controls_C_TimingBridge_k, 0, 1);

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive' */
  /* Configure mailbox 0 to receive messages with the ID: 0 */
  config_eCAN_A_mbx (0U, 0, 0, 0);

  /* Initialize Rider_Controls_Control_CAN_En_B.eCANReceive_o2 */
  {
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Extended = 0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Length = 8;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.ID = 0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack -----------------*/

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive2' */
  /* Configure mailbox 10 to receive messages with the ID: 4 */
  config_eCAN_A_mbx (0U, 10, 4, 0);

  /* Initialize Rider_Controls_Control_CAN_En_B.eCANReceive2_o2 */
  {
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Extended = 0;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Length = 8;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.ID = 4;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive2_o2.Data[7] = (uint8_T)0.0;
  }

  /*-----------S-Function Block: <Root>/CAN Unpack2 -----------------*/

  /* Start for S-Function (c280xcanxmt): '<Root>/eCAN Transmit' */

  /* Configure mailbox 1 to transmit messages with the ID: 1 */
  config_eCAN_A_mbx (1U, 1, 1, 0);

  /* Start for S-Function (c280xcanxmt): '<Root>/eCAN Transmit1' */

  /* Configure mailbox 4 to transmit messages with the ID: 3 */
  config_eCAN_A_mbx (1U, 4, 3, 0);

  /* Start for S-Function (c280xcanxmt): '<Root>/eCAN Transmit2' */

  /* Configure mailbox 14 to transmit messages with the ID: 5 */
  config_eCAN_A_mbx (1U, 14, 5, 0);

  /* Start for S-Function (c280xcanxmt): '<Root>/eCAN Transmit3' */

  /* Configure mailbox 15 to transmit messages with the ID: 483 */
  config_eCAN_A_mbx (1U, 15, 483, 0);

  /* Start for S-Function (c280xcanrcv): '<Root>/eCAN Receive1' */
  /* Configure mailbox 3 to receive messages with the ID: 2 */
  config_eCAN_A_mbx (0U, 3, 2, 0);

  /* Initialize Rider_Controls_Control_CAN_En_B.eCANReceive1_o2 */
  {
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Extended = 0;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Length = 8;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.ID = 2;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[0] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[1] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[2] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[3] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[4] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[5] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[6] = (uint8_T)0.0;
    Rider_Controls_Control_CAN_En_B.eCANReceive1_o2.Data[7] = (uint8_T)0.0;
  }
}

/* Model terminate function */
void Rider_Controls_Control_CAN_Enable_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
