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

