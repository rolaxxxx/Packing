#ifndef MESHPACKINGALGORITHM_H
#define MESHPACKINGALGORITHM_H
#include "algorithm/AAlgorithm.h"

class MeshPackingAlgorithm:public AAlgorithm
{
public:
    MeshPackingAlgorithm();
    void pack();


protected:
    void initialization();
   std::vector<INT>F;

};

#endif // MESHPACKINGALGORITHM_H
