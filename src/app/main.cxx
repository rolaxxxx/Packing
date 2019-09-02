#include "random/RandomFactory.h"
#include "search/SearchFactory.h"
#include "algorithm/AlgorithmFactory.h"
#include "Boundaries/BoundariesShape.h"
#include "core/Data.h"
#include "IO/Reader.h"
#include "core/time.h"
#include "IO/Writer.h"
using namespace std;
int main(int argc, char** argv)
{

    Reader reader;
      Writer writer;


      Data * data=new Data();

      //nuskaitome duomenis is failo jeigu to reikia
      reader.read(data, argv[1]);
      // galime ir rankomis sudeti pradinius taskus, naudojant Data klases objekta
      srand(time(NULL));
      ///koks failo formatas turi buti paduotas i funkcija dabar paduodamas string formatas
      auto duomenys=json::parse(data->getDuomenys());

      RandomFactory randomFactory;
      SearchFactory searchFactory;
      AlgorithmFactory algorithmFactory;
      BoundariesShape shape;

      ARandom * random=randomFactory.create(duomenys["DISTRIBUTION"]["TYPE"]);
      ASearch * search =searchFactory.create(duomenys["SEARCH"]["TYPE"]);
      AAlgorithm*algorithm=algorithmFactory.create(duomenys["ALGORITHM"]["TYPE"]);

      BBoundaries * bounds=shape.create(duomenys["BOUNDARIES"]["TYPE"]);
       bounds->init(search, duomenys);
      search->SetBounds(bounds->getBounds());
      PointType P1, P2, P3, P4;

      double RMAX=duomenys["DISTRIBUTION"]["RMAX"];
      double * boundaries;
      boundaries=bounds->getBounds();
      Point half_bounds;

      half_bounds.x=(boundaries[1]+boundaries[0])/2;
      half_bounds.y=(boundaries[3]+boundaries[2])/2;
      half_bounds.z=(boundaries[5]+boundaries[4])/2;
      cout << " bounds struktura " << endl;
              half_bounds.PrintStructure();
        //cout << "boundaries " << boundaries[0] << " " << boundaries[1] << " " << " " << boundaries[2]<< " " << boundaries[3]<< " " << boundaries[4] << " " << boundaries[5] << endl;
      P1.x=half_bounds.x;
      P1.y=half_bounds.y;
      P1.z=half_bounds.z;
      P1.R=RMAX;

      P2.x=(half_bounds.x)+2*RMAX;
      P2.y=half_bounds.y;
      P2.z=half_bounds.z;
      P2.R=RMAX;

      P3.x=half_bounds.x+RMAX;
      P3.y=(2.0*RMAX*sqrt(3.0)/2.0)+half_bounds.y;
      P3.z=half_bounds.z;
      P3.R=RMAX;
    //cout << duomenys["DISTRIBUTION"]["TYPE"] << endl;

     random->init(duomenys);
      search->init(data, duomenys);

     search->addPoint(P1);
     search->addPoint(P2);
     search->addPoint(P3);

     algorithm->init(data,random,search, duomenys, bounds, 10);

      /// atliekame tikraji pakinima
      algorithm->pack();
     writer.write(data, search, duomenys, algorithm->getPoringumas());// irasome rezultata


     return 0;

}
