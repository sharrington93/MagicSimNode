/*
 *  Header file for LDPC encoder kernel,
 *  used by Communications System Toolbox.
 *
 *  Copyright 2006-2013 The MathWorks, Inc.
 *
 */

#ifndef __LDPCENCODE_KERNEL_H__
#define __LDPCENCODE_KERNEL_H__

#include "tmwtypes.h"
#ifdef MW_COMM_RT
#include "comm_rt/ldpcdecode_kernel.h"
#else
#include "ldpcdecode_kernel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

SPC_DECL void LDPCEncodeKernel(      int8_T  *InformationBits,
                            int8_T  *ParityCheckBits,
                            int32_T NumInfoBits,
                            int32_T NumParityCheckBits,
                            int8_T  EncodingMethod,
                      const int32_T *A_RowIndices,
                      const int32_T *A_RowStartLoc,
                      const int32_T *A_ColumnSum,
                      const int32_T *B_RowIndices,
                      const int32_T *B_RowStartLoc,
                      const int32_T *B_ColumnSum,
                      const int32_T *L_RowIndices,
                      const int32_T *L_RowStartLoc,
                      const int32_T *L_ColumnSum,
                      const int32_T *RowOrder,
                            int8_T  *ReorderBuffer);

#ifdef __cplusplus
} // end of extern "C" scope
#endif

#endif /* __LDPCENCODE_KERNEL_H__ */

/* [EOF] */
