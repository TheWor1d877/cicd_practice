#ifndef CICD_PRACTICE_LOGGER_H
#define CICD_PRACTICE_LOGGER_H


#include <string>

class Logger {
public:
    void log(const std::string& message);
    void error(const std::string& message);
    void warn(const std::string& message);

    // 获取日志统计
    int getLogCount() const;
    int getErrorCount() const;

private:
    int log_count_ = 0;
    int error_count_ = 0;
};


#endif //CICD_PRACTICE_LOGGER_H