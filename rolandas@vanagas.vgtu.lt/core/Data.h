#ifndef DATA_H
#define DATA_H
#include "core/Constants.h"
#include "core/Point.h"

class Data {
public:
  Data();
  void insertNextPoint(PointType p);
  PointType getPoint(INT i);

  void insertNextPoint(INT idx, INT particle);
  INT getNumberOfPoints();
  void insertNextPoint_v(PointType p);

  std::string getDuomenys() const;
  void setDuomenys(const std::string &value);

  PointsArrayType getData() const;

  REAL getParticle_turis() const;

  bool getPack_done() const;
  void setPack_done(bool value);

private:
  PointsArrayType data; /// tik daleles kuriuose ieskomi kaimynai
  std::string duomenys;
  REAL particle_turis;
  bool pack_done=false;
};

#endif // DATA_H
