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
    std::vector<INT>F;
    std::vector<Point>Neideti_taskai;
};

#endif // SPHEREPACKINGALGORITHM_H
