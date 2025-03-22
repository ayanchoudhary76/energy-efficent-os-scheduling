#include <iostream>
#include <vector>
#include "modules/scheduler.h"
#include "utils/logger.h"

int main()
{
    int num_processes;
    std::vector<Process> processes;

    std::cout << "Enter the number of processes: ";
    std::cin >> num_processes;

    for (int i = 0; i < num_processes; i++)
    {
        int id, arrival_time, burst_time;
        std::cout << "Enter Process ID, Arrival Time, and Burst Time for Process " << (i + 1) << ": ";
        std::cin >> id >> arrival_time >> burst_time;
        processes.push_back({id, arrival_time, burst_time});
    }

    Logger::log("Initializing SJF Scheduler with user-input processes...");

    SJFScheduler sjf;
    sjf.schedule(processes);

    Logger::log("SJF Scheduling Completed.");
    return 0;
}
