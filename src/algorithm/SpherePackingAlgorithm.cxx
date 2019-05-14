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
    Timer time;
    int i=0;
    PointType pasirinkta_dalele;
    double rez_time;

    double daleliu_turis=0;

    double  kubo_turis=pow((fabs(search->getBmax().x))+(fabs(search->getBmin().x)),3);


    do{

        //std::cout<<"viso daleliu "<<data->getNumberOfPoints()<<"\n";
         //   cout <<"poringumas "<< daleliu_turis/kubo_turis << endl;
        //cout << data->getNumberOfPoints() << endl;
        //tikrinimas=false;
        int dydis=F.size();


        std::uniform_int_distribution<> dis(0, F.size()-1);
                INT rand_particle_index_f_index=dis(gen);
                INT rand_particle_index = F[rand_particle_index_f_index];
        vector<INT>neighbours=search->getNeighboursID(rand_particle_index);
        pasirinkta_dalele=data->getPoint(rand_particle_index);

//vector - > particle index -> ID -> cell elements//
        double new_R=random->getNextValue();
        //c//out << new_R << endl;
        //cout << neighbours.size() << " pries " << endl;
        for(int t=0;t<neighbours.size();t++){
            //cout << vector_len(pasirinkta_dalele-data->getPoint(neighbours[t]) )<< " " << pasirinkta_dalele.R+data->getPoint(neighbours[t]).R+2*new_R << endl;
            if(vector_len(pasirinkta_dalele-data->getPoint(neighbours[t]))>pasirinkta_dalele.R+data->getPoint(neighbours[t]).R+2*new_R)
                neighbours.erase(neighbours.begin()+t);
        }
       // cout << neighbours.size() << " po" << endl;
       // cout << "____" << endl;

        temp = rand_particle_index;
        int check=i;


        for (INT j = 0; j < neighbours.size()-1; j++){
            for (INT l = j+1; l < neighbours.size(); l++) {

                //std::cout<<"generuojame sfera is "<<neighbours[j]<<" "<<neighbours[l]<<" "<<rand_particle_index<<"\n";

                PointsArrayType newSphere=
                        this->math.getSpheresTouchingThreeOtherSpheres(
                            data->getPoint(neighbours[j]),
                            data->getPoint(neighbours[l]),
                            data->getPoint(rand_particle_index),
                            new_R);

                //time.ElapsedTime("sec");


                // cout << newSphere.size() << endl;
                for(int z=0;z<newSphere.size();z++)
                {
                    //std::cout<<"nagrinejame "<<z<<"\n";
                    //time.StartTimer();
                    //auto begin = std::chrono::high_resolution_clock::now();
                    if(!search->intersect(newSphere[z], neighbours))
                    {
                        //  std::cout<<"dedame\n";
                        if(bounds->check(newSphere[z], search->getBmin(), search->getBmax())){

                            //newSphere[z].PrintStructure();
                            search->addPoint(newSphere[z]);
                            F.push_back(data->getNumberOfPoints()-1);
                            daleliu_turis+=(4.0/3.0)*PI*pow(newSphere[z].R,3);
                            //cout << F.size() << "daleliu kiekis" << endl;
                            i++;
                        }
                    }
                   // time.StopTimer();
                   // rez_time+=time.ElapsedTime("sec");
                   // auto end = std::chrono::high_resolution_clock::now();
                  // duration<double> time_span = duration_cast<duration<double>>(end - begin);
                  // time=time_span.count();

                   // F_index++;

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


        //std::cout<<"viso daleliu "<<data->getNumberOfPoints()<<"\n";
        //std::cout <<"poringumas "<< daleliu_turis/kubo_turis << endl;
        }





    while(F.size());
   //cout << rez_time << endl;

    std::cout<<"packing done\n";
}

void SpherePackingAlgorithm::initialization()
{
    for(int i=0;i<data->getNumberOfPoints();i++){
        F.push_back(i);
    }
    std::cout<<"Performing initialization\n";
}
