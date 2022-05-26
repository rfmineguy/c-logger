#ifndef LOGGER_H
#define LOGGER_H

#define LOG_ENABLED      1
#define FILE_LOG_ENABLED 1

#define LOG_DEBUG        0
#define LOG_WARN         1
#define LOG_ERROR        2
#define LOG_CRITICAL     3

#include <stdio.h>
#include <stdarg.h>


//
//CONSOLE LOGGING FUNCTIONS
//
void logger_log_v(int, const char*, va_list);
void logger_log(int, const char*, ...);
void logger_debug(const char*, ...);
void logger_warn(const char*, ...);
void logger_err(const char*, ...);
void logger_critical(const char*, ...);

//
//FILE LOGGING FUNCTIONS
//
void logger_flog_v(FILE*, int, const char*, va_list);
void logger_flog(FILE*, int, const char*, ...);
void logger_fdebug(FILE*, const char*, ...);
void logger_fwarn(FILE*, const char*, ...);
void logger_ferr(FILE*, const char*, ...);
void logger_fcritical(FILE*, const char*, ...);

// file log

#endif
