#include "AlgorithmFactory.h"
#include "algorithm/SpherePackingAlgorithm.h"
#include "algorithm/MeshPackingAlgorithm.h"

AlgorithmFactory::AlgorithmFactory()
{

}
AAlgorithm* AlgorithmFactory::create(std::string type)
{
    if(type=="SpherePackingAlgorithm")
    {
        return new SpherePackingAlgorithm();
    }
    else if(type=="MeshPackingAlgorithm")
    {
        return new MeshPackingAlgorithm();
    }
    std::cerr<<"Klaida tokio modulio nera!!!\n";
    exit(1000);
}
