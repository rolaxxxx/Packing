#ifndef CUBESHAPE_H
#define CUBESHAPE_H

#include "BBoundaries.h"

class CubeShape : public BBoundaries {

public:
  CubeShape();
  bool check(Point newSphere);

protected:
  void initialization(json duomenys);
  Point min;
  Point max;
};

#endif
