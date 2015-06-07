#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "F2806x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "c280xx_asyncscheduling.h"
#include "c280xx_asyncscheduling_private.h"

void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

interrupt void EPWM3_INT_isr(void)
{
  volatile unsigned int PIEIER3_stack_save = PieCtrlRegs.PIEIER3.all;
  PieCtrlRegs.PIEIER3.all &= ~12;      /*disable group3 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~4;                           /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 4;          /*ACK to allow other interrupts from the same group to fire*/
  IER |= 4;
  EINT;                                /*global interrupt enable*/
  isr_int3pie3_task_fcn();
  DINT;                                /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR    */
  PieCtrlRegs.PIEIER3.all = PIEIER3_stack_save;/*restore PIEIER register that was modified*/
  EALLOW;
  EPwm3Regs.ETCLR.bit.INT = 1;
  EDIS;
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;/* Acknowledge to receive more interrupts*/
}

interrupt void EPWM4_INT_isr(void)
{
  volatile unsigned int PIEIER3_stack_save = PieCtrlRegs.PIEIER3.all;
  PieCtrlRegs.PIEIER3.all &= ~8;       /*disable group3 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~4;                           /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 4;          /*ACK to allow other interrupts from the same group to fire*/
  IER |= 4;
  EINT;                                /*global interrupt enable*/
  isr_int3pie4_task_fcn();
  DINT;                                /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR    */
  PieCtrlRegs.PIEIER3.all = PIEIER3_stack_save;/*restore PIEIER register that was modified*/
  EALLOW;
  EPwm4Regs.ETCLR.bit.INT = 1;
  EDIS;
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;/* Acknowledge to receive more interrupts*/
}

interrupt void ECAN0INTA_isr(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER3_stack_save = PieCtrlRegs.PIEIER3.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~64;      /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER3.all &= ~12;      /*disable group3 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~16;      /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~261;                         /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 261;        /*ACK to allow other interrupts from the same group to fire*/
  IER |= 256;
  EINT;                                /*global interrupt enable*/
  isr_int9pie5_task_fcn();
  DINT;                                /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR    */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;/*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER3.all = PIEIER3_stack_save;/*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;/*restore PIEIER register that was modified*/
  switch (ECanaRegs.CANGIF0.bit.MIV0){
   case 0:
    ECanaRegs.CANRMP.bit.RMP0 = 1;
    break;
  }

  PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;/* Acknowledge to receive more interrupts*/
}

void enable_interrupts()
{
  EALLOW;
  PieVectTable.EPWM3_INT = &EPWM3_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER3.bit.INTx3 = 1;   /* Enable interrupt EPWM3_INT*/
  IER |= M_INT3;
  EALLOW;
  PieVectTable.EPWM4_INT = &EPWM4_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER3.bit.INTx4 = 1;   /* Enable interrupt EPWM4_INT*/
  IER |= M_INT3;
  EALLOW;
  PieVectTable.ECAN0INTA = &ECAN0INTA_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER9.bit.INTx5 = 1;   /* Enable interrupt ECAN0INTA*/
  IER |= M_INT9;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                                /* Enable Global realtime interrupt DBGM*/
}
