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
    INT getNumberOfPoints_v();
    PointType getPoint_v(INT i);
    void insertNextPoint_v(PointType p);
private:
    PointsArrayType data; /// tik daleles kuriuose ieskomi kaimynai


};

#endif // DATA_H
