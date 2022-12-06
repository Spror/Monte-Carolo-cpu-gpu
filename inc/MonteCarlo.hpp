#pragma once

#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>

enum class Method
{
    CPU,
    GPU
};

struct point
{
    double x;
    double y;
};

class MonteCarlo
{

    double calculatedPI;
    std::vector<point> pointIn;
    std::vector<point> pointOut;
    unsigned long  samples;
    double time;
    Method method;
    double Error;

    double CPUCalculation();





public:
    MonteCarlo();
    double returnCalculatedPI();
    std::vector<point> returnPointIn();
    std::vector<point> returnPointOut();
    double returnTime() {return this->time;}
    double returnError() {return this->Error;}
    void calculatePi(unsigned long  const samples,  Method const method);

};
