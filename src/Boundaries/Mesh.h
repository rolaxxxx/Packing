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
	void Barycentric(Point a, Point b, Point c, Point p, float &u, float &v, float &w);
	inline float TriArea2D(float x1, float y1, float x2, float y2, float x3, float y3);
protected:
    void initialization(json duomenys);

};

#endif
