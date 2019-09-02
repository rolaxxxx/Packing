#include "BBoundaries.h"


BBoundaries::BBoundaries()
{

}

void BBoundaries::init(ASearch *search, json duomenys)
{
    this->search=search;
    this->duomenys=duomenys;
    this->bounds=new double[6];
    this->initialization(duomenys);
}

double BBoundaries::getHight() const
{
    return height;
}

double *BBoundaries::getBounds() const
{
    return bounds;
}
double BBoundaries::getRadius() const
{
    return radius;
}


