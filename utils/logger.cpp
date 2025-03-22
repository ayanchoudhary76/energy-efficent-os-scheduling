#include "logger.h"
#include <ctime>

std::string getCurrentTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return std::string(buffer);
}

void Logger::log(const std::string message)
{
    std::string timestamp = getCurrentTime();
    std::cout << "[LOG " << timestamp << "] " << message << std::endl;

    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open())
    {
        logFile << "[LOG " << timestamp << "] " << message << std::endl;
        logFile.close();
    }
    else
    {
        std::cerr << "[ERROR] Unable to open log file" << std::endl;
    }
}
