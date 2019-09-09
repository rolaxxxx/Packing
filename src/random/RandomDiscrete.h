#ifndef RANDOMDISCRETE_H
#define RANDOMDISCRETE_H
#include "ARandom.h"
#include "core/Constants.h"

class RandomDiscrete:public ARandom
{
public:
    RandomDiscrete();
    REAL getNextValue();
    boost::minstd_rand0 gen;
protected:
    void initialization(json duomenys);
};

#endif // RANDOMDISCRETE_H
