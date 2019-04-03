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
    INT getNumberOfPoints();
private:
    PointsArrayType data;
};

#endif // DATA_H
