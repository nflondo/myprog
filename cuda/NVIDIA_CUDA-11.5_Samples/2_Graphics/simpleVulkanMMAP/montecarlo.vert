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
 
#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 0) uniform UniformBufferObject {
    float frame;
} ubo;

layout(location = 0) in float pointInsideCircle;
layout(location = 1) in vec2 xyPos;
 
layout(location = 0) out vec3 fragColor;
 
const float PI = 3.1415926;
 
out gl_PerVertex
{
    vec4 gl_Position;
    float gl_PointSize;
};
 
void main() {
    gl_PointSize = 1.0;
    gl_Position = vec4(xyPos.xy, 0.0f, 1.0f);
    float color_r = 1.0f + 0.5f * sin(ubo.frame / 100.0f);
    float color_g = 1.0f + 0.5f * sin((ubo.frame / 100.0f) + (2.0f*PI/3.0f));
    float color_b = 1.0f;
    fragColor = vec3(pointInsideCircle.x * color_r, pointInsideCircle.x * color_g, color_b);
}
