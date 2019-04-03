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
///

    Point operator * (Point A, INT B);
    Point operator + (Point A, Point B);
    Point operator * (REAL A, Point B);
    Point operator * (Point A, Point B);
    Point operator / (Point A,  REAL B );
    Point operator - (Point A,  Point B );
    bool operator != (PointType A, PointType B);
    REAL dot_prod(Point vec_a, Point vec_b);
    Point cross_prod(Point vec_a, Point vec_b);
    REAL vector_len(Point vec);

#endif // POINT_H
