#include "SpherePackingAlgorithm.h"

using namespace std;
SpherePackingAlgorithm::SpherePackingAlgorithm()
{

}
void SpherePackingAlgorithm::pack()
{
     INT rand_particle_index;
     vector<INT>neighbours;


     PointsArrayType negative_positive_positions;
     //cout << data->getNumberOfPoints() << endl;
     INT temp;
     int i = 0;
     std::random_device rd;  //Will be used to obtain a seed for the random number engine
     std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
     while(i<count){
         std::uniform_int_distribution<> dis(0, data->getNumberOfPoints());
         rand_particle_index = dis(gen);

        

        neighbours=search->getNeighboursID(rand_particle_index);

        //cout <<"radn "<< rand_particle_index << " " << neighbours.size()  <<" "<< data->getNumberOfPoints()<< endl;
        temp = rand_particle_index;

        //cout << data->getNumberOfPoints() << endl;
        //cout << rand_particle_index << endl;
        //cout << neighbours.size() << endl;


        //tikrinti nes skaiciavimuose kaimynai atsiranda du vienodi nors ir reiksmes skirtingos 1 0 2  o pointai gaunasi du vienodi
        //cout <<  neighbours[0] << " " << neighbours[1] << " " << rand_particle_index <<  endl;
            for (INT j = 0; j < neighbours.size() ; j++){
                            for (INT l = j+1; l < neighbours.size() ; l++) {
                //tikrinamos ne visos koombinacijos
                //cout << temp << " " << rand_particle_index << endl;
                   //cout << neighbours[j] << " " << neighbours[l] <<  " " << rand_particle_index << endl;
                                /*cout << " taskai su kuriais skaiciuota "<< data->getPoint(neighbours[j]).x <<
                                " "<< data->getPoint(neighbours[j]).y <<
                                " "<< data->getPoint(neighbours[j]).z<<

                                "||"<< data->getPoint(neighbours[l]).x <<
                                " "<< data->getPoint(neighbours[l]).y <<
                                " "<< data->getPoint(neighbours[l]).z<<

                                " ||"<< data->getPoint(neighbours[rand_particle_index]).x <<
                                " "<< data->getPoint(neighbours[rand_particle_index]).y <<
                                " "<< data->getPoint(neighbours[rand_particle_index]).z<< endl;
*/

                    //cout << data->getNumberOfPoints() << " " << neighbours.size()<< " " << neighbours[j] << " " << neighbours[j + 1] << " " << rand_particle_index << endl;
                    REAL rand_r = random->getNextValue();
                    //cout << rand_r << endl;
                    negative_positive_positions = math.getSpheresTouchingThreeOtherSpheres(data->getPoint(neighbours[j]), data->getPoint(neighbours[l]), data->getPoint(rand_particle_index), rand_r);


                    //cout <<neighbours.size() <<" "<< negative_positive_positions[1].x << " " << negative_positive_positions[1].y <<" " <<
                     /*negative_positive_positions[1].z <<" "<< negative_positive_positions[1].R <<
                                                                " taskai su kuriais skaiciuota "<< data->getPoint(neighbours[j]).x <<
                                                                " "<< data->getPoint(neighbours[j]).y <<
                                                                " "<< data->getPoint(neighbours[j]).z<<

                                                                "||"<< data->getPoint(neighbours[l]).x <<
                                                                " "<< data->getPoint(neighbours[l]).y <<
                                                                " "<< data->getPoint(neighbours[l]).z<<

                                                                " ||"<< data->getPoint(neighbours[rand_particle_index]).x <<
                                                                " "<< data->getPoint(neighbours[rand_particle_index]).y <<
                                                                " "<< data->getPoint(neighbours[rand_particle_index]).z<< endl;


*/
                  // cout << negative_positive_positions[0].x << " " << negative_positive_positions[0].y <<
                   //   negative_positive_positions[0].z << negative_positive_positions[0].R << endl;

                    if ((search->intersect(negative_positive_positions[0], rand_particle_index)))
                    {
                        search->addPoint(negative_positive_positions[0]);
                        i++;
                        j = neighbours.size();
                        // cout << " " << neighbours[j] << " " << neighbours[j + 1] << " " << rand_particle_index << endl;
                     //cout <<" " << negative_positive_positions[0].x << " " << negative_positive_positions[0].y <<
                         //   " " << negative_positive_positions[0].z <<" " <<  negative_positive_positions[0].R << endl;
                        break;
                    }
                    else if ((search->intersect(negative_positive_positions[1], rand_particle_index))) //praeina nan(ind)
                    {
                        search->addPoint(negative_positive_positions[1]);
                         //cout <<" " << negative_positive_positions[1].x << " " << negative_positive_positions[1].y <<
                          //     " " << negative_positive_positions[1].z << " " << negative_positive_positions[1].R << endl;
                        i++;
                        j = neighbours.size();
                        break;

                    }
            }
        }


}
 std::cout<<"packing done\n";
}

void SpherePackingAlgorithm::initialization()
{
    std::cout<<"Performing initialization\n";
}
