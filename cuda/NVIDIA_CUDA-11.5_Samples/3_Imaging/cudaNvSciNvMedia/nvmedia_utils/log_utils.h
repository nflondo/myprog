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

#ifndef _NVMEDIA_TEST_LOG_UTILS_H_
#define _NVMEDIA_TEST_LOG_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stdio.h>

enum LogLevel {
    LEVEL_ERR  = 0,
    LEVEL_WARN = 1,
    LEVEL_INFO = 2,
    LEVEL_DBG  = 3,
};

enum LogStyle {
    LOG_STYLE_NORMAL = 0,
    LOG_STYLE_FUNCTION_LINE
};

#define LINE_INFO       __FUNCTION__, __LINE__
#define LOG_DBG(...)    LogLevelMessage(LEVEL_DBG, LINE_INFO, __VA_ARGS__)
#define LOG_INFO(...)   LogLevelMessage(LEVEL_INFO, LINE_INFO, __VA_ARGS__)
#define LOG_WARN(...)   LogLevelMessage(LEVEL_WARN, LINE_INFO, __VA_ARGS__)

//  SetLogLevel
//
//    SetLogLevel()  Set logging level
//
//  Arguments:
//
//   level
//      (in) Logging level

void
SetLogLevel(
    enum LogLevel level);

//  SetLogStyle
//
//    SetLogStyle()  Set logging print slyle
//
//  Arguments:
//
//   level
//      (in) Logging style

void
SetLogStyle(
    enum LogStyle style);

//  SetLogFile
//
//    SetLogFile()  Set logging file handle
//
//  Arguments:
//
//   level
//      (in) Logging file handle

void
SetLogFile(
    FILE *logFileHandle);

//  LogLevelMessage
//
//    LogLevelMessage()  Print message if logging level is higher than message level
//
//  Arguments:
//
//   LogLevel
//      (in) Message level
//
//   format
//      (in) Message format
//
//   ...
//      (in) Parameters list

void
LogLevelMessage(
    enum LogLevel level,
    const char *functionName,
    int lineNumber,
    const char *format,
    ...);

#ifdef __cplusplus
}
#endif

#endif /* _NVMEDIA_TEST_LOG_UTILS_H_ */
