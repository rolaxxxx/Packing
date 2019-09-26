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
};

#endif // CYLINDERSHAPE_H
