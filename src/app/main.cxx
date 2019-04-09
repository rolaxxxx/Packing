#include "random/RandomFactory.h"
#include "search/SearchFactory.h"
#include "algorithm/AlgorithmFactory.h"
#include "core/Data.h"
#include "IO/Reader.h"
#include "IO/Writer.h"

int main()
{

    Reader reader;
    Writer writer;
    Data * data=new Data();
    //nuskaitome duomenis is failo jeigu to reikia
    reader.read(data,"input.vtk");
    // galime ir rankomis sudeti pradinius taskus, naudojant Data klases objekta


    RandomFactory randomFactory;
    SearchFactory searchFactory;
    AlgorithmFactory algorithmFactory;

    ARandom * random=randomFactory.create(RandomTypes::Uniform);
    ASearch * search =searchFactory.create(SearchTypes::Uniform);
    AAlgorithm*algorithm=algorithmFactory.create(AlgorithmType::SpherePackingAlgorithm);
    PointType P1, P2, P3;

    ///viska inicializuojame ka reikia
    ///
    Point kint1, kint2;
    kint1.x=0;
    kint1.y=0;
    kint1.z=0;

    kint2.x=1;
    kint2.y=1;
    kint2.z=1;

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

    data->insertNextPoint(P1);
    data->insertNextPoint(P2);
    data->insertNextPoint(P3);


    random->init(1,2,10);
    search->init(data,kint1,kint2,2);
    algorithm->init(data,random,search, 10);

    /// atliekame tikraji pakinima
    algorithm->pack();
    writer.write(data,"output.vtk");// irasome rezultata
    return 0;
}
