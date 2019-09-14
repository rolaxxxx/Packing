#ifndef ARANDOM_H
#define ARANDOM_H
#include "core/Constants.h"


class ARandom
{
public:
    ARandom();
    virtual REAL getNextValue()=0;
    void init(json duomenys);
    std::vector<REAL> getIntervals() const;

    std::vector<REAL> getProbs() const;

    REAL getMinValue() const;

    REAL getMaxValue() const;

protected:
    virtual void initialization(json duomenys)=0;
    json duomenys;
	    std::vector<REAL>probs;
    std::vector<REAL>intervals;
};

#endif // ARANDOM_H
