#ifndef LOGGER_H
#define LOGGER_H

#define LOG_DEBUG       0
#define LOG_WARN        1
#define LOG_ERROR       2
#define LOG_CRITICAL    3

#include <stdio.h>
#include <stdarg.h>

void logger_log(int level, const char*, ...);
void logger_flog(FILE*, int level, const char*, ...);


// file log

#endif
