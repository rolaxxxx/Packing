#ifndef AALGORITHM_H
#define AALGORITHM_H
#include "random/ARandom.h"
#include "search/ASearch.h"
#include "Boundaries/BBoundaries.h"
#include "core/Math.h"
#include "core/Data.h"
#include "core/Constants.h"
#include "IO/Writer.h"
class AAlgorithm
{
public:
    AAlgorithm();
    void init(Data*data,ARandom *random,ASearch *search, json duomenys, BBoundaries *bounds, INT count, Writer writer);
    virtual void pack()=0;
    REAL getPoringumas() const;


    void setPoringumas(const REAL &value);

protected:
    virtual void initialization()=0;
    ARandom *random;
    ASearch *search;
    INT count;
    Math math;
    Data*data;
    json duomenys;
    Writer *writer;
    BBoundaries *bounds;
    REAL poringumas;
    double * boundaries;



};

#endif // AALGORITHM_H
