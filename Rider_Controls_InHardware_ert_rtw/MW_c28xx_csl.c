#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include "DSP2803x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "Rider_Controls_InHardware.h"
#include "Rider_Controls_InHardware_private.h"

void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

void enable_interrupts()
{
}
