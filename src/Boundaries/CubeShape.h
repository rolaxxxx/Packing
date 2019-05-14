#ifndef CUBESHAPE_H
#define CUBESHAPE_H

#include "BBoundaries.h"

class CubeShape: public BBoundaries{

public:
    CubeShape();
    bool check(Point newSphere, Point min, Point max);
protected:
    void initialization();
};

#endif
