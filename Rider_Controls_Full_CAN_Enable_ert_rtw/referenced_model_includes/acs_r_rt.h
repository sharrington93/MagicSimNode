/*
 *  File: acs_r_rt.h
 * 
 *  Header file for the Add-Compare-Select function of the Viterbi Algorithm.
 *  Used by scommlseeq.tlc, scomtcmdec.tlc and scomviterbi2.tlc.
 *
 *  Copyright 2005-2006 The MathWorks, Inc.
 */

#ifndef __ACS_R_RT_H__
#define __ACS_R_RT_H__

#include <string.h>
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Add-Compare-Select for Single precision */
int_T ACS_R(const int_T     numStates, /* no. of states, 2^(consLen-1) */     
                  real32_T *pTempMet,  /* ptr temp metric, numStates (nS) */        
            const int_T     alpha,     /* output number of symbols = 2^k*/          
                  real32_T *pBMet,     /* ptr branch metric, 2^n */                 
                  real32_T *pStateMet, /* ptr state metric, nS */                   
                  uint32_T *pTbState,  /* ptr traceback state, nS*(tbLen+1) */      
                  uint32_T *pTbInput,  /* ptr traceback input, nS*(tblen+1) */      
                  int32_T  *pTbPtr,    /* ptr traceback, 1 */                       
            const uint32_T *pNxtSt,    /* ptr next state, numStates * 2^k */        
            const uint32_T *pEncOut,   /* ptr output, numStates * 2^k */            
            const real32_T *maxValue   /* Maximum state value */
    );

#ifdef __cplusplus
} // end of extern "C" scope
#endif

#endif  /* __ACS_R_RT_H__ */

/* EOF */
