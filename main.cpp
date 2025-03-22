#include <iostream>
#include <vector>
#include "modules/scheduler.h"
#include "utils/logger.h"

int main()
{
    std::vector<Process> processes = {
        {1, 0, 6},
        {2, 1, 8},
        {3, 2, 7},
        {4, 3, 3}};

    Logger::log("Initializing SJF Scheduler...");

    SJFScheduler sjf;
    sjf.schedule(processes);

    Logger::log("SJF Scheduling Completed.");
    return 0;
}
