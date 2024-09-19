// logger.cpp
#include "logger.h"

Logger::Logger(const std::string& filename) {
    logfile.open(filename, std::ios::app);
    if (!logfile.is_open()) {
        throw std::runtime_error("Failed to open log file.");
    }
}

Logger::~Logger() {
    if (logfile.is_open()) {
        logfile.close();
    }
}

void Logger::write(const std::string& message) {
    time_t now = time(nullptr);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    logfile << "[" << timestamp << "] " << message << std::endl;
}
