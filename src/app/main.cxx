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




    ///viska inicializuojame ka reikia
    ///
    Point kint1, kint2;
    kint1.x=0;
    kint1.y=0;
    kint1.z=0;

    kint2.x=1;
    kint2.y=1;
    kint2.z=1;
    random->init(1,2,10);
    search->init(data,kint1,kint2,2);
    algorithm->init(data,random,search);

    /// atliekame tikraji pakinima
    algorithm->pack();
    writer.write(data,"output.vtk");// irasome rezultata
    return 0;
}
