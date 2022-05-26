#include "logger.h"
#include <string.h>

int file_io_enabled = 0;

void logger_log_v(int level, const char* fmt, va_list args) {
#if LOG_ENABLED == 0
    return;
#endif
    char prefix[255] = "";
    char buffer[255] = "";
    switch (level) {
    case LOG_DEBUG:     strcpy(prefix, "\033[0;36mDEBUG : \t"); break;
    case LOG_WARN:      strcpy(prefix, "\033[0;33mWARNING : \t"); break;
    case LOG_ERROR:     strcpy(prefix, "\033[0;31mERROR : \t"); break;
    case LOG_CRITICAL:  strcpy(prefix, "\033[0;35mCRITICAL : \t"); break;
    default:            strcpy(prefix, ""); break;
    }
    vsprintf(buffer, fmt, args);
    strcat(prefix, buffer);
    printf("%s\n", prefix);
}

void logger_log(int level, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_log_v(level, fmt, args);
    va_end(args);
}

void logger_debug(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_log_v(LOG_DEBUG, fmt, args);
    va_end(args);
}
void logger_warn(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_log_v(LOG_WARN, fmt, args);
    va_end(args);
}
void logger_err(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_log_v(LOG_ERROR, fmt, args);
    va_end(args);
}
void logger_critical(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_log_v(LOG_CRITICAL, fmt, args);
    va_end(args);
}

void logger_flog_v(FILE* filePtr, int level, const char* fmt, va_list args) {
#if FILE_LOG_ENABLED == 0
    return;
#endif
    if (filePtr == NULL) {
        logger_critical("File pointer %p, not valid\n");
        return;
    }
    char prefix[255] = "";
    char buffer[255] = "";
    switch(level) {
    case LOG_DEBUG:     strcpy(prefix, "\033[0;36mDEBUG : \t"); break;
    case LOG_WARN:      strcpy(prefix, "\033[0;33mWARNING : \t"); break;
    case LOG_ERROR:     strcpy(prefix, "\033[0;31mERROR : \t"); break;
    case LOG_CRITICAL:  strcpy(prefix, "\033[0;35mCRITICAL : \t"); break;
    default:            strcpy(prefix, ""); break;
    }
    vsprintf(buffer, fmt, args);
    strcat(prefix, buffer);
    fprintf(filePtr, "%s\n", prefix);
}

void logger_flog(FILE* filePtr, int level, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_flog_v(filePtr, level, fmt, args);
    va_end(args);
}

void logger_fdebug(FILE* filePtr, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_flog_v(filePtr, LOG_DEBUG, fmt, args);
    va_end(args);
}
void logger_fwarn(FILE* filePtr, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_flog_v(filePtr, LOG_WARN, fmt, args);
    va_end(args);
}
void logger_ferr(FILE* filePtr, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_flog_v(filePtr, LOG_ERROR, fmt, args);
    va_end(args);
}
void logger_fcritical(FILE* filePtr, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logger_flog_v(filePtr, LOG_CRITICAL, fmt, args);
    va_end(args);
}
