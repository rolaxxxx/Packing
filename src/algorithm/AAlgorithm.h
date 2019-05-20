#ifndef AALGORITHM_H
#define AALGORITHM_H
#include "random/ARandom.h"
#include "search/ASearch.h"
#include "Boundaries/BBoundaries.h"
#include "core/Math.h"
#include "core/Data.h"
#include <core/Constants.h>
class AAlgorithm
{
public:
    AAlgorithm();
    void init(Data*data,ARandom *random,ASearch *search, BBoundaries *bounds, INT count);
    virtual void pack()=0;
    REAL getPoringumas() const;

protected:
    virtual void initialization()=0;
    ARandom *random;
    ASearch *search;
    INT count;
    Math math;
    Data*data;
    BBoundaries *bounds;
    REAL poringumas;


};

#endif // AALGORITHM_H
