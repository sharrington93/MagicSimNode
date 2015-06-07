/*
 * File: rtwtypes.h
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

#ifndef __RTWTYPES_H__
#define __RTWTYPES_H__

/* Logical type definitions */
#if (!defined(__cplusplus))
#  ifndef false
#   define false                       (0U)
#  endif

#  ifndef true
#   define true                        (1U)
#  endif
#endif

#define __TMWTYPES__

/*=======================================================================*
 * Target hardware information
 *   Device type: Texas Instruments->C2000
 *   Number of bits:     char:  16    short:   16    int:  16
 *                       long:  32
 *                       native word size:  16
 *   Byte ordering: LittleEndian
 *   Signed integer division rounds to: Zero
 *   Shift right on a signed integer as arithmetic shift: on
 *=======================================================================*/
#ifdef PORTABLE_WORDSIZES              /* PORTABLE_WORDSIZES defined */

/*=======================================================================*
 * Host information
 *   Number of bits:     char:   8    short:   16    int:  32
 *                       long:  32
 *                       long long:  64
 *                       native word size:  32
 *=======================================================================*/

/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *   real32_T, real64_T           - 32 and 64 bit floating point numbers *
 *                                                                       *
 *                                                                       *
 *   Note:  Because the specified hardware does not have native support  *
 *          for all data sizes, some data types are actually typedef'ed  *
 *          from larger native data sizes.  The following data types are *
 *          not in the ideal native data types:                          *
 *                                                                       *
 *          int8_T, uint8_T                                              *
 *=======================================================================*/
typedef short int8_T;
typedef unsigned short uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
typedef float real32_T;
typedef double real64_T;

/*===========================================================================*
 * Generic type definitions: real_T, time_T, boolean_T, int_T, uint_T,       *
 *                           ulong_T, char_T , ulonglong_T and byte_T.       *
 *===========================================================================*/
typedef double real_T;
typedef double time_T;
typedef unsigned short boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned int ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

#else                                  /* PORTABLE_WORDSIZES not defined */

/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *   real32_T, real64_T           - 32 and 64 bit floating point numbers *
 *                                                                       *
 *                                                                       *
 *   Note:  Because the specified hardware does not have native support  *
 *          for all data sizes, some data types are actually typedef'ed  *
 *          from larger native data sizes.  The following data types are *
 *          not in the ideal native data types:                          *
 *                                                                       *
 *          int8_T, uint8_T                                              *
 *=======================================================================*/
typedef int int8_T;
typedef unsigned int uint8_T;
typedef int int16_T;
typedef unsigned int uint16_T;
typedef long int32_T;
typedef unsigned long uint32_T;
typedef float real32_T;
typedef double real64_T;

/*===========================================================================*
 * Generic type definitions: real_T, time_T, boolean_T, int_T, uint_T,       *
 *                           ulong_T, char_T and byte_T.                     *
 *===========================================================================*/
typedef double real_T;
typedef double time_T;
typedef unsigned int boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

#endif                                 /* PORTABLE_WORDSIZES */

/*===========================================================================*
 * Complex number type definitions                                           *
 *===========================================================================*/
#define CREAL_T

typedef struct {
  real32_T re;
  real32_T im;
} creal32_T;

typedef struct {
  real64_T re;
  real64_T im;
} creal64_T;

typedef struct {
  real_T re;
  real_T im;
} creal_T;

#define CINT8_T

typedef struct {
  int8_T re;
  int8_T im;
} cint8_T;

#define CUINT8_T

typedef struct {
  uint8_T re;
  uint8_T im;
} cuint8_T;

#define CINT16_T

typedef struct {
  int16_T re;
  int16_T im;
} cint16_T;

#define CUINT16_T

typedef struct {
  uint16_T re;
  uint16_T im;
} cuint16_T;

#define CINT32_T

typedef struct {
  int32_T re;
  int32_T im;
} cint32_T;

#define CUINT32_T

typedef struct {
  uint32_T re;
  uint32_T im;
} cuint32_T;

/*=======================================================================*
 * Min and Max:                                                          *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255U))
#define MIN_uint8_T                    ((uint8_T)(0U))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535U))
#define MIN_uint16_T                   ((uint16_T)(0U))
#define MAX_int32_T                    ((int32_T)(2147483647))
#define MIN_int32_T                    ((int32_T)(-2147483647-1))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))
#define MIN_uint32_T                   ((uint32_T)(0U))

/* Block D-Work pointer type */
typedef void * pointer_T;

/* Simulink specific types */
#ifndef __ZERO_CROSSING_TYPES__
#define __ZERO_CROSSING_TYPES__

/* Trigger directions: falling, either, and rising */
typedef enum {
  FALLING_ZERO_CROSSING = -1,
  ANY_ZERO_CROSSING = 0,
  RISING_ZERO_CROSSING = 1
} ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define UNINITIALIZED_ZCSIG            0x03U
#define NEG_ZCSIG                      0x02U
#define POS_ZCSIG                      0x01U
#define ZERO_ZCSIG                     0x00U

/* Current state of a trigger signal */
typedef enum {
  FALLING_ZCEVENT = -1,
  NO_ZCEVENT = 0,
  RISING_ZCEVENT = 1
} ZCEventType;

#endif                                 /* __ZERO_CROSSING_TYPES__ */
#endif                                 /* __RTWTYPES_H__ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
