#ifndef SCHEDULER_H
#define SCHEDULER_H
#include<vector>
using namespace std;
struct process
{
    int id,arr_time,burst_time;
};

class scheduler{
    public:
        virtual void schedule(vector<process>&p)=0;
};
#endif