/* 
 *  complexops.h
 *   Complex math definitions for code sharing between 
 *   the DSP System Toolbox and the Communications System Toolbox.
 *
 *  Copyright 1996-2010 The MathWorks, Inc.
 */

#ifndef __COMPLEXOPS_H__
#define __COMPLEXOPS_H__

#include "tmwtypes.h"

#ifdef USE_MXARRAY_COMPLEXOPS
    
    #include "comm_mx_util.h"

    #define cArray struct complexnumber
    #define Re(x, n) (x.re[n])
    #define Im(x, n) (x.im[n])
#else

    /* Simulink complex arrays, creal_T (interleaved real/imag parts) */
    #define cArray creal_T *
    #define Re(x, n) (x[n].re)
    #define Im(x, n) (x[n].im)

    /* Simulink complex arrays, creal32_T (interleaved real/imag parts) */
    #define cArray32 creal32_T *
    
#endif

#define cmult_Re(x, nx, y, ny) ( Re(x, nx)*Re(y, ny) - Im(x, nx)*Im(y, ny) )
#define cmult_Im(x, nx, y, ny) ( Re(x, nx)*Im(y, ny) + Im(x, nx)*Re(y, ny) )

#endif

/* [EOF] */
