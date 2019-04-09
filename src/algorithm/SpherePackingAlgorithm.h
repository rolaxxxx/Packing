#ifndef SPHEREPACKINGALGORITHM_H
#define SPHEREPACKINGALGORITHM_H
#include "algorithm/AAlgorithm.h"

class SpherePackingAlgorithm:public AAlgorithm
{
public:
    SpherePackingAlgorithm();
    void pack();
protected:
    void initialization();

};

#endif // SPHEREPACKINGALGORITHM_H
