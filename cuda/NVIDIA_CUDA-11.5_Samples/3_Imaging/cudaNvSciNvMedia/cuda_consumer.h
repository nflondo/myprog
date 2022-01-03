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

#ifndef __CUDA_BUFIMPORT_KERNEL_H__
#define __CUDA_BUFIMPORT_KERNEL_H__

#include <cuda_runtime.h>
#include "helper_cuda.h"
#include "nvmedia_image_nvscibuf.h"
#include "nvscisync.h"
#include "nvmedia_utils/cmdline.h"

struct cudaExternalResInterop
{
    cudaMipmappedArray_t    *d_mipmapArray;
    cudaArray_t             *d_mipLevelArray;
    cudaSurfaceObject_t     *cudaSurfaceNvmediaBuf;
    cudaStream_t            stream;
    cudaExternalMemory_t    extMemImageBuf;
    cudaExternalSemaphore_t waitSem;
    cudaExternalSemaphore_t signalSem;

    int32_t                 planeCount;
    uint64_t                *planeOffset;
    int32_t                 *imageWidth;
    int32_t                 *imageHeight;
    unsigned int            *d_outputImage;
};

struct cudaResources
{
    cudaArray_t *d_yuvArray;
    cudaStream_t stream;
    cudaSurfaceObject_t *cudaSurfaceNvmediaBuf;
    unsigned int *d_outputImage;
};

void runCudaOperation(cudaExternalResInterop& cudaExtResObj, NvSciSyncFence *fence,
                        NvSciSyncFence *cudaSignalfence, int deviceId, int iterations);
void runCudaOperation(Blit2DTest *ctx, cudaResources &cudaResObj, int deviceId);

void setupCuda(cudaExternalResInterop& cudaExtResObj, NvSciBufObj& inputBufObj,
                NvSciSyncObj &syncObj, NvSciSyncObj &cudaSignalerSyncObj, int deviceId);
void setupCuda(Blit2DTest *ctx, cudaResources &cudaResObj, int deviceId);
void cleanupCuda(cudaExternalResInterop& cudaObjs);
void cleanupCuda(Blit2DTest *ctx, cudaResources &cudaResObj);

#endif
