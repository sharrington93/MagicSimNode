/* 
 *  gaussian.h
 *   Gaussian source (core C-code).
 *   Shared by MATLAB C-MEX function, SIMULINK C-MEX S-Function, and TLC.
 *
 *  Copyright 2009-2013 The MathWorks, Inc.
 * 
 */

#ifndef __GAUSSIAN_H__
#define __GAUSSIAN_H__

#include <math.h>
#ifdef MW_COMM_RT
#include "comm_rt/commrandn.h"
#include "comm_rt/complexops.h"
#else
#include "commrandn.h"
#include "complexops.h"
#endif
#include "spc_decl.h"

#ifdef __cplusplus
extern "C" {
#endif

SPC_DECL void generateGaussianSamples(int Nout, int NC, cArray w, real64_T *w2, real_T *WGNState, int legacyMode);

#ifdef __cplusplus
} // end of extern "C" scope
#endif

#endif

/* [EOF] */
