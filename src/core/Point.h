#ifndef POINT_H
#define POINT_H

#include "core/Constants.h"

struct Point
{
    REAL x;
    REAL y;
    REAL z;
    REAL R;
};

typedef Point PointType;
typedef std::vector<PointType> PointsArrayType;

//// TODO operatorius perkrauti kad butu patogu matematinius vieksmus atlikti, cia tik aprasai, kodas i cxx faila.
/// tai butu +,-,daugyba dalyba is skaliaro, cross product, dot product, vektoriaus ilgis

#endif // POINT_H
