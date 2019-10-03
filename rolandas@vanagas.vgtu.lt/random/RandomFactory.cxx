#include "RandomFactory.h"
#include "random/RandomUniform.h"
#include "random/RandomDiscrete.h"

RandomFactory::RandomFactory()
{

}


ARandom* RandomFactory::create(std::string type)
{
    if(type=="Uniform")
    {
        std::cout << "uniform distribution issimtas " << std::endl;
    }
    else if(type=="Discrete")
    {
        return new RandomDiscrete();
    }
    std::cerr<<"Klaida tokio modulio nera!!!\n";
    exit(1000);
}
