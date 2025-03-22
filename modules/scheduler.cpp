#include "scheduler.h"
#include <iostream>
#include <algorithm>
using namespace std;
void sjfscheduler::schedule(vector<process> &p)
{
    sort(p.begin(), p.end(), [](process &a, process &b) {
        return a.burst_time < b.burst_time;
    });
    cout<<"Scheduling using SJF: "<<endl;
    for (auto &i : p)
    {
        cout << "Process ID: " << i.id << " Arrival Time: " << i.arr_time << " Burst Time: " << i.burst_time << endl;
    }
}