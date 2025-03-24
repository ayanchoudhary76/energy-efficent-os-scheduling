#include "scheduler.h"
#include "gantt_chart.h"
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
    std::vector<int> completion_time(n, 0), tat(n, 0), wt(n, 0);
    std::vector<std::pair<int, int>> gantt_chart;

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

            gantt_chart.push_back({p.id, current_time});

            std::cout << "Executing Process P" << p.id << " at time " << current_time << "\n";
            Logger::log("Executing Process P" + std::to_string(p.id) + " at time " + std::to_string(current_time));

            p.burst_time--;
            total_energy += 5;

            if (p.burst_time > 0)
            {
                pq.push(p);
            }
            else
            {
                completion_time[p.id - 1] = current_time + 1;
            }

            current_time++;
        }
        else
        {
            current_time++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = completion_time[i] - processes[i].arrival_time;
        wt[i] = tat[i] - processes[i].burst_time;
    }

    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;

    std::cout << "\nProcess Execution Order:\n";
    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "| Process | Arrival Time | Burst Time | Completion Time | TAT | WT |\n";
    std::cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << "|    P" << processes[i].id << "    |      " << processes[i].arrival_time
                  << "       |     " << processes[i].burst_time
                  << "     |       " << completion_time[i]
                  << "       |   " << tat[i]
                  << "  |  " << wt[i] << "  |\n";

        Logger::log("Process " + std::to_string(processes[i].id) + " executed, CT: " +
                    std::to_string(completion_time[i]) + ", TAT: " +
                    std::to_string(tat[i]) + ", WT: " + std::to_string(wt[i]));
    }

    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "Total Energy Consumption: " << total_energy << " units\n";
    std::cout << "Average Turnaround Time: " << avg_tat << "\n";
    std::cout << "Average Waiting Time: " << avg_wt << "\n";

    Logger::log("Total Energy Consumption: " + std::to_string(total_energy) + " units");
    Logger::log("Average Turnaround Time: " + std::to_string(avg_tat));
    Logger::log("Average Waiting Time: " + std::to_string(avg_wt));

    GanttChart::display(gantt_chart, current_time);
}
