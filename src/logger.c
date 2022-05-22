#include "logger.h"
#include <stdio.h>
#include <string.h>

void logger_log(int level, const char* fmt, ...) {
    char prefix[255] = "";
    char buffer[255] = "";
    switch (level) {
    case LOG_DEBUG:      strcpy(prefix, "\033[0;36mDEBUG : \t"); break;
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
