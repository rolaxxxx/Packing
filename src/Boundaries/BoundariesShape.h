#ifndef BOUNDARIESSHAPE_H
#define BOUNDARIESSHAPE_H



#include "BBoundaries.h"
enum class BoundsTypes
{
    Cube, Cylinder
};
class BoundariesShape{

public:
    BoundariesShape();
    BBoundaries* create(std::string type);

};

#endif
