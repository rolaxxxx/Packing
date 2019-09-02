#ifndef MESH_H
#define MESH_H

#include "BBoundaries.h"
#include "core/Constants.h"

class Mesh: public BBoundaries{

public:
    Mesh();
    bool check(Point newSphere);
    int IntersectLineTriangle(Point p, Point q, Point a, Point b, Point c);
    bool SameSign(int x, int y);
protected:
    void initialization(json duomenys);

};

#endif
