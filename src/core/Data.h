#ifndef DATA_H
#define DATA_H
#include "core/Constants.h"
#include "core/Point.h"

class Data
{
public:
    Data();
    void insertNextPoint(PointType p);

    PointType getPoint(INT i);

    void insertNextPoint(INT idx, INT particle);

     std::vector<INT> getPoints(INT i);


    INT getNumberOfPoints();
private:
    PointsArrayType data; /// tik daleles kuriuose ieskomi kaimynai
    PointsArrayType data_v;///visos daleles su tomis kur kaimynai nera ieskomi (formuojama vizualizacija
    std::map<INT, std::vector<INT>> SUFORMUOTAS_GRIDAS;

};

#endif // DATA_H
