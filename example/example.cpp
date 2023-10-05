#include "../Syslog.h"
#include <iostream>

int main() {
    Syslog::initialize(LOG_INFO, "logger_example", true);
    Logger::info("info msg!");
    Logger::error("error msg!");
    Syslog::close();
    return 0;
}
