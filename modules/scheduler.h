#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>

struct Process
{
    int id, arrival_time, burst_time;
};

class Scheduler
{
public:
    virtual void schedule(std::vector<Process> &processes) = 0;
};

class SJFScheduler : public Scheduler
{
public:
    void schedule(std::vector<Process> &processes) override;
};

#endif
