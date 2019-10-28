#ifndef AALGORITHM_H
#define AALGORITHM_H
#include "Boundaries/BBoundaries.h"
#include "IO/Writer.h"
#include "core/Constants.h"
#include "core/Data.h"
#include "core/Math.h"
#include "random/ARandom.h"
#include "search/ASearch.h"
class AAlgorithm {
public:
  AAlgorithm();
  void init(Data *data, ARandom *random, ASearch *search, json duomenys,
            BBoundaries *bounds, INT count, Writer writer);
  virtual void pack() = 0;
  REAL getPoringumas() const;

  void setPoringumas(const REAL &value);

protected:
  virtual void initialization() = 0;
  ARandom *random;
  ASearch *search;
  INT count;
  Math math;
  Data *data;
  json duomenys;
  Writer *writer;
  BBoundaries *bounds;
  REAL poringumas;
  std::string rez_switch;
  INT amount_particles;
  double *boundaries;
};

#endif // AALGORITHM_H
