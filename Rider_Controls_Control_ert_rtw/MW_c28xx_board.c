#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include "DSP2803x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "Rider_Controls_Control.h"
#include "Rider_Controls_Control_private.h"

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
  InitCpuTimers();

  /* initial GPIO qualification settings.... */
  EALLOW;
  GpioCtrlRegs.GPAQSEL1.all = 0U;
  GpioCtrlRegs.GPAQSEL2.all = 0U;
  GpioCtrlRegs.GPBQSEL1.all = 0U;
  EDIS;
}
