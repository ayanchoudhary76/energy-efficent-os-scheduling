#include<iostream>
#include<vector>
#include<algorithm>
#include "modules/scheduler.h"
#include "utils/logger.h"
using namespace std;
int main(){
    vector<process> p = {{1, 0, 5}, {2, 1, 3}, {3, 2, 8}};
    logger::log("Initializing SJF Scheduler...");
    sjfscheduler sjf;
    sjf.schedule(p);
    logger::log("SJF Scheduler executed successfully");
    return 0;
}