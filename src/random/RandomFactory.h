#ifndef RANDOMFACTORY_H
#define RANDOMFACTORY_H
#include "ARandom.h"

enum class RandomTypes
{
    Uniform
};

class RandomFactory
{
public:
    RandomFactory();
    ARandom* create(RandomTypes type);

};

#endif // RANDOMFACTORY_H
