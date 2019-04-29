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
    for(int i=0;i<60000;i++){

        std::uniform_int_distribution<> dis(0, data->getNumberOfPoints()-1);
        INT rand_particle_index = dis(gen);
        double new_R=random->getNextValue();
        vector<INT>neighbours=search->getNeighboursID(rand_particle_index);
     //   cout <<"radn "<< rand_particle_index << " " << neighbours.size()  <<" "<< data->getNumberOfPoints()<< "  "<<i<<"  "<<count<<endl;
        temp = rand_particle_index;
    //    std::cout<<"ki111tas roundas\n";
        for (INT j = 0; j < neighbours.size()-1 ; j++){
            for (INT l = j+1; l < neighbours.size() ; l++) {

           //     std::cout<<"generuojame sfera is "<<neighbours[j]<<" "<<neighbours[l]<<" "<<rand_particle_index<<"\n";
                PointsArrayType newSphere=
                        this->math.getSpheresTouchingThreeOtherSpheres(
                            data->getPoint(neighbours[j]),
                            data->getPoint(neighbours[l]),
                            data->getPoint(rand_particle_index),
                            new_R);
                for(int z=0;z<newSphere.size();z++)
                {
                  //  std::cout<<"nagrinejame "<<z<<"\n";
                    if(!search->intersect(newSphere[z]))
                    {
                      //  std::cout<<"dedame\n";
                        //newSphere[z].PrintStructure();
                        search->addPoint(newSphere[z]);
                    }
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
