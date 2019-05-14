#ifndef BOUNDARIESSHAPE_H
#define BOUNDARIESSHAPE_H


#include "BBoundaries.h"
enum class BoundsTypes
{
    Cube
};
class BoundariesShape{

public:
    BoundariesShape();
    BBoundaries* create(BoundsTypes type);

};

#endif
