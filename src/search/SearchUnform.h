#ifndef SEARCHUNFORM_H
#define SEARCHUNFORM_H
#include "search/ASearch.h"

class SearchUnform:public ASearch
{
public:
    SearchUnform();
    std::vector<INT> getNeighboursID(INT id);
    bool intersectionTest(PointType p);
    PointsArrayType getNeighboursPoints(INT id);
    void addPoint(PointType p);
protected:
    void initialization();
};

#endif // SEARCHUNFORM_H
