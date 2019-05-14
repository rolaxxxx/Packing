#ifndef SPHEREPACKINGALGORITHM_H
#define SPHEREPACKINGALGORITHM_H
#include "algorithm/AAlgorithm.h"
#include "core/time.h"
class SpherePackingAlgorithm:public AAlgorithm
{
public:
    SpherePackingAlgorithm();
    void pack();
protected:
    void initialization();
    std::vector<INT>F;
};

#endif // SPHEREPACKINGALGORITHM_H
