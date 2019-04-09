#include "SpherePackingAlgorithm.h"

SpherePackingAlgorithm::SpherePackingAlgorithm()
{

}
void SpherePackingAlgorithm::pack()
{
    std::cout<<"Performing packing\n";
     INT rand_particle_index;

    for(INT i=0;i<count;i++){
        INT temp=data->getNumberOfPoints();
        //std::cout << temp << std::endl;
        //rand_particle_index=rand()%temp;



    }



    std::cout<<"packing done\n";
}

void SpherePackingAlgorithm::initialization()
{
    std::cout<<"Performing initialization\n";
}
