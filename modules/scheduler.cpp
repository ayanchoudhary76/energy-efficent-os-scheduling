#include "scheduler.h"
#include "../utils/logger.h"
#include <iostream>
#include <algorithm>

void SJFScheduler::schedule(std::vector<Process> &processes)
{
    std::sort(processes.begin(), processes.end(), [](Process a, Process b)
              {
        if (a.arrival_time == b.arrival_time)
            return a.burst_time < b.burst_time;
        return a.arrival_time < b.arrival_time; });

    Logger::log("Starting SJF Scheduling...");
    int current_time = 0;
    int total_energy = 0;

    std::cout << "\nProcess Execution Order:\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "| Process | Arrival Time | Burst Time | Completion Time | Energy Used |\n";
    std::cout << "-----------------------------------------\n";

    for (auto &p : processes)
    {
        if (current_time < p.arrival_time)
        {
            current_time = p.arrival_time; // Fix: Ensure CPU waits if needed
        }

        int energy_used = p.burst_time * 5;
        total_energy += energy_used;
        int completion_time = current_time + p.burst_time;

        std::cout << "|    P" << p.id << "    |      " << p.arrival_time
                  << "       |     " << p.burst_time
                  << "     |       " << completion_time
                  << "       |     " << energy_used << "   |\n";

        Logger::log("Process " + std::to_string(p.id) + " executed, Completion Time: " +
                    std::to_string(completion_time) + ", Energy Used: " + std::to_string(energy_used));

        current_time = completion_time;
    }

    std::cout << "-----------------------------------------\n";
    std::cout << "Total Energy Consumption: " << total_energy << " units\n";
    Logger::log("Total Energy Consumption: " + std::to_string(total_energy) + " units");
}
