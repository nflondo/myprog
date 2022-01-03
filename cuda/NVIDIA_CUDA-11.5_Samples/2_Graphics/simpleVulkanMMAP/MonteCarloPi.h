/*
 * Copyright 2019-2020 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

#pragma once
#ifndef __PISIM_H__
#define __PISIM_H__

#include <vector>
#include <cuda_runtime_api.h>
#include <curand.h>
#include <curand_kernel.h>
#include <cuda.h>

#include "helper_multiprocess.h"

typedef float vec2[2];

class MonteCarloPiSimulation
{
    size_t m_numPoints;

    // Pointers to Cuda allocated buffers which are imported and used by vulkan as vertex buffer
    vec2 *m_xyVector;
    float *m_pointsInsideCircle;

    // Pointers to device and host allocated memories storing number of points that are inside the unit circle
    float *m_numPointsInCircle;
    float *m_hostNumPointsInCircle;

    int m_blocks, m_threads;

    // Total size of allocations created by cuMemMap Apis. This size is the sum of sizes of
    // m_xyVector and m_pointsInsideCircle buffers.
    size_t m_totalAllocationSize;

    // Shareable Handles(a file descriptor on Linux and NT Handle on Windows), used for sharing cuda
    // allocated memory with Vulkan
    ShareableHandle m_posShareableHandle, m_inCircleShareableHandle;

    // Cuda Device corresponding to the Vulkan Physical device
    int m_cudaDevice;

    // Track and accumulate total points that have been simulated since start of the sample.
    // The idea is to get a closer approximation to PI with time.
    size_t m_totalPointsInsideCircle;
    size_t m_totalPointsSimulated;

    void setupSimulationAllocations();
    void cleanupSimulationAllocations();
    void getIdealExecutionConfiguration();

public:
    MonteCarloPiSimulation(size_t num_points);
    ~MonteCarloPiSimulation();
    void initSimulation(int cudaDevice, cudaStream_t stream = 0);
    void stepSimulation(float time, cudaStream_t stream = 0);
    static void computePiCallback(void *args);

    size_t getNumPoints() const {
        return m_numPoints;
    }

    float getNumPointsInCircle() const {
        return *m_hostNumPointsInCircle;
    }

    ShareableHandle &getPositionShareableHandle() {
        return m_posShareableHandle;
    }
    ShareableHandle &getInCircleShareableHandle() {
        return m_inCircleShareableHandle;
    }

};

#endif // __PISIM_H__
