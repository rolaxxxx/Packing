#include "SpherePackingAlgorithm.h"
using namespace std;
SpherePackingAlgorithm::SpherePackingAlgorithm()
{

}
void SpherePackingAlgorithm::pack()
{
     INT rand_particle_index;
     vector<INT>neighbours;
     vector<INT>group;
     srand (time(NULL));
     PointsArrayType negative_positive_positions;
     //cout << data->getNumberOfPoints() << endl;
     for(INT i=0;i<count;i++){
        rand_particle_index=rand()%data->getNumberOfPoints();
     //cout << i << endl;
        //cout << neighbours.size() << endl;
        neighbours=search->getNeighboursID(rand_particle_index);
             for(INT j=0;j<neighbours.size();j++){
                 //tikrinamos ne visos koombinacijos
                    //cout << neighbours[j] << " " << data->getNumberOfPoints() << endl;
                    negative_positive_positions=math.getSpheresTouchingThreeOtherSpheres(data->getPoint(neighbours[j]),data->getPoint(neighbours[j+1]), data->getPoint(rand_particle_index),random->getNextValue());

                    if(!(search->intersect(negative_positive_positions[0], rand_particle_index)))
                         { data->insertNextPoint(negative_positive_positions[0]);
                            search->addPoint(negative_positive_positions[0]);
                            j=neighbours.size();
                        //cout << negative_positive_positions[0].x << " " << negative_positive_positions[1].y << " " << negative_positive_positions[1].z << negative_positive_positions[1].R << endl;
                     }
                    else if(!(search->intersect(negative_positive_positions[1], rand_particle_index)))
                         { data->insertNextPoint(negative_positive_positions[1]);
                            j=neighbours.size();
                            search->addPoint(negative_positive_positions[1]);
                    }
                    else{

                    }

             }
     }
    std::cout<<"packing done\n";
}

void SpherePackingAlgorithm::initialization()
{
    std::cout<<"Performing initialization\n";
}
