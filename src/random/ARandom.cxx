#include "ARandom.h"

ARandom::ARandom()
{

}

void ARandom::init(json duomenys)
{

    this->count=duomenys["DISTRIBUTION"]["COUNT"];
    this->minValue=duomenys["DISTRIBUTION"]["RMIN"];
    this->maxValue=duomenys["DISTRIBUTION"]["RMAX"];
    this->initialization(duomenys);
}
