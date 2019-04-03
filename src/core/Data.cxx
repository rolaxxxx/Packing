#include "Data.h"

Data::Data()
{

}
void Data::insertNextPoint(PointType p)
{
    data.push_back(p);
}
void Data::insertNextPoint(INT idx, INT particle){
    SUFORMUOTAS_GRIDAS[idx].push_back(particle);
}
std::vector<INT> Data::getPoints(INT i)
{
    return SUFORMUOTAS_GRIDAS.at(i);
}
PointType Data::getPoint(INT i)
{
    return data[i];
}

INT Data::getNumberOfPoints()
{
    return data.size();
}

