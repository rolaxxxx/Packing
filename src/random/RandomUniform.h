#ifndef RANDOMUNIFORM_H
#define RANDOMUNIFORM_H
#include "ARandom.h"
#include "core/Constants.h"
class RandomUniform:public ARandom
{
public:
    RandomUniform();
    REAL getNextValue();
protected:
    void initialization();
};

#endif // RANDOMUNIFORM_H
