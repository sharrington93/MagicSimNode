/*
 *  File: llr_r_rt.h
 * 
 *  Header file for the LLR function of the Soft Demodulation feature.
 *
 *  Copyright 2006-2013 The MathWorks, Inc.
 *
 */

#ifndef __LLR_R_RT_H__
#define __LLR_R_RT_H__

#include "dsp_rt.h"
#ifdef MW_COMM_RT
#include "comm_rt/complexops.h"
#else
#include "complexops.h"
#endif
#include "spc_decl.h"

#ifdef __cplusplus
extern "C" {
#endif

/* LLR for Double types */

SPC_DECL void llr_r(const cArray32   inputSignal,    /* input signal */
           const int_T      numElements,    /* number of input signal elements */
           const real32_T  *noiseVariance,  /* noise variance */
           const int_T      M,              /* M            */
           const int_T      nBits,          /* number of bits in symbol (log2(M)) */
           const cArray32   constellation,  /* signal constellation */
           const int32_T   *S0,             /* symbols having 0 */
           const int32_T   *S1,             /* symbols having 1 */
           real32_T        *llr             /* output values - LLR */
    );

#ifdef __cplusplus
} /* end of extern "C" scope */
#endif

#endif  /* __LLR_R_RT_H__ */

/* EOF */
