#ifndef ASEARCH_H
#define ASEARCH_H
#include "core/Data.h"
#include "core/Constants.h"

class ASearch
{
public:
    ASearch();
    void init(Data*data,Point bmin, Point bmax,REAL RMax);
    virtual std::vector<INT> getNeighboursID(INT id)=0;
    virtual bool intersectionTest(PointType p)=0;
    virtual PointsArrayType getNeighboursPoints(INT id)=0;
    virtual void addPoint(PointType p)=0;
protected:
    virtual void initialization()=0;

    Data*data;
    Point bmax;
    std::map<INT, std::vector<INT>>SUFORMUOTAS_GRIDAS;
    Point bmin;// min max bounds
    INT Nx;
    INT Ny;
    INT Nz;
    REAL RMax;
    REAL CELL_SIZE;
};

#endif // ASEARCH_H
