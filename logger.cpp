#include "logger.h"
#include <iostream>

bool Syslog::logToStdout_ = false;

void Syslog::initialize(int logLevel, const std::string& appName, bool logToStdout) {
    openlog(appName.c_str(), LOG_PID, LOG_USER);
    setlogmask(LOG_UPTO(logLevel));
    logToStdout_ = logToStdout;
}

void Syslog::log(int logLevel, const std::string& message) {
    syslog(logLevel, "%s", message.c_str());
    if (logToStdout_) {
        std::cout << message << std::endl;
    }
}

void Syslog::close() {
    closelog();
}
