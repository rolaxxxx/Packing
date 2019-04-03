#include "AlgorithmFactory.h"
#include "algorithm/SpherePackingAlgorithm.h"

AlgorithmFactory::AlgorithmFactory()
{

}
AAlgorithm* AlgorithmFactory::create(AlgorithmType type)
{
    if(type==AlgorithmType::SpherePackingAlgorithm)
    {
        return new SpherePackingAlgorithm();
    }
    std::cerr<<"Klaida tokio modulio nera!!!\n";
    exit(1000);
}
