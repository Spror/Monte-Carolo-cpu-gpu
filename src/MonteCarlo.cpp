#include "inc/MonteCarlo.hpp"


MonteCarlo::MonteCarlo(): calculatedPI{0}, samples{0}, time{0}
{

}

double MonteCarlo::returnCalculatedPI()
{
    return this->calculatedPI;
}

std::vector<point> MonteCarlo::returnPointIn()
{
    return this->pointIn;
}

std::vector<point> MonteCarlo::returnPointOut()
{
    return this->pointOut;
}

void MonteCarlo::calculatePi(unsigned long  const samples, Method const method)
{
    this->samples = samples;
    this->method = method;

    auto start = std::chrono::steady_clock::now();
    if(this->method == Method::CPU){


        this->calculatedPI = CPUCalculation();


    }
    else{


    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    this->time = elapsed_seconds.count();

    this->Error = M_PI-this->calculatedPI;



}


double MonteCarlo::CPUCalculation()
{
    std::srand(std::time(nullptr));
    unsigned long  samples = this->samples;
    for(unsigned long  i=0; i<samples; i++)
    {
        point random_point{double(std::rand() %(samples + 1))/samples, double(std::rand() %(samples + 1))/samples};
        auto origin_dist = random_point.x*random_point.x +random_point.y*random_point.y;

        if(origin_dist <= 1.0)
            this->pointIn.push_back(random_point);
        else
            this->pointOut.push_back(random_point);

    }

    return double(4*this->pointIn.size())/(this->pointOut.size()+this->pointIn.size());
}
