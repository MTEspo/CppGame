// logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <ctime>

class Logger {
private:
    std::ofstream logfile;

public:
    Logger(const std::string& filename);
    ~Logger();

    void write(const std::string& message);
};

#endif // LOGGER_H