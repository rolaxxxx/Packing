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
    double daleliu_turis=0;
    double  kubo_turis=pow((fabs(search->getBmax().x))+(fabs(search->getBmin().x)),3);
    while(F.size()){
        //cout << data->getNumberOfPoints() << endl;
        std::uniform_int_distribution<> dis(0, F.size()-1);
        INT rand_particle_index_f_index=dis(gen);
        INT rand_particle_index = F[rand_particle_index_f_index];

        double new_R=random->getNextValue();
        vector<INT>neighbours=search->getNeighboursID(rand_particle_index);

        temp = rand_particle_index;
        int check=i;
        for (INT j = 0; j < neighbours.size()-1 ; j++){
            for (INT l = j+1; l < neighbours.size() ; l++) {

                //std::cout<<"generuojame sfera is "<<neighbours[j]<<" "<<neighbours[l]<<" "<<rand_particle_index<<"\n";
                PointsArrayType newSphere=
                        this->math.getSpheresTouchingThreeOtherSpheres(
                            data->getPoint(neighbours[j]),
                            data->getPoint(neighbours[l]),
                            data->getPoint(rand_particle_index),
                            new_R);
               // cout << newSphere.size() << endl;
                for(int z=0;z<newSphere.size();z++)
                {
                    //std::cout<<"nagrinejame "<<z<<"\n";
                    if(!search->intersect(newSphere[z]))
                    {
                        //  std::cout<<"dedame\n";
                        if(       newSphere[z].x<search->getBmax().x
                                &&newSphere[z].y<search->getBmax().y
                                &&newSphere[z].z<search->getBmax().z
                                &&newSphere[z].x>search->getBmin().x
                                &&newSphere[z].y>search->getBmin().y
                                &&newSphere[z].z>search->getBmin().z
                                  ){

                            //newSphere[z].PrintStructure();
                            search->addPoint(newSphere[z]);
                            F.push_back(data->getNumberOfPoints()-1);
                            daleliu_turis+=(4.0/3.0)*PI*pow(newSphere[z].R,3);

                            i++;
                        }
                    }
                }

            }
        }
        if(check==i)
           {
            F.erase(std::remove(F.begin(), F.end(), rand_particle_index), F.end());
           }

std::cout<<"viso daleliu "<<data->getNumberOfPoints()<<"\n";
    cout <<"poringumas "<< daleliu_turis/kubo_turis << endl;
    }

    cout << kubo_turis << " " << data->getNumberOfPoints() <<  endl;
    cout << daleliu_turis/kubo_turis << endl;

    std::cout<<"packing done\n";
}

void SpherePackingAlgorithm::initialization()
{
    for(int i=0;i<data->getNumberOfPoints();i++){
        F.push_back(i);
    }
    std::cout<<"Performing initialization\n";
}
