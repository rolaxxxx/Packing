#ifndef AALGORITHM_H
#define AALGORITHM_H
#include "random/ARandom.h"
#include "search/ASearch.h"
#include "core/Math.h"
#include "core/Data.h"

class AAlgorithm
{
public:
    AAlgorithm();
    void init(Data*data,ARandom *random,ASearch *search, INT count);
    virtual void pack()=0;
protected:
    virtual void initialization()=0;
    ARandom *random;
    ASearch *search;
    INT count;
    Math math;
    Data*data;


};

#endif // AALGORITHM_H
