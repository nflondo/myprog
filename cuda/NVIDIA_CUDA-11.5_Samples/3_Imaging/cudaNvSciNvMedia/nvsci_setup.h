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

#ifndef __NVSCI_SETUP_H__
#define __NVSCI_SETUP_H__
#include "nvmedia_utils/cmdline.h"
#include <nvscibuf.h>
#include <nvscisync.h>

void setupNvMediaSignalerNvSciSync(Blit2DTest* ctx, NvSciSyncObj &syncObj, int cudaDeviceId);
void setupCudaSignalerNvSciSync(Blit2DTest* ctx, NvSciSyncObj &syncObj, int cudaDeviceId);
void setupNvSciBuf(NvSciBufObj &bufobj, NvSciBufAttrList &nvmediaAttrlist, int cudaDeviceId);
void cleanupNvSciBuf(NvSciBufObj &Bufobj);
void cleanupNvSciSync(NvSciSyncObj &syncObj);
#endif