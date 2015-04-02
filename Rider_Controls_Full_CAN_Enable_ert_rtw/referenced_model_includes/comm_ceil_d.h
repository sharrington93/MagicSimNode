/* 
 *  comm_ceil_d.h
 *
 * Double precision CEIL 
 *  (to get rid of __imp__ceil function call in comm_sim_rt.lib)
 *  
 *  Copyright 2007 The MathWorks, Inc.
 */
#ifndef __COMM_CEIL_D_H__
#define __COMM_CEIL_D_H__

#ifdef __cplusplus
extern "C" {
#endif

extern int commCeil_D(double x);

#ifdef __cplusplus
} // end of extern "C" scope
#endif

#endif /* __COMM_CEIL_D_H__ */

