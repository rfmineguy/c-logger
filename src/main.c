#include <stdio.h>
#include "logger.h"

int main() {
    int x;
    FILE* file;
    if ((file = fopen("log.txt", "w"))) {
        logger_log(LOG_DEBUG, "Succesfully opened file");
    }
    logger_log(LOG_DEBUG, "Info test %c", '4');
    logger_log(LOG_WARN, "Warning test %d", 4);
    logger_log(LOG_ERROR, "Hello %d", 1);
    logger_log(LOG_CRITICAL, "Critical test %p", &x);
    logger_flog(file, LOG_DEBUG, "Info file %d", '3');

    if (file != NULL)
        fclose(file);
}
