/*
 * Copyright 1993-2020 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

#ifndef COMP_MALLOC_H
#define COMP_MALLOC_H

cudaError_t allocateCompressible(void **adr, size_t size, bool UseCompressibleMemory);
cudaError_t freeCompressible(void *ptr, size_t size, bool UseCompressibleMemory);

#endif
