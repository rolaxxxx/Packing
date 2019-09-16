#ifndef MESH_H
#define MESH_H

#include "BBoundaries.h"
#include "core/Constants.h"
#include "core/Point.h"

class Mesh: public BBoundaries{

public:
    Mesh();
    bool check(Point newSphere);
    int IntersectLineTriangle(Point p, Point q, Point a, Point b, Point c);
    bool SameSign(int x, int y);
    int PointInTriangle(Point p, Point a, Point b, Point c);
protected:
    void initialization(json duomenys);

};

#endif
