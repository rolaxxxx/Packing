#include "ARandom.h"

ARandom::ARandom()
{

}

void ARandom::init(json duomenys)
{
     min=duomenys["DISTRIBUTION"]["RMIN"];
     max=duomenys["DISTRIBUTION"]["RMAX"];

    this->initialization(duomenys);
}


