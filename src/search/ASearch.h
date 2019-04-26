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
    virtual std::vector<INT> getGridNeigbours(INT id)=0;
    virtual bool intersect(PointType id,  INT rand)=0;
    virtual void addPoint(PointType p)=0;
	virtual INT getMapSIZE()=0;
protected:
    virtual void initialization()=0;

    Data*data;

    Point bmax;
    Point bmin;// min max bounds
    INT Nx;
    INT Ny;
    INT Nz;
    PointType prad1;
    PointType prad2;
    PointType prad3;
    REAL RMax;
    REAL CELL_SIZE;
};

#endif // ASEARCH_H
