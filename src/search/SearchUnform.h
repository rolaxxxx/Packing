#ifndef SEARCHUNFORM_H
#define SEARCHUNFORM_H
#include "search/ASearch.h"

class SearchUnform : public ASearch {
public:
  SearchUnform();
  std::vector<INT> getNeighboursID(INT id);
  bool intersect(PointType p, std::vector<INT> neighbours);

  std::vector<INT> getGridNeigbours(INT id);
  void addPoint(PointType p);

  std::vector<INT> &getCellElements(INT id);
  INT calculateID(PointType p);
  INT getGridSize();

protected:
  void initialization();

private:
  // unordered_map mp;
  // std::unordered_map<INT, std::vector<INT>>SUFORMUOTAS_GRIDAS;
  // std::vector<pair<INT, vector> SUFORMUOTAS_GRIDAS
  std::vector<std::vector<INT>> SUFORMUOTAS_GRIDAS;
  std::vector<INT> GetPotentialNeighbours(Point p);
  // std::vector<std::vector<INT>> SUFORMUOTAS_GRIDAS;
  Timer time;
};

#endif // SEARCHUNFORM_H
