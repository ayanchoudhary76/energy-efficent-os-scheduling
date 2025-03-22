#include "scheduler.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "utils/logger.h"
using namespace std;
void sjfscheduler::schedule(vector<process> &p)
{
    sort(p.begin(), p.end(), [](process &a, process &b) {
        return a.burst_time < b.burst_time;
    });
    cout<<"Scheduling using SJF: "<<endl;
    int current_time = 0;
    int total_energy = 0;
    cout<<"\nProcess Execution Order: "<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"| Process ID | Arrival Time | Burst Time | Completion Time | Energy Used |"<<endl;
    cout<<"-----------------------------"<<endl;
    for (auto &i : p)
    {
        int energy_used = i.burst_time * 5;
        total_energy += energy_used;
        int completion_time = current_time + i.burst_time;
        cout<<"| P"<<i.id<<"          | "<<i.arr_time<<"            | "<<i.burst_time<<"          | "<<completion_time<<"               | "<<energy_used<<"         |"<<endl;

        logger::log("Process P"+to_string(i.id)+" executed from "+to_string(current_time)+" to "+to_string(completion_time));
        current_time = completion_time;
    }
    cout<<"-----------------------------"<<endl;
    cout<<"Total Energy Used: "<<total_energy<<endl;
    logger::log("SJF Scheduler executed successfully");
}