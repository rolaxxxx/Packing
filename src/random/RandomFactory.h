#ifndef RANDOMFACTORY_H
#define RANDOMFACTORY_H
#include "ARandom.h"



class RandomFactory
{
public:
    RandomFactory();
    ARandom* create(std::string type);

};

#endif // RANDOMFACTORY_H
