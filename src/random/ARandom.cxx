#include "ARandom.h"

ARandom::ARandom()
{

}

void ARandom::init(REAL minValue,REAL maxValue,INT count, std::vector<REAL> probs )
{
    this->count=count;
    this->minValue=minValue;
    this->maxValue=maxValue;
    this->probs=probs;
    this->delta_R=(this->maxValue-this->minValue)/(count-1);
    REAL temp_R=this->minValue;
    for(int i=0;i<count;i++){
        //std::cout << temp_R << endl;
        this->intervals.push_back(temp_R);
        temp_R+=this->delta_R;
    }

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
