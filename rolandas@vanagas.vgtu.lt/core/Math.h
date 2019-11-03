#ifndef MATH_H
#define MATH_H
#include "core/Constants.h"
#include "core/Point.h"

class Math {
public:
  Math();
  PointsArrayType getSpheresTouchingThreeOtherSpheres(PointType p1,
                                                      PointType p2,
                                                      PointType p3, REAL r);
  REAL getDistanceBetweenTwoSpheres(PointType p1, PointType p2);
};

#endif // MATH_H
