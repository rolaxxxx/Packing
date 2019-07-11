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

      ARandom * random=randomFactory.create(duomenys["DISTRIBUTION"]["TYPE"]);
      ASearch * search =searchFactory.create(duomenys["SEARCH"]["TYPE"]);
      AAlgorithm*algorithm=algorithmFactory.create(duomenys["ALGORITHM"]["TYPE"]);
      PointType P1, P2, P3, P4;

      double RMAX=duomenys["DISTRIBUTION"]["RMAX"];
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


    //cout << duomenys["DISTRIBUTION"]["TYPE"] << endl;

     random->init(duomenys);

     BoundariesShape shape;
     BBoundaries * bounds=shape.create(duomenys["BOUNDARIES"]["TYPE"]);
     bounds->init(search, duomenys);

      search->init(data, duomenys);

     search->addPoint(P1);
     search->addPoint(P2);
     search->addPoint(P3);

     algorithm->init(data,random,search, bounds, 10);

      /// atliekame tikraji pakinima
      algorithm->pack();
     writer.write(data, search, duomenys, algorithm->getPoringumas());// irasome rezultata


     return 0;

}
