#ifndef ASEARCH_H
#define ASEARCH_H
#include "core/Data.h"

class ASearch
{
public:
    ASearch();
    void init(Data*data,REAL bminx,REAL bminy,REAL bminz,REAL bmaxx,REAL bmaxy,REAL bmaxz,REAL RMax);
    virtual std::vector<INT> getNeighboursID(INT id)=0;
    virtual bool intersectionTest(PointType p)=0;
    virtual PointsArrayType getNeighboursPoints(INT id)=0;
    virtual void addPoint(PointType p)=0;
protected:
    virtual void initialization()=0;

    Data*data;
    REAL bminx;
    REAL bminy;
    REAL bminz;
    REAL bmaxx;
    REAL bmaxy;
    REAL bmaxz;
    REAL RMax;
    REAL CELL_SIZE;
};

#endif // ASEARCH_H
