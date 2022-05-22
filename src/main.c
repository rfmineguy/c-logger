#include <stdio.h>
#include "logger.h"

int main() {
    int x;
    logger_log(LOG_DEBUG, "Info test %c", '4');
    logger_log(LOG_WARN, "Warning test %d", 4);
    logger_log(LOG_ERROR, "Hello %d", 1);
    logger_log(LOG_CRITICAL, "Critical test %p", &x);
}
