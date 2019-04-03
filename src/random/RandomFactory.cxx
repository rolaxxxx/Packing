#include "RandomFactory.h"
#include "random/RandomUniform.h"

RandomFactory::RandomFactory()
{

}


ARandom* RandomFactory::create(RandomTypes type)
{
    if(type==RandomTypes::Uniform)
    {
        return new RandomUniform();
    }
    std::cerr<<"Klaida tokio modulio nera!!!\n";
    exit(1000);
}
