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

#include "nvmedia_utils/cmdline.h"
#include <cuda.h>
#include <cuda_runtime.h>
#include "helper_cuda.h"
#include "nvsci_setup.h"
#include "nvmedia_2d_nvscisync.h"


#define checkNvSciErrors(call)                              \
  do {                                                      \
    NvSciError _status = call;                              \
    if (NvSciError_Success != _status) {                    \
      printf(                                               \
          "NVSCI call in file '%s' in line %i returned"     \
          " %d, expected %d\n",                             \
          __FILE__, __LINE__, _status, NvSciError_Success); \
      fflush(stdout);                                       \
      exit(EXIT_FAILURE);                                   \
    }                                                       \
   } while (0)

void setupNvMediaSignalerNvSciSync(Blit2DTest* ctx, NvSciSyncObj &syncObj, int cudaDeviceId)
{
    NvSciSyncModule sciSyncModule;
    checkNvSciErrors(NvSciSyncModuleOpen(&sciSyncModule));
    NvSciSyncAttrList signalerAttrList, waiterAttrList;
    NvSciSyncAttrList syncUnreconciledList[2];
    NvSciSyncAttrList syncReconciledList, syncConflictList;

    checkNvSciErrors(NvSciSyncAttrListCreate(sciSyncModule, &signalerAttrList));
    checkNvSciErrors(NvSciSyncAttrListCreate(sciSyncModule, &waiterAttrList));

    NvMediaStatus status = NvMedia2DFillNvSciSyncAttrList(ctx->i2d, signalerAttrList, NVMEDIA_SIGNALER);
    if(status != NVMEDIA_STATUS_OK) {
        printf("%s: NvMedia2DFillNvSciSyncAttrList failed\n",__func__);
        exit(EXIT_FAILURE);
    }

    checkCudaErrors(cudaSetDevice(cudaDeviceId));
    checkCudaErrors(cudaDeviceGetNvSciSyncAttributes(waiterAttrList, cudaDeviceId, cudaNvSciSyncAttrWait));

    syncUnreconciledList[0] = signalerAttrList;
    syncUnreconciledList[1] = waiterAttrList;
    checkNvSciErrors(NvSciSyncAttrListReconcile(syncUnreconciledList, 2, &syncReconciledList, &syncConflictList));
    checkNvSciErrors(NvSciSyncObjAlloc(syncReconciledList, &syncObj));

    NvSciSyncAttrListFree(signalerAttrList);
    NvSciSyncAttrListFree(waiterAttrList);
    if(syncConflictList != nullptr) {
        NvSciSyncAttrListFree(syncConflictList);
    }
}

void setupCudaSignalerNvSciSync(Blit2DTest* ctx, NvSciSyncObj &syncObj, int cudaDeviceId)
{
    NvSciSyncModule sciSyncModule;
    checkNvSciErrors(NvSciSyncModuleOpen(&sciSyncModule));
    NvSciSyncAttrList signalerAttrList, waiterAttrList;
    NvSciSyncAttrList syncUnreconciledList[2];
    NvSciSyncAttrList syncReconciledList, syncConflictList;

    checkNvSciErrors(NvSciSyncAttrListCreate(sciSyncModule, &signalerAttrList));
    checkNvSciErrors(NvSciSyncAttrListCreate(sciSyncModule, &waiterAttrList));

    NvMediaStatus status = NvMedia2DFillNvSciSyncAttrList(ctx->i2d, waiterAttrList, NVMEDIA_WAITER);
    if(status != NVMEDIA_STATUS_OK) {
        printf("%s: NvMedia2DFillNvSciSyncAttrList failed\n",__func__);
        exit(EXIT_FAILURE);
    }

    checkCudaErrors(cudaSetDevice(cudaDeviceId));
    checkCudaErrors(cudaDeviceGetNvSciSyncAttributes(signalerAttrList, cudaDeviceId, cudaNvSciSyncAttrSignal));

    syncUnreconciledList[0] = signalerAttrList;
    syncUnreconciledList[1] = waiterAttrList;
    checkNvSciErrors(NvSciSyncAttrListReconcile(syncUnreconciledList, 2, &syncReconciledList, &syncConflictList));
    checkNvSciErrors(NvSciSyncObjAlloc(syncReconciledList, &syncObj));

    NvSciSyncAttrListFree(signalerAttrList);
    NvSciSyncAttrListFree(waiterAttrList);
    if(syncConflictList != nullptr) {
        NvSciSyncAttrListFree(syncConflictList);
    }
}


void setupNvSciBuf(NvSciBufObj &bufobj, NvSciBufAttrList &nvmediaAttrlist, int cudaDeviceId)
{
    CUuuid devUUID;
    NvSciBufAttrList conflictlist;
    NvSciBufAttrList bufUnreconciledAttrlist[1];

    CUresult res = cuDeviceGetUuid_v2(&devUUID, cudaDeviceId);
    if (res != CUDA_SUCCESS) {
      fprintf(stderr, "Driver API error = %04d \n", res);
      exit(EXIT_FAILURE);
    }

    NvSciBufAttrKeyValuePair attr_gpuid[] = {NvSciBufGeneralAttrKey_GpuId, &devUUID, sizeof(devUUID)};

    // set CUDA GPU ID to attribute list
    checkNvSciErrors(NvSciBufAttrListSetAttrs(nvmediaAttrlist, attr_gpuid, sizeof(attr_gpuid)/sizeof(NvSciBufAttrKeyValuePair)));

    bufUnreconciledAttrlist[0] = nvmediaAttrlist;

    checkNvSciErrors(NvSciBufAttrListReconcileAndObjAlloc(bufUnreconciledAttrlist,
                                               1,
                                               &bufobj,
                                               &conflictlist));
    if (conflictlist != NULL) {
        NvSciBufAttrListFree(conflictlist);
    }
}

void cleanupNvSciBuf(NvSciBufObj &Bufobj)
{
    if (Bufobj != NULL) {
        NvSciBufObjFree(Bufobj);
    }
}

void cleanupNvSciSync(NvSciSyncObj &syncObj)
{
    if (NvSciSyncObjFree != NULL) {
        NvSciSyncObjFree(syncObj);
    }
}
