#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class logger
{
    public:
        static void log(const string message);
};
#endif