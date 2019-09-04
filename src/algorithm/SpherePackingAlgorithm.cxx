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
    int isvedimo_kintamasis=10000;
    double daleliu_turis=0;

    //double  kubo_turis=((fabs(search->getBmax().x))-(fabs(search->getBmin().x)))*((fabs(search->getBmax().y))-(fabs(search->getBmin().y)))*((fabs(search->getBmax().z))-(fabs(search->getBmin().z)));
    double figuros_turis=(boundaries[1]-boundaries[0])*(boundaries[3]-boundaries[2])*(boundaries[5]-boundaries[4]);
    //cout << "boundaries reiksme ------  " <<
double new_R=random->getNextValue();
    do{

        //std::cout<<"viso daleliu "<<data->getNumberOfPoints()<<"\n";
         //   cout <<"poringumas "<< daleliu_turis/kubo_turis << endl;
        //cout << data->getNumberOfPoints() << endl;
        //cout <<"figuros ismatavimai " <<  bounds->getRadius() << " " << bounds->getHight() << endl;
        //tikrinimas=false;
        int dydis=F.size();


        std::uniform_int_distribution<> dis(0, F.size()-1);
              INT rand_particle_index_f_index=dis(gen);
                INT rand_particle_index = F[rand_particle_index_f_index];
        vector<INT>neighbours=search->getGridNeigbours(rand_particle_index);
        pasirinkta_dalele=data->getPoint(rand_particle_index);

//vector - > particle index -> ID -> cell elements//

        //c//out << new_R << endl;
        //cout << neighbours.size() << " pries " << endl;
        for(int t=0;t<neighbours.size();t++){
            //cout << vector_len(pasirinkta_dalele-data->getPoint(neighbours[t]) )<< " " << pasirinkta_dalele.R+data->getPoint(neighbours[t]).R+2*new_R << endl;
            if(vector_len(pasirinkta_dalele-data->getPoint(neighbours[t]))>pasirinkta_dalele.R+data->getPoint(neighbours[t]).R+2*new_R)
                neighbours.erase(neighbours.begin()+t);
        }
        //cout << neighbours.size() << endl;
         pasirinkta_dalele.koordinacinis_num=neighbours.size()-1;
        //cout << neighbours.size() << " po" << endl;
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
               // for(int z=0;z<newSphere.size();z++)
               // {
                // Neideti_taskai.push_back(newSphere[z]);

               // }

                for(int z=0;z<newSphere.size();z++)
                {
                    //std::cout<<"nagrinejame "<<z<<"\n";

       // cout << boundaries[0] << " " <<  boundaries[1] << " " <<  boundaries[2] << " " <<  boundaries[3] << " " <<  boundaries[4] << " " <<  boundaries[5] << " " << endl;
                     //time.StartTimer();

                //if(newSphere[z].x+newSphere[z].R<boundaries[3]&& newSphere[z].x-newSphere[z].R>boundaries[2]&& newSphere[z].y+newSphere[z].R<boundaries[1]&& newSphere[z].y+newSphere[z].R>boundaries[0]&& newSphere[z].z+newSphere[z].R<boundaries[5]&& newSphere[z].z-newSphere[z].R>boundaries[4])
               // {
                    if(!search->intersect(newSphere[z], neighbours))
                    {
                        //  std::cout<<"dedame\n";
                      //  time.StartTimer();
                        if(bounds->check(newSphere[z]) ){
                           // Neideti_taskai.pop_back();
                            //newSphere[z].PrintStructure();
                            search->addPoint(newSphere[z]);
                            //newSphere[z].PrintStructure();
                            //cout << "idetas taskas " << endl;
                            if(isvedimo_kintamasis==0){
                            writer->write(data, search, duomenys, poringumas);
                            isvedimo_kintamasis=10000;
                            }
                            F.push_back(data->getNumberOfPoints()-1);
                            daleliu_turis+=(4.0/3.0)*PI*pow(newSphere[z].R,3);
                            //cout << j << " "   << newSphere[z].R << " " << daleliu_turis << " ismatavimai " << endl;
                            //cout << F.size() << "daleliu kiekis" << endl;
                            i++;
                            isvedimo_kintamasis--;
                            new_R=random->getNextValue();
                        }
                       // time.StopTimer();
                       // rez_time+=time.ElapsedTime("sec");
                    }
               // }
              }
/* parasyta neidetu tasku funkcija /// letina programa
                for(int k=0;k<Neideti_taskai.size();k++){
                    if(!search->intersect(Neideti_taskai[k], neighbours))
                    {
                        //  std::cout<<"dedame\n";
                        if(bounds->check(Neideti_taskai[k])){
                            Neideti_taskai.pop_back();
                            //newSphere[z].PrintStructure();
                            search->addPoint(Neideti_taskai[k]);
                            F.push_back(data->getNumberOfPoints()-1);
                            daleliu_turis+=(4.0/3.0)*PI*pow(Neideti_taskai[k].R,3);
                            //cout << j << " "   << newSphere[z].R << " " << daleliu_turis << " ismatavimai " << endl;
                            //cout << F.size() << "daleliu kiekis" << endl;
                            i++;
                        }
                    }
                   }
                */

                }

                   // auto end = std::chrono::high_resolution_clock::now();
                  // duration<double> time_span = duration_cast<duration<double>>(end - begin);
                  // time=time_span.count();

                   // F_index++;

                }



                           // time.StopTimer();
        if(check==i)
           {
            //F[rand_particle_index]=-1;
            //F.erase(std::remove(F.begin(), F.end(), rand_particle_index), F.end());
            remove(F.begin(),F.end(), rand_particle_index);
            F.pop_back();
           }
       // cout << F.size() << " f dydis " <<  endl;

        std::cout<<"viso daleliu "<<data->getNumberOfPoints()<<"\n";
        std::cout <<"poringumas "<< daleliu_turis/figuros_turis << endl;
       //std::cout <<"koordinacinis numeris "<< koord << endl;


}

    while(F.size());

   // cout << time.CumulativeTime("sec") << endl;
   //cout << programos_laikas << " " << " intersect funkcijos laikas " << endl;
    poringumas=daleliu_turis/figuros_turis;
    std::cout<<"packing done\n";
}

void SpherePackingAlgorithm::initialization()
{
    for(int i=0;i<data->getNumberOfPoints();i++){
        F.push_back(i);
    }
    std::cout<<"Performing initialization\n";
}
