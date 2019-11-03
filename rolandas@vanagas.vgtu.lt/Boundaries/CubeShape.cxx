#include "CubeShape.h"

CubeShape::CubeShape() {}
bool CubeShape::check(Point newSphere) {

  if (newSphere.x + newSphere.R < max.x && newSphere.y + newSphere.R < max.y &&
      newSphere.z + newSphere.R < max.z && newSphere.x - newSphere.R > min.x &&
      newSphere.y - newSphere.R > min.y && newSphere.z - newSphere.R > min.z)
    return true;
  else
    return false;
}
void CubeShape::initialization(json duomenys) {
  bounds[0] = duomenys["BOUNDARIES"]["BMIN"][0];
  bounds[1] = duomenys["BOUNDARIES"]["BMAX"][0];
  bounds[2] = duomenys["BOUNDARIES"]["BMIN"][1];

  bounds[3] = duomenys["BOUNDARIES"]["BMAX"][1];
  bounds[4] = duomenys["BOUNDARIES"]["BMIN"][2];
  bounds[5] = duomenys["BOUNDARIES"]["BMAX"][2];

  min.x = duomenys["BOUNDARIES"]["BMIN"][0];
  min.y = duomenys["BOUNDARIES"]["BMIN"][1];
  min.z = duomenys["BOUNDARIES"]["BMIN"][2];

  max.x = duomenys["BOUNDARIES"]["BMAX"][0];
  max.y = duomenys["BOUNDARIES"]["BMAX"][1];
  max.z = duomenys["BOUNDARIES"]["BMAX"][2];

  turis = fabs(bounds[1] - bounds[0]) * fabs(bounds[3] - bounds[2]) *
          fabs(bounds[5] - bounds[4]);
  // uspildai
}
