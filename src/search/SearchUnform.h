#ifndef SEARCHUNFORM_H
#define SEARCHUNFORM_H
#include "search/ASearch.h"

class SearchUnform:public ASearch
{
public:
    SearchUnform();
    std::vector<INT> getNeighboursID(INT id);
    bool intersect(INT id);
    std::vector<INT> getGridNeigbours(INT id);
    INT getMapSIZE();
    void addPoint(PointType p);
    std::vector<INT> getCellElements(INT id);
    INT calculateID(PointType p);
    INT getGridSize();

protected:
    void initialization();
private:
    std::map<INT, std::vector<INT>>SUFORMUOTAS_GRIDAS;

};

#endif // SEARCHUNFORM_H
