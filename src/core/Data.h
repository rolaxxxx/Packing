#ifndef DATA_H
#define DATA_H
#include "core/Constants.h"
#include "core/Point.h"

class Data
{
public:
    Data();
    void insertNextPoint(PointType p);

    PointType getPoint(INT i);
    PointType getFinalVectorPoint(INT i);

    void insertNextFinalVector(PointType p);

    void insertNextPoint(INT idx, INT particle);

     std::vector<INT> getPoints(INT i);
    void removePoint(INT p);

    INT getNumberOfPoints();
    INT getFinalVectorNumberOfPoints();
    INT getNumberOfPoints_v();


    PointType getPoint_v(INT i);
    void insertNextPoint_v(PointType p);




    std::string getDuomenys() const;
    void setDuomenys(const std::string &value);

    std::string getVtk_duomenys() const;
    void setVtk_duomenys(const std::string &value);

private:
    PointsArrayType data; /// tik daleles kuriuose ieskomi kaimynai
    std::string duomenys;



};

#endif // DATA_H
