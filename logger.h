#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <syslog.h>
#include <sys/syslog.h>
#include <string>
#include <sstream>
#include <optional>

class Syslog {
public:
    static void initialize(int logLevel, const std::string& appName, bool logToStdout);
    static void log(int logLevel, const std::string& message);
    static void close();

private:
    static bool logToStdout_;
};

class Logger {
public:
    static void initialize(int logLevel, const std::string& appName, bool logToStdout){
        Syslog::initialize(logLevel, appName, logToStdout);
    }

    static void close(){
        Syslog::close();
    }

    template<typename... Args>
        static void debug(Args&&... args) {
            loggToSyslog(LOG_DEBUG, std::forward<Args>(args)...);
        }

    template<typename... Args>
        static void info(Args&&... args) {
            loggToSyslog(LOG_INFO, std::forward<Args>(args)...);
        }

    template<typename... Args>
        static void notice(Args&&... args) {
            loggToSyslog(LOG_NOTICE, std::forward<Args>(args)...);
        }

    template<typename... Args>
        static void warning(Args&&... args) {
            loggToSyslog(LOG_WARNING, std::forward<Args>(args)...);
        }

    template<typename... Args>
        static void error(Args&&... args) {
            loggToSyslog(LOG_ERR, std::forward<Args>(args)...);
        }

    template<typename... Args>
        static void critical(Args&&... args) {
            loggToSyslog(LOG_CRIT, std::forward<Args>(args)...);
        }

    template<typename... Args>
        static void alert(Args&&... args) {
            loggToSyslog(LOG_ALERT, std::forward<Args>(args)...);
        }

    template<typename... Args>
        static void emergency(Args&&... args) {
            loggToSyslog(LOG_EMERG, std::forward<Args>(args)...);
        }

private:
    template<typename... Args>
        static void loggToSyslog(int logLevel, Args&&... args) {
            int logPriorityLevel = logLevel & LOG_PRIMASK;
            std::string message = argsToString(std::forward<Args>(args)...);
            Syslog::log(logLevel, message);
        }

    template<typename... Args>
        static std::string argsToString(Args&&... args) {
            std::ostringstream stream;
            using List = int[];
            (void)List{0, ( (void)(stream << args << ' '), 0 )... };
            return stream.str();
        }

};

#endif // _LOGGER_H_
