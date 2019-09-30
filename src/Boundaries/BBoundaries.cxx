#include "BBoundaries.h"


BBoundaries::BBoundaries()
{

}

void BBoundaries::init(ASearch *search, json duomenys)
{
    this->search=search;
    this->duomenys=duomenys;
    this->bounds=new double[6];
    this->initialization(this->duomenys);
}



double *BBoundaries::getBounds() const
{
    return bounds;
}

REAL BBoundaries::getTuris() const
{
    return turis;
}



