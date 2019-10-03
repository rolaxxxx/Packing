#ifndef CYLINDERSHAPE_H
#define CYLINDERSHAPE_H
#include "BBoundaries.h"

class CylinderShape : public BBoundaries
{
public:
    CylinderShape();
    bool check(Point newSphere);
protected:
    void initialization(json duomenys);
	    REAL radius;
    REAL height;
    double getRadius() const;
    double getHight() const;
};

#endif // CYLINDERSHAPE_H
