#include "scheduler.h"
#include "../utils/logger.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void SJFScheduler::schedule(std::vector<Process> &processes)
{
    auto cmp = [](const Process &a, const Process &b)
    { return a.burst_time > b.burst_time; };
    std::priority_queue<Process, std::vector<Process>, decltype(cmp)> pq(cmp);

    int current_time = 0, total_energy = 0;
    int index = 0, n = processes.size();

    std::sort(processes.begin(), processes.end(), [](Process a, Process b)
              { return a.arrival_time < b.arrival_time; });

    Logger::log("Starting Preemptive SJF Scheduling...");

    while (index < n || !pq.empty())
    {
        while (index < n && processes[index].arrival_time <= current_time)
        {
            pq.push(processes[index]);
            index++;
        }

        if (!pq.empty())
        {
            Process p = pq.top();
            pq.pop();
            std::cout << "Executing Process P" << p.id << " at time " << current_time << "\n";
            Logger::log("Executing Process P" + std::to_string(p.id) + " at time " + std::to_string(current_time));

            p.burst_time--;
            total_energy += 5;

            if (p.burst_time > 0)
            {
                pq.push(p);
            }

            current_time++;
        }
        else
        {
            current_time++;
        }
    }

    Logger::log("Total Energy Consumption: " + std::to_string(total_energy) + " units");
}
