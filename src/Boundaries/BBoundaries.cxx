#include "BBoundaries.h"


BBoundaries::BBoundaries()
{

}

void BBoundaries::init(ASearch *search, json duomenys)
{
    this->search=search;
    this->duomenys=duomenys;
    this->initialization(duomenys);
}

double BBoundaries::getHight() const
{
    return height;
}
double BBoundaries::getRadius() const
{
    return radius;
}
