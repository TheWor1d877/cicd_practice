//
// Created by TheWor1d on 2025/12/27.
//

#include "logger.h"

#include <iostream>

void Logger::log(const std::string& message) {
    std::cout << "[LOG] " << message << std::endl;
    log_count_++;
}

void Logger::error(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
    log_count_++;
    error_count_++;
}

void Logger::warn(const std::string& message) {
    std::cout << "[WARN] " << message << std::endl;
    log_count_++;
}

int Logger::getLogCount() const {
    return log_count_;
}

int Logger::getErrorCount() const {
    return error_count_;
}