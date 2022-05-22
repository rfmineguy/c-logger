#ifndef LOGGER_H
#define LOGGER_H

#define LOG_DEBUG       0
#define LOG_WARN        1
#define LOG_ERROR       2
#define LOG_CRITICAL    3

#include <stdarg.h>
void logger_log(int level, const char*, ...);

#endif
