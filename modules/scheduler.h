#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
using namespace std;
struct process
{
    int id, arr_time, burst_time;
};

class scheduler
{
public:
    virtual void schedule(vector<process> &p) = 0;
};

class sjfscheduler : public scheduler
{
public:
    void schedule(vector<process> &p) override;
};

#endif