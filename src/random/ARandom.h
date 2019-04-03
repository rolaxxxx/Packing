#ifndef ARANDOM_H
#define ARANDOM_H
#include "core/Constants.h"

class ARandom
{
public:
    ARandom();
    virtual REAL getNextValue()=0;
    void init(REAL minValue,REAL maxValue,INT count);
protected:
    virtual void initialization()=0;
    INT count;
    REAL minValue;
    REAL maxValue;
};

#endif // ARANDOM_H
