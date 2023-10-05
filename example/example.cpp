#include "../logger.h"
#include <iostream>

int main() {
    Logger::initialize(LOG_INFO, "logger_example", true);
    Logger::info("info msg!");
    Logger::error("error msg!");
    Logger::close();
    return 0;
}
