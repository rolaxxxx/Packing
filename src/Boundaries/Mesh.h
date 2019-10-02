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
    int PointInTriangle(Point p, Point a, Point b, Point c);
    Point ClosestPtPointTriangle(Point p, Point a, Point b, Point c);
    void Barycentric(Point a, Point b, Point c, Point p, REAL &u, REAL &v, REAL &w);
    inline REAL TriArea2D(REAL x1, REAL y1, REAL x2, REAL y2, REAL x3, REAL y3);
protected:
    void initialization(json duomenys);
	std::vector<Point> taskai;
};

#endif
