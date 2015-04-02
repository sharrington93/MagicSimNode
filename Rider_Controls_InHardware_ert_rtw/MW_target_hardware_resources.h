#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#include "DSP2803x_Device.h"
#include "DSP2803x_GlobalPrototypes.h"
#include "c2000BoardSupport.h"
#include "c2000SchedulerTimer.h"

#define MW_USECODERTARGET 1.000000
#define MW_TARGETHARDWARE TI Piccolo F2803x (boot from flash)
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 0
#define MW_RUNTIME_DEVICEID 0
#define MW_RUNTIME_FLASHLOAD 1
#define MW_RUNTIME_LOADCOMMANDARG $(TARGET_ROOT)/CCS_Config/f28035.ccxml
#define MW_TARGETLINKOBJ_USECUSTOMLINKER 1
#define MW_TARGETLINKOBJ_NAME $(TARGET_ROOT)/src/c28035.cmd
#define MW_CLOCKING_CPUCLOCKRATEMHZ 60
#define MW_CLOCKING_USEINTERNALOSC 1
#define MW_CLOCKING_OSCCLK 10
#define MW_CLOCKING_AUTOSETPLLSETTINGS 1
#define MW_CLOCKING_PLLCR 0
#define MW_CLOCKING_DIVSEL 1
#define MW_CLOCKING_CLOSESTCPUCLOCK 60
#define MW_CLOCKING_LSPCLKDIV 0
#define MW_CLOCKING_LSPCLK 15
#define MW_ADC_CLOCKDIV 0
#define MW_ADC_CLOCKFREQUENCY 60.000000
#define MW_ADC_NONOVERLAP 0
#define MW_ADC_OFFSETCORRECTIONVALUE 0
#define MW_ADC_EXTERNALREFERENCESELECTOR 0
#define MW_ADC_EXTERNALREFERENCEVREFHI 3.3
#define MW_ADC_EXTERNALREFERENCEVREFLO 0
#define MW_ADC_INTPULSEGENERATION 0
#define MW_ADC_SOCPRIORITY 0
#define MW_ADC_XINT2GPIO 0
#define MW_COMP_PINASSIGNMENT_COMP1 1
#define MW_COMP_PINASSIGNMENT_COMP2 1
#define MW_COMP_PINASSIGNMENT_COMP3 1
#define MW_ECAN_A_MODULECLOCKFREQUENCY 30
#define MW_ECAN_A_BAUDRATEPRESCALER 4.000000
#define MW_ECAN_A_TSEG1 6
#define MW_ECAN_A_TSEG2 4
#define MW_ECAN_A_BAUDRATE 500000
#define MW_ECAN_A_SBG 0
#define MW_ECAN_A_SJW 1
#define MW_ECAN_A_SAM 0
#define MW_ECAN_A_ENHANCEDCANMODE 1
#define MW_ECAN_A_SELFTESTMODE 0
#define MW_ECAP_PINASSIGNMENT_ECAP1 1
#define MW_EPWM_PINASSIGNMENT_TZ1 0
#define MW_EPWM_PINASSIGNMENT_TZ2 0
#define MW_EPWM_PINASSIGNMENT_TZ3 0
#define MW_EPWM_PINASSIGNMENT_SYNCI 0
#define MW_EPWM_PINASSIGNMENT_SYNCO 0
#define MW_I2C_MODE 0
#define MW_I2C_ADDRDATAFORMAT 0
#define MW_I2C_OWNADDRESS 1
#define MW_I2C_BITCOUNT 0
#define MW_I2C_MODULECLOCKPRESCALER 9
#define MW_I2C_MODULECLOCKFREQUENCY 6000000
#define MW_I2C_MASTERCLKLOWTIME 5
#define MW_I2C_MASTERCLKHIGHTIME 5
#define MW_I2C_MASTERCLOCKFREQUENCY 300000
#define MW_I2C_ENABLELOOPBACK 0
#define MW_I2C_ENABLETXINT 0
#define MW_I2C_TXFIFOLEVEL 4
#define MW_I2C_ENABLERXINT 0
#define MW_I2C_RXFIFOLEVEL 4
#define MW_I2C_ENABLESYSINT 0
#define MW_I2C_AAS 0
#define MW_I2C_SCD 0
#define MW_I2C_ARDY 0
#define MW_I2C_NACK 0
#define MW_I2C_AL 0
#define MW_SCI_A_ENABLELOOPBACK 0
#define MW_SCI_A_SUSPENSIONMODE 2
#define MW_SCI_A_NUMBEROFSTOPBITS 0
#define MW_SCI_A_PARITYMODE 0
#define MW_SCI_A_CHARACTERLENGTHBITS 0
#define MW_SCI_A_USERBAUDRATE 115200
#define MW_SCI_A_BAUDRATEPRESCALER 64.000000
#define MW_SCI_A_BAUDRATE 115385.000000
#define MW_SCI_A_COMMUNICATIONMODE 0
#define MW_SCI_A_BLOCKINGMODE 0
#define MW_SCI_A_DATABYTEORDER 0
#define MW_SCI_A_DATASWAPWIDTH 0
#define MW_SCI_A_PINASSIGNMENT_TX 2
#define MW_SCI_A_PINASSIGNMENT_RX 2
#define MW_SPI_A_MODE 0
#define MW_SPI_A_USERBAUDRATE 117188
#define MW_SPI_A_BAUDRATEFACTOR 127.000000
#define MW_SPI_A_BAUDRATE 468750.000000
#define MW_SPI_A_DATABITS 15
#define MW_SPI_A_CLOCKPOLARITY 0
#define MW_SPI_A_CLOCKPHASE 0
#define MW_SPI_A_SUSPENSIONMODE 2
#define MW_SPI_A_ENABLELOOPBACK 0
#define MW_SPI_A_ENABLETHREEWIRE 0
#define MW_SPI_A_FIFOENABLE 0
#define MW_SPI_A_FIFOINTERRUPTLEVEL_RX 4
#define MW_SPI_A_FIFOINTERRUPTLEVEL_TX 0
#define MW_SPI_A_FIFOTRANSMITDELAY 0
#define MW_SPI_A_PINASSIGNMENT_SOMI 0
#define MW_SPI_A_PINASSIGNMENT_SIMO 0
#define MW_SPI_B_MODE 0
#define MW_SPI_B_USERBAUDRATE 117188
#define MW_SPI_B_BAUDRATEFACTOR 127.000000
#define MW_SPI_B_BAUDRATE 468750.000000
#define MW_SPI_B_DATABITS 15
#define MW_SPI_B_CLOCKPOLARITY 0
#define MW_SPI_B_CLOCKPHASE 0
#define MW_SPI_B_SUSPENSIONMODE 2
#define MW_SPI_B_ENABLELOOPBACK 0
#define MW_SPI_B_ENABLETHREEWIRE 0
#define MW_SPI_B_FIFOENABLE 0
#define MW_SPI_B_FIFOINTERRUPTLEVEL_RX 4
#define MW_SPI_B_FIFOINTERRUPTLEVEL_TX 0
#define MW_SPI_B_FIFOTRANSMITDELAY 0
#define MW_SPI_B_PINASSIGNMENT_CLK 0
#define MW_SPI_B_PINASSIGNMENT_SOMI 0
#define MW_SPI_B_PINASSIGNMENT_STE 0
#define MW_SPI_B_PINASSIGNMENT_SIMO 0
#define MW_WATCHDOG_ENABLE_WATCHDOG 0
#define MW_WATCHDOG_WATCHDOGCLOCK 0
#define MW_WATCHDOG_TIME_PERIOD 0.013107
#define MW_WATCHDOG_WATCHDOGEVENT 0
#define MW_GPIO0_7_GPIOQUALSEL0 0
#define MW_GPIO0_7_GPIOQUALSEL1 0
#define MW_GPIO0_7_GPIOQUALSEL2 0
#define MW_GPIO0_7_GPIOQUALSEL3 0
#define MW_GPIO0_7_GPIOQUALSEL4 0
#define MW_GPIO0_7_GPIOQUALSEL5 0
#define MW_GPIO0_7_GPIOQUALSEL6 0
#define MW_GPIO0_7_GPIOQUALSEL7 0
#define MW_GPIO0_7_QUALPRD 0
#define MW_GPIO8_15_GPIOQUALSEL8 0
#define MW_GPIO8_15_GPIOQUALSEL9 0
#define MW_GPIO8_15_GPIOQUALSEL10 0
#define MW_GPIO8_15_GPIOQUALSEL11 0
#define MW_GPIO8_15_GPIOQUALSEL12 0
#define MW_GPIO8_15_GPIOQUALSEL13 0
#define MW_GPIO8_15_GPIOQUALSEL14 0
#define MW_GPIO8_15_GPIOQUALSEL15 0
#define MW_GPIO8_15_QUALPRD 0
#define MW_GPIO16_23_GPIOQUALSEL16 0
#define MW_GPIO16_23_GPIOQUALSEL17 0
#define MW_GPIO16_23_GPIOQUALSEL18 0
#define MW_GPIO16_23_GPIOQUALSEL19 0
#define MW_GPIO16_23_GPIOQUALSEL20 0
#define MW_GPIO16_23_GPIOQUALSEL21 0
#define MW_GPIO16_23_GPIOQUALSEL22 0
#define MW_GPIO16_23_GPIOQUALSEL23 0
#define MW_GPIO16_23_QUALPRD 0
#define MW_GPIO24_31_GPIOQUALSEL24 0
#define MW_GPIO24_31_GPIOQUALSEL25 0
#define MW_GPIO24_31_GPIOQUALSEL26 0
#define MW_GPIO24_31_GPIOQUALSEL27 0
#define MW_GPIO24_31_GPIOQUALSEL28 0
#define MW_GPIO24_31_GPIOQUALSEL29 0
#define MW_GPIO24_31_GPIOQUALSEL30 0
#define MW_GPIO24_31_GPIOQUALSEL31 0
#define MW_GPIO24_31_QUALPRD 0
#define MW_GPIO32_39_GPIOQUALSEL32 0
#define MW_GPIO32_39_GPIOQUALSEL33 0
#define MW_GPIO32_39_GPIOQUALSEL34 0
#define MW_GPIO32_39_GPIOQUALSEL39 0
#define MW_GPIO32_39_QUALPRD 0
#define MW_GPIO40_44_GPIOQUALSEL40 0
#define MW_GPIO40_44_GPIOQUALSEL41 0
#define MW_GPIO40_44_GPIOQUALSEL42 0
#define MW_GPIO40_44_GPIOQUALSEL43 0
#define MW_GPIO40_44_GPIOQUALSEL44 0
#define MW_GPIO40_44_QUALPRD 0
#define MW_LIN_MODULECLOCKFREQUENCY 30
#define MW_LIN_ENABLELOOPBACK 0
#define MW_LIN_SUSPENSIONMODE 1
#define MW_LIN_PARITYMODE 0
#define MW_LIN_FRAMELENGTHBYTES 7
#define MW_LIN_BAUDRATEPRESCALER 15
#define MW_LIN_BAUDRATEM 4
#define MW_LIN_BAUDRATE 115384
#define MW_LIN_COMMUNICATIONMODE 0
#define MW_LIN_DATABYTEORDER 0
#define MW_LIN_DATASWAPWIDTH 0
#define MW_LIN_PINASSIGNMENT_TX 1
#define MW_LIN_PINASSIGNMENT_RX 1
#define MW_LIN_MASTERCLK 0
#define MW_LIN_IDFILTERING 1
#define MW_LIN_LINID 0x3A
#define MW_LIN_LINIDSLAVETASKBYTE 0x30
#define MW_LIN_CHECKSUMTYPE 0
#define MW_LIN_BUFFERMODE 1
#define MW_LIN_ADAPTMODE 0
#define MW_LIN_SYNCFIELDERRINT 0
#define MW_LIN_NORESPERRINT 0
#define MW_LIN_TIMEOUT3WAKEUP 0
#define MW_LIN_TIMEOUTWAKEUP 0
#define MW_LIN_TIMEOUTINT 0
#define MW_LIN_WAKEUPINT 0
#define MW_FLASH_LOADER_ENABLE_FLASH 0
#define MW_FLASH_LOADER_AUTOMATIC 1
#define MW_FLASH_LOADER_SECTORA 1
#define MW_FLASH_LOADER_SECTORB 1
#define MW_FLASH_LOADER_SECTORC 1
#define MW_FLASH_LOADER_SECTORD 1
#define MW_FLASH_LOADER_SECTORE 1
#define MW_FLASH_LOADER_SECTORF 1
#define MW_FLASH_LOADER_SECTORG 1
#define MW_FLASH_LOADER_SECTORH 1
#define MW_FLASH_LOADER_API_DIR C:/TI/controlSUITE/libs/utilities/flash_api/2803x/v100/lib/2803x_FlashAPI_BootROMSymbols.lib
#define MW_FLASH_LOADER_APIBROWSE 0
#define MW_FLASH_LOADER_APIEXECUTE 0
#define MW_MULTI_TASKING_MODE 1

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif
