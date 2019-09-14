#ifndef RANDOMDISCRETE_H
#define RANDOMDISCRETE_H
#include "ARandom.h"
#include "core/Constants.h"

class RandomDiscrete:public ARandom
{
public:
    RandomDiscrete();
    REAL getNextValue();
    boost::random::mt19937 gen;

protected:
    void initialization(json duomenys);
    std::vector<REAL>probs;
    std::vector<REAL>intervals;
};

#endif // RANDOMDISCRETE_H
