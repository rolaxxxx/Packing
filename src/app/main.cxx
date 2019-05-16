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

      kint2.x=15;
      kint2.y=15;
      kint2.z=15;


     /*
      VAR		Fraction 1	Fraction 2	Fraction 3	Fraction 4	Fraction 5	Fraction 6
      1	R	0.003
          Probability	100
      2	R	0.002
          Probability	100
      3	R	0.001
          Probability	100
      4	R	0.0005	0.0007	0.0009	0.0012
          Probability	27	36	30	7


Cilindras	Diametras	0.3	pasidaryti spinduli
    Ilgis	0.22

          */


      /*
       * Kubas	x	0.025	0	VAR		Fraction 1	Fraction 2	Fraction 3	Fraction 4	Fraction 5	Fraction 6	Fraction 7
    y	0.005	0	1	R	1.00E-04
    z	0.001	0		Probability	100
                2	R	2.00E-04
Kubas	x	0.025	0		Probability	100
    y	0.01	0	3	R	1.50E-04
    z	0.001	0		Probability	100
                4	R	5.00E-05	7.00E-05	9.00E-05	1.10E-04	1.30E-04	1.50E-04	1.70E-04
Kubas	x	0.05	0		Probability	3	4	8	14	21	20	17
    y	0.01	0	5	R	2.50E-05	3.50E-05	4.50E-05	5.50E-05	6.50E-05	7.50E-05	8.50E-05
    z	0.001	0		Probability	3	4	8	14	21	20	17

      */

      double RMAX=0.74;
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
  probabilities.push_back(1);

     random->init(RMAX,RMAX,1, probabilities);

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
      //cout << search->getMapSIZE() << endl; testuoju ar elementai per init funkcija is data masyvo isidejo i suformuota grida
     algorithm->init(data,random,search, bounds, 10);

      /// atliekame tikraji pakinima
      //algorithm->pack();
     writer.write(data, search, intervals, probabilities, "output.vtk");// irasome rezultata
  return 0;

}
