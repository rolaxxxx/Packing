#include "Data.h"

Data::Data()
{

}

void Data::insertNextPoint(PointType p)
{
    data.push_back(p);
}
PointType Data::getPoint(INT i)
{
    return data[i];
}
INT Data::getNumberOfPoints()
{
    return data.size();
}

std::string Data::getDuomenys() const
{
    return duomenys;
}

void Data::setDuomenys(const std::string &value)
{
    duomenys = value;
}







