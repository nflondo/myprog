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

#ifndef _NVMEDIA_2D_CMD_LINE_H_
#define _NVMEDIA_2D_CMD_LINE_H_

/* Include header containing NvMedia2D declarations */
#include "nvmedia_2d.h"

/* Maximum length of the path including file name */
#define FILE_NAME_SIZE 1024

/* TestArgs contains all arguments required to run the 2D test */
typedef struct _TestArgs {
    char inputFileName[FILE_NAME_SIZE];

    NvMediaSurfAllocAttr srcSurfAllocAttrs[NVM_SURF_ALLOC_ATTR_MAX];
    NvMediaSurfAllocAttr dstSurfAllocAttrs[NVM_SURF_ALLOC_ATTR_MAX];
    uint32_t numSurfAllocAttrs;

    NvMediaSurfFormatAttr srcSurfFormatAttrs[NVM_SURF_FMT_ATTR_MAX];
    NvMediaSurfFormatAttr dstSurfFormatAttrs[NVM_SURF_FMT_ATTR_MAX];

    NvMediaRect srcRect;
    NvMediaRect dstRect;
    NvMedia2DBlitParameters     blitParams;
    size_t iterations;
} TestArgs;

typedef struct {
    NvMediaDevice               *device;
    /* I2D for 2D blit processing */
    NvMedia2D                   *i2d;
    NvMediaImage                *srcImage;
    NvMediaImage                *dstImage;
    NvMediaRect                 *srcRect;
    NvMediaRect                 *dstRect;
    uint8_t                     **dstBuff;
    uint32_t                    *dstBuffPitches;
    uint8_t                     *dstBuffer;
    uint32_t                    numSurfaces;
    uint32_t                    bytesPerPixel;
    uint32_t                    heightSurface;
    uint32_t                    widthSurface;
    float                       *xScalePtr;
    float                       *yScalePtr;

} Blit2DTest;

/* Prints application usage options */
void PrintUsage (void);

/* Parses command line arguments.
* Also parses any configuration files supplied in the command line arguments.
* Arguments:
* argc
*    (in) Number of tokens in the command line
* argv
*    (in) Command line tokens
* args
*    (out) Pointer to test arguments structure
*/
int  ParseArgs(int argc, char **argv, TestArgs *args);

#endif /* _NVMEDIA_2D_CMD_LINE_H_ */
