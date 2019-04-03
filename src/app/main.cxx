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
    random->init(1,2,10);
    search->init(data,0,0,0,1,1,1,2);
    algorithm->init(data,random,search);

    /// atliekame tikraji pakinima
    algorithm->pack();
    writer.write(data,"output.vtk");// irasome rezultata
    return 0;
}
