#include "ARandom.h"

ARandom::ARandom()
{

}

void ARandom::init( REAL minValue,REAL maxValue,INT count)
{
    this->count=count;
    this->minValue=minValue;
    this->maxValue=maxValue;
    this->initialization();
}

std::vector<REAL> ARandom::getIntervals() const
{
    return intervals;
}

std::vector<REAL> ARandom::getProbs() const
{
    return probs;
}
