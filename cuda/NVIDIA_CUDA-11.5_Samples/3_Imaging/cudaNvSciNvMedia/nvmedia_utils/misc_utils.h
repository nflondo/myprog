/*
 * Copyright 2020 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

#ifndef _NVMEDIA_TEST_MISC_UTILS_H_
#define _NVMEDIA_TEST_MISC_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "nvmedia_core.h"
#include "nvmedia_common.h"

#ifndef __INTEGRITY
#define MIN(a,b)             (((a) < (b)) ? (a) : (b))
#define MAX(a,b)             (((a) > (b)) ? (a) : (b))
#endif

typedef enum {
    LSB_ALIGNED,
    MSB_ALIGNED
} PixelAlignment;


//  u32
//
//    u32()  Reads 4 bytes from buffer and returns the read value
//
//  Arguments:
//
//   ptr
//      (in) Input buffer

uint32_t   u32(const uint8_t* ptr);

//  GetTimeMicroSec
//
//    GetTimeMicroSec()  Returns current time in microseconds
//
//  Arguments:
//
//   uTime
//      (out) Pointer to current time in microseconds

NvMediaStatus
GetTimeMicroSec(
    uint64_t *uTime);

#ifdef __cplusplus
}
#endif

#endif /* _NVMEDIA_TEST_MISC_UTILS_H_ */
