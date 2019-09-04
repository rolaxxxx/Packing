#ifndef RANDOMUNIFORM_H
#define RANDOMUNIFORM_H
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

#endif // RANDOMUNIFORM_H
