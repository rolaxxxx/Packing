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
  std::vector<std::vector<INT>> SUFORMUOTAS_GRIDAS;
  std::vector<INT> GetPotentialNeighbours(Point p);

  Timer time;
};

#endif // SEARCHUNFORM_H
