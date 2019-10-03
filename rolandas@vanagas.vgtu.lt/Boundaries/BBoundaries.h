#ifndef BBOUNDARIES_H
#define BBOUNDARIES_H


#include "core/Constants.h"
#include "search/ASearch.h"
#include "core/Point.h"

class BBoundaries
{
public:
   BBoundaries();
    void init(ASearch *search, json duomenys);
    virtual bool check(Point newSphere)=0;


     double *getBounds() const;

     REAL getTuris() const;

protected:
     virtual void initialization(json duomenys)=0;
    ASearch *search;
    json duomenys;

    Point center;
    Point min;
    Point max;
    
    int tria_kiekis;
    double rez=0;
	REAL turis;


    double * bounds;
};

#endif
