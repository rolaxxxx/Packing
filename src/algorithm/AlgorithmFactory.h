#ifndef ALGORITHMFACTORY_H
#define ALGORITHMFACTORY_H
#include "algorithm/AAlgorithm.h"

enum class AlgorithmType
{
    SpherePackingAlgorithm
};

class AlgorithmFactory
{
public:
    AlgorithmFactory();
    AAlgorithm* create(std::string type);
};

#endif // ALGORITHMFACTORY_H
