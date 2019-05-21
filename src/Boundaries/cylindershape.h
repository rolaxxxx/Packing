#ifndef CYLINDERSHAPE_H
#define CYLINDERSHAPE_H
#include "BBoundaries.h"

class CylinderShape : public BBoundaries
{
public:
    CylinderShape();
    bool check(Point newSphere, Point min, Point max);
protected:
    void initialization();
};

#endif // CYLINDERSHAPE_H
