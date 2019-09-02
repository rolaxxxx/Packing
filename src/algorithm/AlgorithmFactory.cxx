#include "AlgorithmFactory.h"
#include "algorithm/SpherePackingAlgorithm.h"


AlgorithmFactory::AlgorithmFactory()
{

}
AAlgorithm* AlgorithmFactory::create(std::string type)
{
    if(type=="SpherePackingAlgorithm")
    {
        return new SpherePackingAlgorithm();
    }

    std::cerr<<"Klaida tokio modulio nera!!!\n";
    exit(1000);
}
