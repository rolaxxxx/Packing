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
    PointType getFinalVectorPoint(INT i);

    void insertNextFinalVector(PointType p);

    void insertNextPoint(INT idx, INT particle);

     std::vector<INT> getPoints(INT i);
    void removePoint(INT p);

    INT getNumberOfPoints();
    INT getFinalVectorNumberOfPoints();
    INT getNumberOfPoints_v();


    PointType getPoint_v(INT i);
    void insertNextPoint_v(PointType p);
private:
    PointsArrayType data; /// tik daleles kuriuose ieskomi kaimynai



};

#endif // DATA_H
