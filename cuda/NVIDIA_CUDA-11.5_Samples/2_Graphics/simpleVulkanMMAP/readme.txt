Sample: simpleVulkanMMAP
Minimum spec: SM 3.5

 This sample demonstrates Vulkan CUDA Interop via cuMemMap APIs. CUDA exports buffers that Vulkan imports as vertex buffer. CUDA invokes kernels to operate on vertices and synchronizes with Vulkan through vulkan semaphores imported by CUDA. This sample depends on Vulkan SDK, GLFW3 libraries, for building this sample please refer to "Build_instructions.txt" provided in this sample's directory

Key concepts:
cuMemMap IPC
MMAP
Graphics Interop
CUDA Vulkan Interop
Data Parallel Algorithms
