#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include "DSP2803x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "Rider_Controls_Full_CAN_Enable.h"
#include "Rider_Controls_Full_CAN_Enable_private.h"

void init_board ()
{
  DisableDog();
  EALLOW;
  SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;/* Enable ADC peripheral clock*/
  (*Device_cal)();
  SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 0;/* Return ADC clock to original state*/
  EDIS;

  /* Select Internal Oscillator 1 as Clock Source (default), and turn off all unused clocks to
   * conserve power.
   */
  IntOsc1Sel();

  /* Initialize the PLL control: PLLCR and DIVSEL
   * DSP28_PLLCR and DSP28_DIVSEL are defined in DSP2803x_Examples.h
   */
  InitPll(12,2);
  InitPeripheralClocks();
  EALLOW;

  /* Configure low speed peripheral clocks */
  SysCtrlRegs.LOSPCP.all = 0U;
  EDIS;

  /* Disable and clear all CPU interrupts */
  DINT;
  IER = 0x0000;
  IFR = 0x0000;
  InitPieCtrl();
  InitPieVectTable();

  /* initial eCAN function.... */
  /* Initialize eCAN_A Module with following parameters:
   *    BRP=4, TSEG1=8, TSEG2=6
   *    Resynchronize on: Only_falling_edges
   *    Level of CAN bus: Sample_one_time
   *    Synchronization jump width = 2 */
  init_eCAN_A (4, 8, 6, 1, 2, 1);
  InitCpuTimers();

  /* initial GPIO qualification settings.... */
  EALLOW;
  GpioCtrlRegs.GPAQSEL1.all = 0U;
  GpioCtrlRegs.GPAQSEL2.all = 2097152U;
  GpioCtrlRegs.GPBQSEL1.all = 0U;

  /* Initialize qualification sampling period */
  // GpioCtrlRegs.GPACTRL.bit.QUALPRD3 = 255;          // GPIO Port A Qualification Control Register Field: Sampling period for pins GPIO24 to GPIO31
  GpioCtrlRegs.GPACTRL.all = (GpioCtrlRegs.GPACTRL.all & ~0xFF000000) |
    0xFF000000;
  EDIS;
}
