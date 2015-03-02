/*
 * File: ert_main.c
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
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  enableTimer0Interrupt();
  Rider_Controls_InHardware_CAN_Enable_step();

  /* Get model outputs here */
  disableTimer0Interrupt();
  OverrunFlag--;
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.01;
  float systemClock = 60;
  c2000_flash_init();
  init_board();
  rtmSetErrorStatus(Rider_Controls_InHardware_CA_M, 0);
  Rider_Controls_InHardware_CAN_Enable_initialize();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    rtmGetErrorStatus(Rider_Controls_InHardware_CA_M) == (NULL);
  enableTimer0Interrupt();
  globalInterruptEnable();
  while (runModel) {
    runModel =
      rtmGetErrorStatus(Rider_Controls_InHardware_CA_M) == (NULL);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Rider_Controls_InHardware_CAN_Enable_terminate();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
