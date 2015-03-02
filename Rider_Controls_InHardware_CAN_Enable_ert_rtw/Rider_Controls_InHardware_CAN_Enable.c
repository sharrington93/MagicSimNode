/*
 * File: Rider_Controls_InHardware_CAN_Enable.c
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

#include "Rider_Controls_InHardware_CAN_Enable.h"
#include "Rider_Controls_InHardware_CAN_Enable_private.h"

/* Block signals (auto storage) */
BlockIO_Rider_Controls_InHardwa Rider_Controls_InHardware_CAN_B;

/* Block states (auto storage) */
D_Work_Rider_Controls_InHardwar Rider_Controls_InHardwa_DWork_m;

/* Real-time model */
RT_MODEL_Rider_Controls_InHar_d Rider_Controls_InHardware_CA_M_;
RT_MODEL_Rider_Controls_InHar_d *const Rider_Controls_InHardware_CA_M =
  &Rider_Controls_InHardware_CA_M_;

/* Model step function */
void Rider_Controls_InHardware_CAN_Enable_step(void)
{
  /* ModelReference: '<Root>/Software' */
  Rider_Controls_InHardware(&Rider_Controls_InHardware_CAN_B.Software_o1,
    &Rider_Controls_InHardware_CAN_B.Software_o2);

  /* S-Function (scanpack): '<Root>/CAN Pack' */
  Rider_Controls_InHardware_CAN_B.CANPack.ID = 0U;
  Rider_Controls_InHardware_CAN_B.CANPack.Length = 8U;
  Rider_Controls_InHardware_CAN_B.CANPack.Extended = 0U;
  Rider_Controls_InHardware_CAN_B.CANPack.Remote = 0;
  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] = 0;
  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] = 0;
  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] = 0;
  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] = 0;
  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] = 0;
  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] = 0;
  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] = 0;
  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 32
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SINGLE
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = -100000.0
     *  maximum                 = 100000.0
     * -----------------------------------------------------------------------*/
    {
      {
        real32_T outValue = 0;

        {
          real32_T result = Rider_Controls_InHardware_CAN_B.Software_o2;

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
                Rider_Controls_InHardware_CAN_B.CANPack.Data[4] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[4] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[4] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[4] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[4] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[4] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[4] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[4] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[4] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[5] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[5] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[5] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[5] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[5] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[5] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[5] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[5] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[5] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 15)) >> 15)<<7);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[6] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 16)) >> 16)<<0);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[6] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 17)) >> 17)<<1);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[6] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 18)) >> 18)<<2);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[6] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 19)) >> 19)<<3);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[6] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 20)) >> 20)<<4);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[6] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 21)) >> 21)<<5);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[6] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 22)) >> 22)<<6);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[6] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[6] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 23)) >> 23)<<7);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[7] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 24)) >> 24)<<0);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[7] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 25)) >> 25)<<1);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[7] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 26)) >> 26)<<2);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[7] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 27)) >> 27)<<3);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[7] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 28)) >> 28)<<4);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[7] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 29)) >> 29)<<5);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[7] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 30)) >> 30)<<6);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[7] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[7] | (uint8_T)
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
          real32_T result = Rider_Controls_InHardware_CAN_B.Software_o1;

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
                Rider_Controls_InHardware_CAN_B.CANPack.Data[0] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 0)) >> 0)<<0);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[0] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 1)) >> 1)<<1);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[0] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 2)) >> 2)<<2);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[0] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 3)) >> 3)<<3);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[0] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 4)) >> 4)<<4);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[0] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 5)) >> 5)<<5);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[0] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 6)) >> 6)<<6);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[0] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[0] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 7)) >> 7)<<7);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[1] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 8)) >> 8)<<0);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[1] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 9)) >> 9)<<1);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[1] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 10)) >> 10)<<2);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[1] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 11)) >> 11)<<3);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[1] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 12)) >> 12)<<4);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[1] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 13)) >> 13)<<5);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[1] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 14)) >> 14)<<6);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[1] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[1] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 15)) >> 15)<<7);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[2] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 16)) >> 16)<<0);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[2] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 17)) >> 17)<<1);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[2] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 18)) >> 18)<<2);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[2] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 19)) >> 19)<<3);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[2] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 20)) >> 20)<<4);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[2] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 21)) >> 21)<<5);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[2] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 22)) >> 22)<<6);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[2] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[2] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 23)) >> 23)<<7);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[3] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 24)) >> 24)<<0);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[3] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 25)) >> 25)<<1);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[3] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 26)) >> 26)<<2);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[3] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 27)) >> 27)<<3);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[3] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 28)) >> 28)<<4);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[3] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 29)) >> 29)<<5);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[3] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] | (uint8_T)
                  ((uint8_T)((uint32_T)(typedIntValue & (uint32_T)(((uint32_T)(1))
                      << 30)) >> 30)<<6);
              }

              {
                Rider_Controls_InHardware_CAN_B.CANPack.Data[3] =
                  Rider_Controls_InHardware_CAN_B.CANPack.Data[3] | (uint8_T)
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
      Rider_Controls_InHardware_CAN_B.CANPack.Length;
    ECanaMboxes.MBOX1.MSGID.all = Rider_Controls_InHardware_CAN_B.CANPack.ID;
    ECanaMboxes.MBOX1.MDL.byte.BYTE0 =
      Rider_Controls_InHardware_CAN_B.CANPack.Data[3];
    ECanaMboxes.MBOX1.MDL.byte.BYTE1 =
      Rider_Controls_InHardware_CAN_B.CANPack.Data[2];
    ECanaMboxes.MBOX1.MDL.byte.BYTE2 =
      Rider_Controls_InHardware_CAN_B.CANPack.Data[1];
    ECanaMboxes.MBOX1.MDL.byte.BYTE3 =
      Rider_Controls_InHardware_CAN_B.CANPack.Data[0];
    ECanaMboxes.MBOX1.MDH.byte.BYTE4 =
      Rider_Controls_InHardware_CAN_B.CANPack.Data[7];
    ECanaMboxes.MBOX1.MDH.byte.BYTE5 =
      Rider_Controls_InHardware_CAN_B.CANPack.Data[6];
    ECanaMboxes.MBOX1.MDH.byte.BYTE6 =
      Rider_Controls_InHardware_CAN_B.CANPack.Data[5];
    ECanaMboxes.MBOX1.MDH.byte.BYTE7 =
      Rider_Controls_InHardware_CAN_B.CANPack.Data[4];
    ECanaRegs.CANTRS.all = (((uint32_T) 0x00000001) << 1);
    EDIS;
  }
}

/* Model initialize function */
void Rider_Controls_InHardware_CAN_Enable_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Rider_Controls_InHardware_CA_M, (NULL));

  /* block I/O */
  {
    Rider_Controls_InHardware_CAN_B.CANPack = CAN_DATATYPE_GROUND;
    Rider_Controls_InHardware_CAN_B.Software_o1 = 0.0F;
    Rider_Controls_InHardware_CAN_B.Software_o2 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&Rider_Controls_InHardwa_DWork_m, 0,
                sizeof(D_Work_Rider_Controls_InHardwar));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Software' */
  Rider_Controls_InHar_initialize(rtmGetErrorStatusPointer
    (Rider_Controls_InHardware_CA_M));

  /* Start for ModelReference: '<Root>/Software' */
  Rider_Controls_InHardware_Start();

  /* Start for S-Function (c280xcanxmt): '<Root>/eCAN Transmit' */

  /* Configure mailbox 1 to transmit messages with the ID: 0 */
  config_eCAN_A_mbx (1U, 1, 0, 0);
}

/* Model terminate function */
void Rider_Controls_InHardware_CAN_Enable_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
