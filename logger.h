#ifndef PUTHTTPD_LOGGER_H
#define PUTHTTPD_LOGGER_H

#include "types.h"

enum LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARN = 2,
    ERR = 3
};


int init_logger(s_string logfile, enum LogLevel logVerbosity);
void message_log(char message[], enum LogLevel level);
void string_log(s_string *message, enum LogLevel level);
int shutdown_logger();

#endif //PUTHTTPD_LOGGER_H
