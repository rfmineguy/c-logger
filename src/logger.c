#include "logger.h"
#include <string.h>

int file_io_enabled = 0;

void logger_log(int level, const char* fmt, ...) {
    char prefix[255] = "";
    char buffer[255] = "";
    switch (level) {
    case LOG_DEBUG:     strcpy(prefix, "\033[0;36mDEBUG : \t"); break;
    case LOG_WARN:      strcpy(prefix, "\033[0;33mWARNING : \t"); break;
    case LOG_ERROR:     strcpy(prefix, "\033[0;31mERROR : \t"); break;
    case LOG_CRITICAL:  strcpy(prefix, "\033[0;35mCRITICAL : \t"); break;
    default:            strcpy(prefix, ""); break;
    }
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    strcat(prefix, buffer);
    printf("%s\n", prefix);
    va_end(args);
}

void logger_flog(FILE* filePtr, int level, const char* fmt, ...) {
    if (filePtr == NULL) {
        logger_log(LOG_CRITICAL, "File pointer %p, not valid\n");
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
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    strcat(prefix, buffer);
    fprintf(filePtr, "%s\n", prefix);
    va_end(args);
}
