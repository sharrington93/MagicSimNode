/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'c280xx_asyncscheduling'.
 *
 * Model version                  : 1.213
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Fri Jun 05 22:34:06 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "c280xx_asyncscheduling.h"
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
  c280xx_asyncscheduling_step();

  /* Get model outputs here */
  disableTimer0Interrupt();
  OverrunFlag--;
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.001;
  float systemClock = 90;
  c2000_flash_init();
  init_board();
  rtmSetErrorStatus(c280xx_asyncscheduling_M, 0);
  c280xx_asyncscheduling_initialize();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    rtmGetErrorStatus(c280xx_asyncscheduling_M) == (NULL);
  enableTimer0Interrupt();
  enable_interrupts();
  globalInterruptEnable();
  while (runModel) {
    runModel =
      rtmGetErrorStatus(c280xx_asyncscheduling_M) == (NULL);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  c280xx_asyncscheduling_terminate();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
