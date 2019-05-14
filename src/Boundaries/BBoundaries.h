#ifndef BBOUNDARIES_H
#define BBOUNDARIES_H


#include "core/Constants.h"
#include "search/ASearch.h"


class BBoundaries
{
public:
   BBoundaries();
    void init(ASearch *search);
    virtual bool check(Point sph, Point min, Point max)=0;

protected:
    virtual void initialization()=0;
    ASearch *search;

};

#endif
