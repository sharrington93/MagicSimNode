/*
 * File: Rider_Controls_Full_CAN_Enable.c
 *
 * Code generated for Simulink model 'Rider_Controls_Full_CAN_Enable'.
 *
 * Model version                  : 1.105
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Wed Apr 01 18:57:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Rider_Controls_Full_CAN_Enable.h"
#include "Rider_Controls_Full_CAN_Enable_private.h"

rtTimingBridge Rider_Controls_Ful_TimingBridge;
const real_T Rider_Controls_Full_CAN_Enable_RGND = 0.0;/* real_T ground */
const uint16_T Rider_Controls_Full_CAN_Enable_U16GND = 0U;/* uint16_T ground */

/* Block signals (auto storage) */
BlockIO_Rider_Controls_Full_CAN Rider_Controls_Full_CAN_Enabl_B;

/* Block states (auto storage) */
D_Work_Rider_Controls_Full_CAN_ Rider_Controls_Full_CAN_E_DWork;

/* Real-time model */
RT_MODEL_Rider_Controls_Full_CA Rider_Controls_Full_CAN_Enab_M_;
RT_MODEL_Rider_Controls_Full_CA *const Rider_Controls_Full_CAN_Enab_M =
  &Rider_Controls_Full_CAN_Enab_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Rider_Controls_Full_CAN_Enable_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Rider_Controls_Full_CAN_Enab_M, 1));
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
  Rider_Controls_Full_CAN_Enab_M->Timing.RateInteraction.TID0_1 =
    (Rider_Controls_Full_CAN_Enab_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Rider_Controls_Full_CAN_Enab_M->Timing.TaskCounters.TID[1])++;
  if ((Rider_Controls_Full_CAN_Enab_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.01s, 0.0s] */
    Rider_Controls_Full_CAN_Enab_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Rider_Controls_Full_CAN_Enable_step0(void) /* Sample time: [1.0E-5s, 0.0s] */
{
  {                                    /* Sample time: [1.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* ModelReference: '<Root>/InHardware' */
  Rider_Controls_InHardwareTID0();
  Rider_Controls_InHar_UpdateTID0();

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  Rider_Controls_Full_CAN_Enab_M->Timing.clockTick0++;
  if (!Rider_Controls_Full_CAN_Enab_M->Timing.clockTick0) {
    Rider_Controls_Full_CAN_Enab_M->Timing.clockTickH0++;
  }
}

/* Model step function for TID1 */
void Rider_Controls_Full_CAN_Enable_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  uint16_T rtb_Software_o6;
  uint16_T rtb_Software_o7;

  /* ModelReference: '<Root>/InHardware' */
  Rider_Controls_InHardwareTID1(&Rider_Controls_Full_CAN_Enabl_B.InHardware_o1,
    &Rider_Controls_Full_CAN_Enabl_B.InHardware_o2,
    &Rider_Controls_Full_CAN_Enabl_B.InHardware_o3[0],
    &Rider_Controls_Full_CAN_Enabl_B.InHardware_o4,
    &Rider_Controls_Full_CAN_Enabl_B.InHardware_o5);

  /* ModelReference: '<Root>/Software' */
  Rider_Controls_Control(&Rider_Controls_Full_CAN_Enabl_B.InHardware_o1,
    &Rider_Controls_Full_CAN_Enabl_B.InHardware_o2,
    &Rider_Controls_Full_CAN_Enabl_B.InHardware_o3[0],
    &Rider_Controls_Full_CAN_Enabl_B.InHardware_o4, (uint16_T*)
    &Rider_Controls_Full_CAN_Enable_U16GND,
    &Rider_Controls_Full_CAN_Enabl_B.Software_o1,
    &Rider_Controls_Full_CAN_Enabl_B.Software_o2,
    &Rider_Controls_Full_CAN_Enabl_B.Software_o3,
    &Rider_Controls_Full_CAN_Enabl_B.Software_o4,
    &Rider_Controls_Full_CAN_Enabl_B.Software_o5, &rtb_Software_o6,
    &rtb_Software_o7);

  /* ModelReference: '<Root>/OutHardware' */
  Rider_Controls_OutHardware(&Rider_Controls_Full_CAN_Enabl_B.Software_o1,
    &Rider_Controls_Full_CAN_Enabl_B.Software_o4,
    &Rider_Controls_Full_CAN_Enabl_B.Software_o5, &rtb_Software_o7,
    &rtb_Software_o6);

  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.ID = 480U;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Length = 8U;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Extended = 0U;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Remote = 0;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] = 0;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] = 0;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] = 0;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] = 0;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[4] = 0;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[5] = 0;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[6] = 0;
  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 32
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SINGLE
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 1.0
     * -----------------------------------------------------------------------*/

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 0
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SINGLE
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 4000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = Rider_Controls_Full_CAN_Enabl_B.Software_o1;

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
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 15)) >> 15)<<7);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 16)) >> 16)<<0);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 17)) >> 17)<<1);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 18)) >> 18)<<2);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 19)) >> 19)<<3);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 20)) >> 20)<<4);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 21)) >> 21)<<5);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 22)) >> 22)<<6);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 23)) >> 23)<<7);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 24)) >> 24)<<0);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 25)) >> 25)<<1);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 26)) >> 26)<<2);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 27)) >> 27)<<3);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 28)) >> 28)<<4);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 29)) >> 29)<<5);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 30)) >> 30)<<6);
              }

              {
                Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] =
                  Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3] | (uint8_T)
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
    ECanaMboxes.MBOX20.MSGCTRL.bit.DLC =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Length;
    ECanaMboxes.MBOX20.MSGID.all = Rider_Controls_Full_CAN_Enabl_B.CANPack1.ID;
    ECanaMboxes.MBOX20.MDL.byte.BYTE0 =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[3];
    ECanaMboxes.MBOX20.MDL.byte.BYTE1 =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[2];
    ECanaMboxes.MBOX20.MDL.byte.BYTE2 =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[1];
    ECanaMboxes.MBOX20.MDL.byte.BYTE3 =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[0];
    ECanaMboxes.MBOX20.MDH.byte.BYTE4 =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[7];
    ECanaMboxes.MBOX20.MDH.byte.BYTE5 =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[6];
    ECanaMboxes.MBOX20.MDH.byte.BYTE6 =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[5];
    ECanaMboxes.MBOX20.MDH.byte.BYTE7 =
      Rider_Controls_Full_CAN_Enabl_B.CANPack1.Data[4];
    ECanaRegs.CANTRS.all = (((uint32_T) 0x00000001) << 20);
    EDIS;
  }

  Rider_Controls_InHar_UpdateTID1();

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  Rider_Controls_Full_CAN_Enab_M->Timing.clockTick1++;
  if (!Rider_Controls_Full_CAN_Enab_M->Timing.clockTick1) {
    Rider_Controls_Full_CAN_Enab_M->Timing.clockTickH1++;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void Rider_Controls_Full_CAN_Enable_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Rider_Controls_Full_CAN_Enable_step0();
    break;

   case 1 :
    Rider_Controls_Full_CAN_Enable_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Rider_Controls_Full_CAN_Enable_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Rider_Controls_Full_CAN_Enab_M, 0,
                sizeof(RT_MODEL_Rider_Controls_Full_CA));

  /* block I/O */
  (void) memset(((void *) &Rider_Controls_Full_CAN_Enabl_B), 0,
                sizeof(BlockIO_Rider_Controls_Full_CAN));

  {
    int_T i;
    for (i = 0; i < 40; i++) {
      Rider_Controls_Full_CAN_Enabl_B.InHardware_o3[i] = 0.0F;
    }

    Rider_Controls_Full_CAN_Enabl_B.CANPack1 = CAN_DATATYPE_GROUND;
    Rider_Controls_Full_CAN_Enabl_B.InHardware_o1 = 0.0F;
    Rider_Controls_Full_CAN_Enabl_B.InHardware_o2 = 0.0F;
    Rider_Controls_Full_CAN_Enabl_B.Software_o1 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&Rider_Controls_Full_CAN_E_DWork, 0,
                sizeof(D_Work_Rider_Controls_Full_CAN_));

  {
    static uint32_T *clockTickPtrs[2];
    static uint32_T *clockTickHPtrs[2];
    static uint32_T *taskCounterPtrs;
    static boolean_T *rateTransitionPtrs[(2 * 2)];
    Rider_Controls_Ful_TimingBridge.nTasks = 2;
    clockTickPtrs[0] = &(Rider_Controls_Full_CAN_Enab_M->Timing.clockTick0);
    clockTickHPtrs[0] = &(Rider_Controls_Full_CAN_Enab_M->Timing.clockTickH0);
    clockTickPtrs[1] = &(Rider_Controls_Full_CAN_Enab_M->Timing.clockTick1);
    clockTickHPtrs[1] = &(Rider_Controls_Full_CAN_Enab_M->Timing.clockTickH1);
    Rider_Controls_Ful_TimingBridge.clockTick = clockTickPtrs;
    Rider_Controls_Ful_TimingBridge.clockTickH = clockTickHPtrs;
    taskCounterPtrs = &(Rider_Controls_Full_CAN_Enab_M->Timing.TaskCounters.TID
                        [0]);
    Rider_Controls_Ful_TimingBridge.taskCounter = taskCounterPtrs;
    rateTransitionPtrs[0*2 + 1] =
      &(Rider_Controls_Full_CAN_Enab_M->Timing.RateInteraction.TID0_1);
    Rider_Controls_Ful_TimingBridge.rateTransition = rateTransitionPtrs;
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/InHardware' */
  Rider_Controls_I_initialize(rtmGetErrorStatusPointer
    (Rider_Controls_Full_CAN_Enab_M), &Rider_Controls_Ful_TimingBridge, 0, 1);

  /* Model Initialize fcn for ModelReference Block: '<Root>/OutHardware' */
  Rider_Controls_OutHa_initialize(rtmGetErrorStatusPointer
    (Rider_Controls_Full_CAN_Enab_M));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Software' */
  Rider_Controls_Contr_initialize(rtmGetErrorStatusPointer
    (Rider_Controls_Full_CAN_Enab_M));

  /* Start for ModelReference: '<Root>/InHardware' */
  Rider_Controls_InHard_Start();

  /* Start for ModelReference: '<Root>/OutHardware' */
  Rider_Controls_OutHardwar_Start();

  /* Start for S-Function (c280xcanxmt): '<Root>/eCAN Transmit1' */

  /* Configure mailbox 20 to transmit messages with the ID: 480 */
  config_eCAN_A_mbx (1U, 20, 480, 0);
}

/* Model terminate function */
void Rider_Controls_Full_CAN_Enable_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
