#ifndef RANDOMUNIFORM_H
#define RANDOMUNIFORM_H
#include "ARandom.h"
#include "core/Constants.h"

class RandomUniform : public ARandom {
public:
  RandomUniform();
  REAL getNextValue();
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  boost::minstd_rand0 gen;

protected:
  void initialization(json duomenys);
  REAL min, max;
};

#endif // RANDOMUNIFORM_H
