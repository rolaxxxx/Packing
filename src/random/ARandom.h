#ifndef ARANDOM_H
#define ARANDOM_H
#include "core/Constants.h"


class ARandom
{
public:
    ARandom();
    virtual REAL getNextValue()=0;
    void init(json duomenys);

protected:
    virtual void initialization(json duomenys)=0;
    json duomenys;
	
};

#endif // ARANDOM_H
