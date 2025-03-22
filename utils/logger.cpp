#include "logger.h"

void Logger::log(const string message)
{
    cout << "[LOG] " << message << endl;

    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open())
    {
        logFile << "[LOG] " << message << endl;
        logFile.close();
    }
    else
    {
        cout << "Error: Unable to open log file" << endl;
    }
}
