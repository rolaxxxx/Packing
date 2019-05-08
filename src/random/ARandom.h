#ifndef ARANDOM_H
#define ARANDOM_H
#include "core/Constants.h"

class ARandom
{
public:
    ARandom();
    virtual REAL getNextValue()=0;
    void init(REAL minValue,REAL maxValue,INT count, std::vector<REAL> probs);
protected:
    virtual void initialization()=0;
    INT count;
    REAL minValue;
    REAL maxValue;
    REAL delta_R;
    std::vector<REAL> intervals;
    std::vector<REAL> probs ; // is main paimti
};

#endif // ARANDOM_H
