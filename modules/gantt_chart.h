#ifndef GANTT_CHART_H
#define GANTT_CHART_H

#include <vector>
#include <iostream>

class GanttChart
{
public:
    static void display(const std::vector<std::pair<int, int>> &gantt_chart, int current_time);
};

#endif  