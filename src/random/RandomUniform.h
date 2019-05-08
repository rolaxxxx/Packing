#ifndef RANDOMUNIFORM_H
#define RANDOMUNIFORM_H
#include "ARandom.h"
#include "core/Constants.h"

class RandomUniform:public ARandom
{
public:
    RandomUniform();
    REAL getNextValue();
    boost::minstd_rand0 gen;
protected:
    void initialization();
};

#endif // RANDOMUNIFORM_H
