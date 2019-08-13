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
    /*std::set<PointType>::iterator it;
    it=data.begin();
    std::advance(it,i);
    return *it;
    */
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

PointsArrayType Data::getData() const
{
    return data;
}

//std::string Data::getVtk_duomenys() const
//{
//return output;
//}

//void Data::setVtk_duomenys(const std::string &value)
//{
    //output = value;
//}







