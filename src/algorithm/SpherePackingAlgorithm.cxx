#include "SpherePackingAlgorithm.h"

using namespace std;
SpherePackingAlgorithm::SpherePackingAlgorithm()
{

}
void SpherePackingAlgorithm::pack()
{
    INT temp;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    // for(int i=0;i<25000;i++){ senas for ciklas
    int i=0;
    while(i<5100){

        std::uniform_int_distribution<> dis(0, data->getNumberOfPoints()-1);
        INT rand_particle_index = dis(gen);

        double new_R=random->getNextValue();
        vector<INT>neighbours=search->getNeighboursID(rand_particle_index);

        temp = rand_particle_index;

        for (INT j = 0; j < neighbours.size()-1 ; j++){
            for (INT l = j+1; l < neighbours.size() ; l++) {

           //     std::cout<<"generuojame sfera is "<<neighbours[j]<<" "<<neighbours[l]<<" "<<rand_particle_index<<"\n";
                PointsArrayType newSphere=
                        this->math.getSpheresTouchingThreeOtherSpheres(
                            data->getPoint(neighbours[j]),
                            data->getPoint(neighbours[l]),
                            data->getPoint(rand_particle_index),
                            new_R);
                int check=i;
                for(int z=0;z<newSphere.size();z++)
                {
                  //  std::cout<<"nagrinejame "<<z<<"\n";
                    if(!search->intersect(newSphere[z]))
                    {
                        //  std::cout<<"dedame\n";
                        if(       newSphere[z].x<search->getBmax().x-1
                                &&newSphere[z].y<search->getBmax().y-1
                                &&newSphere[z].z<search->getBmax().z-1
                                &&newSphere[z].x>search->getBmin().x+1
                                &&newSphere[z].y>search->getBmin().y+1
                                &&newSphere[z].z>search->getBmin().z+1
                                  ){
                            newSphere[z].PrintStructure();
                            search->addPoint(newSphere[z]);
                            i++;
                        }
                    }
                }
                if(check==i)
                {

                }
            }
        }

        std::cout<<"viso daleliu "<<data->getNumberOfPoints()<<"\n";
    }
    std::cout<<"packing done\n";
}

void SpherePackingAlgorithm::initialization()
{
    std::cout<<"Performing initialization\n";
}
