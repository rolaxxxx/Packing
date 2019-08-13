#include "MeshPackingAlgorithm.h"

using namespace std;
MeshPackingAlgorithm::MeshPackingAlgorithm()
{

}
void MeshPackingAlgorithm::pack()
{
    INT temp;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    // for(int i=0;i<25000;i++){ senas for ciklas
    Timer time;
    int i=0;
    PointType pasirinkta_dalele;
    double rez_time;

    double daleliu_turis=0;

    //double  kubo_turis=((fabs(search->getBmax().x))-(fabs(search->getBmin().x)))*((fabs(search->getBmax().y))-(fabs(search->getBmin().y)))*((fabs(search->getBmax().z))-(fabs(search->getBmin().z)));
    double figuros_turis=PI*fabs(bounds->getRadius())*fabs(bounds->getRadius())*fabs(bounds->getHight());

    do{

        int dydis=F.size();
        std::uniform_int_distribution<> dis(0, F.size()-1);
                INT rand_particle_index_f_index=dis(gen);
      //          INT rand_particle_index = F[rand_particle_index_f_index];

        /*pasirinkta_dalele=data->getPoint(rand_particle_index);

//vector - > particle index -> ID -> cell elements//
        double new_R=random->getNextValue();


        temp = rand_particle_index;
        int check=i;


        for (INT j = 0; j < F.size()-1; j++){
            for (INT l = j+1; l < F.size(); l++) {

                PointsArrayType newSphere=
                        this->math.getSpheresTouchingThreeOtherSpheres(
                            data->getPoint(j),
                            data->getPoint(l),
                            data->getPoint(rand_particle_index),
                            new_R);

                // cout << newSphere.size() << endl;

                for(int z=0;z<newSphere.size();z++)
                {

                        //  std::cout<<"dedame\n";
                    if(!search->intersect(newSphere[z], data->getData()))
                    {
                        if(bounds->check(newSphere[z])){

                            F.push_back(data->getNumberOfPoints()-1);
                            daleliu_turis+=(4.0/3.0)*PI*pow(newSphere[z].R,3);
                            i++;
                        }

                    }
                }


            }
        if(check==i)
           {
            //F[rand_particle_index]=-1;
            //F.erase(std::remove(F.begin(), F.end(), rand_particle_index), F.end());
            remove(F.begin(),F.end(), rand_particle_index);
            F.pop_back();
           }
        //cout << F.size() << endl;

        std::cout<<"viso daleliu "<<data->getNumberOfPoints()<<"\n";
        std::cout <<"poringumas "<< daleliu_turis/figuros_turis << endl;
        }
*/
    }
    while(F.size());

   // cout << time.CumulativeTime("sec") << endl;
   //cout << rez_time << endl;
    poringumas=daleliu_turis/figuros_turis;
    std::cout<<"packing done\n";
}

void MeshPackingAlgorithm::initialization()
{

}
