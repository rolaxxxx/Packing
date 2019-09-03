#include "AAlgorithm.h"

AAlgorithm::AAlgorithm()
{

}
void AAlgorithm::init(Data *data, ARandom *random, ASearch *search, json duomenys, BBoundaries *bounds, INT count, Writer writer)
{

    this->data=data;
    this->random=random;
    this->search=search;
    this->bounds=bounds;
    this->duomenys=duomenys;
    this->count=count;
    this->boundaries=bounds->getBounds();
    this->initialization();
}

REAL AAlgorithm::getPoringumas() const
{
    return poringumas;
}

void AAlgorithm::setPoringumas(const REAL &value)
{
    poringumas = value;
}


