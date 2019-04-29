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
    kint1.x=0;
    kint1.y=0;
    kint1.z=0;

    kint2.x=50;
    kint2.y=50;
    kint2.z=50;

    P1.x=0.5;
    P1.y=0.3;
    P1.z=0.2;
    P1.R=1;

    P2.x=1.75;
    P2.y=1.599;
    P2.z=-0.666;
    P2.R=1;

    P3.x=0.375;
    P3.y=2.24856;
    P3.z=0.633012;
    P3.R=1;


    random->init(0.5,1,10);

    search->init(data, kint1, kint2, 2);

	search->addPoint(P1);
	search->addPoint(P2);
	search->addPoint(P3);


    
	//cout << search->getMapSIZE() << endl; testuoju ar elementai per init funkcija is data masyvo isidejo i suformuota grida
    algorithm->init(data,random,search,10);

    /// atliekame tikraji pakinima
    algorithm->pack();
    writer.write(data,"output.vtk");// irasome rezultata
    return 0;
}
