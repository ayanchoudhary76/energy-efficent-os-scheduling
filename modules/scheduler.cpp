#include "scheduler.h"
#include "../utils/logger.h"
#include <iostream>
#include <algorithm>
#include <vector>

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
    int total_tat = 0;
    int total_wt = 0;
    int n = processes.size();

    std::vector<std::pair<int, int>> gantt_chart;

    std::cout << "\nProcess Execution Order:\n";
    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "| Process | Arrival Time | Burst Time | Completion Time | TAT | WT |\n";
    std::cout << "-------------------------------------------------------------------\n";

    for (auto &p : processes)
    {
        if (current_time < p.arrival_time)
        {
            current_time = p.arrival_time;
        }

        int completion_time = current_time + p.burst_time;
        int tat = completion_time - p.arrival_time;
        int wt = tat - p.burst_time;

        total_tat += tat;
        total_wt += wt;
        int energy_used = p.burst_time * 5;
        total_energy += energy_used;

        gantt_chart.push_back({p.id, current_time});

        std::cout << "|    P" << p.id << "    |      " << p.arrival_time
                  << "       |     " << p.burst_time
                  << "     |       " << completion_time
                  << "       |   " << tat
                  << "  |  " << wt << "  |\n";

        Logger::log("Process " + std::to_string(p.id) + " executed, CT: " +
                    std::to_string(completion_time) + ", TAT: " +
                    std::to_string(tat) + ", WT: " + std::to_string(wt) +
                    ", Energy Used: " + std::to_string(energy_used));

        current_time = completion_time;
    }

    float avg_tat = (float)total_tat / n;
    float avg_wt = (float)total_wt / n;

    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "Total Energy Consumption: " << total_energy << " units\n";
    std::cout << "Average Turnaround Time: " << avg_tat << "\n";
    std::cout << "Average Waiting Time: " << avg_wt << "\n";

    Logger::log("Total Energy Consumption: " + std::to_string(total_energy) + " units");
    Logger::log("Average Turnaround Time: " + std::to_string(avg_tat));
    Logger::log("Average Waiting Time: " + std::to_string(avg_wt));

    std::cout << "\nGantt Chart:\n";
    std::cout << "|";
    for (const auto &entry : gantt_chart)
    {
        std::cout << " P" << entry.first << " |";
    }
    std::cout << "\n";

    for (const auto &entry : gantt_chart)
    {
        std::cout << entry.second << "    ";
    }
    std::cout << current_time << "\n";
}
