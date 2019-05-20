#include "random/RandomFactory.h"
#include "search/SearchFactory.h"
#include "algorithm/AlgorithmFactory.h"
#include "Boundaries/BoundariesShape.h"
#include "core/Data.h"
#include "IO/Reader.h"
#include "core/time.h"
#include "IO/Writer.h"
using namespace std;
int main()
{


    Reader reader;
      Writer writer;
      Data * data=new Data();

      //nuskaitome duomenis is failo jeigu to reikia
      reader.read(data,"input.vtk");
      // galime ir rankomis sudeti pradinius taskus, naudojant Data klases objekta
      srand(time(NULL));

      RandomFactory randomFactory;
      SearchFactory searchFactory;
      AlgorithmFactory algorithmFactory;

      ARandom * random=randomFactory.create(RandomTypes::Uniform);
      ASearch * search =searchFactory.create(SearchTypes::Uniform);
      AAlgorithm*algorithm=algorithmFactory.create(AlgorithmType::SpherePackingAlgorithm);
      PointType P1, P2, P3, P4;

      ///viska inicializuojame ka reikia
      ///
      Point kint1, kint2;
      // bounds size
      kint1.x=0;
      kint1.y=0;
      kint1.z=0;

      kint2.x=0.05;
      kint2.y=0.01;
      kint2.z=0.001;

      double RMAX=8.50E-05;
      P1.x=0;
      P1.y=0;
      P1.z=0;
      P1.R=RMAX;

      P2.x=2*RMAX;
      P2.y=0;
      P2.z=0;
      P2.R=RMAX;

      P3.x=RMAX;
      P3.y=2.0*RMAX*sqrt(3.0)/2.0;
      P3.z=0;
      P3.R=RMAX;

  std::vector<REAL> probabilities;
  probabilities.push_back(3);
  probabilities.push_back(4);
  probabilities.push_back(8);
  probabilities.push_back(14);
  probabilities.push_back(21);
  probabilities.push_back(20);
  probabilities.push_back(17);

     random->init(2.50E-05,RMAX,7, probabilities);

     BoundariesShape shape;
     BBoundaries * bounds=shape.create(BoundsTypes::Cube);


    // for(int i=0;i<100;i++)
     //{
         //cout << random->getNextValue() << endl;


    // }

      search->init(data, kint1, kint2,RMAX);

     search->addPoint(P1);
     search->addPoint(P2);
     search->addPoint(P3);


     std::vector<REAL> intervals;
     intervals=random->getIntervals();
     //for(int i=0;i<intervals.size();i++){
      //      cout << intervals[i] << endl;

    // }
      //cout << search->getMapSIZE() << endl; testuoju ar elementai per init funkcija is data masyvo isidejo i suformuota grida
     algorithm->init(data,random,search, bounds, 10);

      /// atliekame tikraji pakinima
      algorithm->pack();
     writer.write(data, search, intervals, probabilities, algorithm->getPoringumas(), "output.vtk");// irasome rezultata
  return 0;

}
