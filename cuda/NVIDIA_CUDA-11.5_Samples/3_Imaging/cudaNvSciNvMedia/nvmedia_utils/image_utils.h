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

#ifndef _NVMEDIA_TEST_IMAGE_UTILS_H_
#define _NVMEDIA_TEST_IMAGE_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "misc_utils.h"
#include "nvmedia_core.h"
#include "nvmedia_surface.h"
#include "nvmedia_image.h"
#include "cmdline.h"

#if (NV_IS_SAFETY == 1)
#include "nvmedia_image_internal.h"
#endif

#define PACK_RGBA(R, G, B, A)  (((uint32_t)(A) << 24) | ((uint32_t)(B) << 16) | \
                                ((uint32_t)(G) << 8) | (uint32_t)(R))
#define DEFAULT_ALPHA   0x80




//  ReadImage
//
//    ReadImage()  Read image from file
//
//  Arguments:
//
//   filename
//      (in) Input file name
//
//   frameNum
//      (in) Frame number to read. Use for stream input files.
//
//   width
//      (in) Surface width
//
//   height
//      (in) Surface height
//
//   image
//      (out) Pointer to pre-allocated output surface
//
//   uvOrderFlag
//      (in) Flag for UV order. If true - UV; If false - VU;
//
//   bytesPerPixel
//      (in) Bytes per pixel. Nedded for RAW image types handling.
//         RAW8 - 1 byte per pixel
//         RAW10, RAW12, RAW14 - 2 bytes per pixel
//
//   pixelAlignment
//      (in) Alignment of bits in pixel.
//         0 - LSB Aligned
//         1 - MSB Aligned

NvMediaStatus
ReadImage(
    char *fileName,
    uint32_t frameNum,
    uint32_t width,
    uint32_t height,
    NvMediaImage *image,
    NvMediaBool uvOrderFlag,
    uint32_t bytesPerPixel,
    uint32_t pixelAlignment);

//  InitImage
//
//    InitImage()  Init image data to zeros
//
//  Arguments:
//
//   image
//      (in) image to initialize
//
//   width
//      (in) Surface width
//
//   height
//      (in) Surface height

NvMediaStatus
InitImage(
    NvMediaImage *image,
    uint32_t width,
    uint32_t height);

NvMediaStatus
AllocateBufferToWriteImage(
    Blit2DTest *ctx,
    NvMediaImage *image,
    NvMediaBool uvOrderFlag,
    NvMediaBool appendFlag);

//  WriteImageToBuffer
//
//    WriteImageToBuffer()  Save RGB or YUV image
//
NvMediaStatus
WriteImageToAllocatedBuffer(
    Blit2DTest *ctx,
    NvMediaImage *image,
    NvMediaBool uvOrderFlag,
    NvMediaBool appendFlag,
    uint32_t bytesPerPixel);

#ifdef __cplusplus
}
#endif

#endif /* _NVMEDIA_TEST_IMAGE_UTILS_H_ */
