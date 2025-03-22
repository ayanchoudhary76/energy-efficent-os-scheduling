#include "logger.h"
#include <fstream>
#include <iostream>

void Logger::log(const std::string message)
{
    std::cout << "[LOG] " << message << std::endl;

    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open())
    {
        logFile << "[LOG] " << message << std::endl;
        logFile.close();
    }
    else
    {
        std::cerr << "[ERROR] Unable to open log file" << std::endl;
    }
}
