#ifndef RANDOMUNIFORM_H
#define RANDOMUNIFORM_H
#include "ARandom.h"
#include "core/Constants.h"

class RandomUniform:public ARandom
{
public:
    RandomUniform();
    REAL getNextValue();


  unsigned seed= std::chrono::system_clock::now().time_since_epoch().count();




protected:
    void initialization(json duomenys);
};

#endif // RANDOMUNIFORM_H
