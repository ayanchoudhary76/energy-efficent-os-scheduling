#include<iostream>
#include<vector>
#include<algorithm>
#include "modules/scheduler.h"
using namespace std;
int main(){
    vector<process> p = {{1, 0, 5}, {2, 1, 3}, {3, 2, 8}};
    sjfscheduler sjf;
    cout<<"Executing SJF Scheduler"<<endl;
    sjf.schedule(p);
    return 0;
}