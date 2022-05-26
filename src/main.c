#include <stdio.h>
#include <time.h>
#include "logger.h"

int main() {
    int x;
    FILE* file = NULL;
    if ((file = fopen("log.txt", "w"))) {
        logger_log(LOG_DEBUG, "Succesfully opened file");
    }
    clock_t t;
    t = clock();
    logger_debug("Info test %c", '4');
    t = clock() - t;
    printf("logger_debug took %f seconds\n", ((double)t)/CLOCKS_PER_SEC);

    logger_warn("Warning test %d", 4);
    logger_err("Hello %d", 1);
    logger_critical("Critical test %p", &x);
    logger_fdebug(file, "Info file %d", '3');
    logger_fcritical(file, "Failed to write to disk");
    logger_fwarn(file, "Warn test");
    logger_debug("Hello World %s", "test");
    printf("Test\n");

    if (file != NULL)
        fclose(file);
}
