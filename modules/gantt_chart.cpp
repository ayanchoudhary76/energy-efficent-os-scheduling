#include "gantt_chart.h"
#include <iostream>

void GanttChart::display(const std::vector<std::pair<int, int>> &gantt_chart, int current_time)
{
    std::cout << "\nGantt Chart:\n";
    std::cout << "|";
    for (const auto &entry : gantt_chart)
    {
        std::cout << " P" << entry.first << " |";
    }
    std::cout << "\n";

    for (const auto &entry : gantt_chart)
    {
        std::cout << entry.second << "    ";
    }
    std::cout << current_time << "\n";
}