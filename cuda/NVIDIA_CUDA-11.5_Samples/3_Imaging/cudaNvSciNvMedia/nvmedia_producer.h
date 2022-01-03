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

#ifndef __NVMEDIA_PRODUCER_H__
#define __NVMEDIA_PRODUCER_H__
#include "nvmedia_utils/cmdline.h"
#include "nvmedia_image.h"
#include "nvmedia_2d.h"
#include "nvmedia_surface.h"
#include "nvmedia_utils/image_utils.h"
#include "nvmedia_image_nvscibuf.h"
#include "nvscisync.h"

void runNvMediaBlit2D(TestArgs* args, Blit2DTest* ctx, NvSciSyncObj &syncObj, 
                      NvSciSyncFence *preSyncFence, NvSciSyncFence *fence);
void runNvMediaBlit2D(TestArgs* args, Blit2DTest* ctx);
void setupNvMedia(TestArgs* args, Blit2DTest* ctx, NvSciBufObj &srcNvSciBufobj,
                  NvSciBufObj& dstNvSciBufobj, NvSciSyncObj &syncObj, NvSciSyncObj &preSyncObj,
                  int cudaDeviceId);
void setupNvMedia(TestArgs* args, Blit2DTest* ctx);
void cleanupNvMedia(Blit2DTest* ctx, NvSciSyncObj &syncObj, NvSciSyncObj &preSyncObj);
void cleanupNvMedia(Blit2DTest* ctx);
#endif
