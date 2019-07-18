#ifndef MESH_H
#define MESH_H

#include "BBoundaries.h"

class Mesh: public BBoundaries{

public:
    Mesh();
    bool check(Point newSphere);
protected:
    void initialization(json duomenys);
};

#endif
