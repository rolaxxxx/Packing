#ifndef RANDOMUNIFORM_H
#define RANDOMUNIFORM_H
#include "ARandom.h"

class RandomUniform:public ARandom
{
public:
    RandomUniform();
    REAL getNextValue();
protected:
    void initialization();
};

#endif // RANDOMUNIFORM_H
