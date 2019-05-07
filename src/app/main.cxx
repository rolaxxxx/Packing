#include "random/RandomFactory.h"
#include "search/SearchFactory.h"
#include "algorithm/AlgorithmFactory.h"
#include "core/Data.h"
#include "IO/Reader.h"
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
    kint1.x=-15;
    kint1.y=-15;
    kint1.z=-15;

    kint2.x=15;
    kint2.y=15;
    kint2.z=15;

    double RMAX=0.4;
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


   random->init(RMAX,RMAX,10);

    search->init(data, kint1, kint2,RMAX);

    search->addPoint(P1);
    search->addPoint(P2);
    search->addPoint(P3);



	//cout << search->getMapSIZE() << endl; testuoju ar elementai per init funkcija is data masyvo isidejo i suformuota grida
    algorithm->init(data,random,search,10);

    /// atliekame tikraji pakinima
    algorithm->pack();
    writer.write(data, search, "output.vtk");// irasome rezultata
    return 0;

}
