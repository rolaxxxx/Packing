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
      ///koks failo formatas turi buti paduotas i funkcija dabar paduodamas string formatas
      auto duomenys=json::parse(data->getDuomenys());

      RandomFactory randomFactory;
      SearchFactory searchFactory;
      AlgorithmFactory algorithmFactory;

      ARandom * random=randomFactory.create(RandomTypes::Uniform);
      ASearch * search =searchFactory.create(SearchTypes::Uniform);
      AAlgorithm*algorithm=algorithmFactory.create(AlgorithmType::SpherePackingAlgorithm);
      PointType P1, P2, P3, P4;

      ///viska inicializuojame ka reikia
      //VAR		Fraction 1	Fraction 2	Fraction 3	Fraction 4
      //Cilindras	Diametras	0.3	pasidaryti spinduli	1	R	0.003
      //Ilgis	0.22	0		Probability	100
      //2R	0.002
      // Probability	100
      //3	R	0.001
      //Probability	100
      //4	R	0.0005	0.0007	0.0009	0.0012
      //Probability	27	36	30	7

      Point kint1, kint2;
      // bounds size
      kint1.x=0;
      kint1.y=0;
      kint1.z=0;

      kint2.x=0.005;
      kint2.y=0.005;
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
    cout << duomenys["DISTRIBUTION"]["TYPE"] << endl;

    /* random->init( RMAX,RMAX,1);

     BoundariesShape shape;
     BBoundaries * bounds=shape.create(BoundsTypes::Cube);

      search->init(data, kint1, kint2,RMAX);

     search->addPoint(P1);
     search->addPoint(P2);
     search->addPoint(P3);

     algorithm->init(data,random,search, bounds, 10);

      /// atliekame tikraji pakinima
      algorithm->pack();
     writer.write(data, search, intervals, probabilities, algorithm->getPoringumas(), "output.vtk");// irasome rezultata
  }
}
        */
     return 0;

}
