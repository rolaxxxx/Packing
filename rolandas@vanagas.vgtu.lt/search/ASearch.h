#ifndef ASEARCH_H
#define ASEARCH_H
#include "core/Data.h"
#include "core/Constants.h"


class ASearch
{
public:
    ASearch();
    void init(Data*data,json duomenys);
    virtual std::vector<INT> getNeighboursID(INT id)=0;
    virtual std::vector<INT> getGridNeigbours(INT id)=0;

    virtual bool intersect(PointType id, std::vector<INT>neighbours)=0;

    virtual void addPoint(PointType p)=0;
    Point getBmax() const;

    Point getBmin() const;

    INT getNx() const;

    INT getNy() const;

    INT getNz() const;

    void SetBounds(double *boundai);

protected:
    virtual void initialization()=0;

    Data*data;
    json duomenys;
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
    double rez=0;
};

#endif // ASEARCH_H
