#include "SearchUnform.h"

using namespace std;
SearchUnform::SearchUnform()
{

}
void SearchUnform::initialization()
{

}
INT SearchUnform::calculateID(PointType p){
    PointType temp_coords;
    INT xx=(int)floor((p.x-bmin.x)/CELL_SIZE);
    INT yy=(int)floor((p.y-bmin.y)/CELL_SIZE);
    INT zz=(int)floor((p.z-bmin.z)/CELL_SIZE);
    return xx+yy*Nx+zz*Nx*Ny;
}

void SearchUnform::addPoint(PointType p)
{
    int id=data->getNumberOfPoints();
    SUFORMUOTAS_GRIDAS[calculateID(p)].push_back(id);
    p.ID=id;
    data->insertNextPoint(p);
}


std::vector<INT> SearchUnform::getCellElements(INT id){
    return SUFORMUOTAS_GRIDAS[id];
}


std::vector<INT> SearchUnform::GetPotentialNeighbours(Point temp)
{
    std::vector<INT> ids;
    std::vector<INT> potencialus_kaimynai;
    INT xx=(int)floor((temp.x-bmin.x)/CELL_SIZE);
    INT yy=(int)floor((temp.y-bmin.y)/CELL_SIZE);
    INT zz=(int)floor((temp.z-bmin.z)/CELL_SIZE);
    for(INT x=xx-1;x<=xx+1;x++){ // pakeliau atstuma nes neradau kaimynu
        for(INT y=yy-1;y<=yy+1;y++){
            for(INT z=zz-1;z<=zz+1;z++){
                INT  TEMP_ID=x+y*Nx+z*Nx*Ny;
                potencialus_kaimynai=getCellElements(TEMP_ID);
                for (INT i = 0; i < potencialus_kaimynai.size(); i++) {
                    if(temp.ID!=potencialus_kaimynai[i])
                        ids.push_back(potencialus_kaimynai[i]);
                }
            }
        }
    }

    cout << " ____ " << endl;
    return ids;
}

std::vector<INT> SearchUnform::getGridNeigbours(INT id)
{
    Point p=data->getPoint(id);

    std::vector<INT> potencialus_kaimynai=GetPotentialNeighbours(p);
    return potencialus_kaimynai;
}

std::vector<INT> SearchUnform::getNeighboursID(INT id)
{

    Point p=data->getPoint(id);
    std::vector<INT> potencialus_kaimynai=GetPotentialNeighbours(p);

    std::cout<<"Potencialus kaimynu skaicius "<<potencialus_kaimynai.size()<<"\n";
    std::vector<INT> ids;
    for(int i=0;i<potencialus_kaimynai.size();i++)
    {
        std::cout<<"target id "<<p.ID<<"  potencialus kaimynas "<<potencialus_kaimynai[i]<<"\n";
        Point target=data->getPoint(potencialus_kaimynai[i]);
        double L=vector_len(p-target);
        double L2=L-p.R-target.R;
        if(L2<EPSILON)
        {

            ids.push_back(potencialus_kaimynai[i]);
            target.PrintStructure();
        }else {
            std::cout<<"ilgis "<<L<<" radius suma "<<p.R+target.R<<" skirtumas "<<L-(p.R+target.R)<<"\n";
        }

    }
    std::cout<<"real neigb "<<ids.size()<<"\n";
    return ids;
}
bool SearchUnform::intersect(PointType p)
{

    std::vector<INT> potencialus_kaimynai=GetPotentialNeighbours(p);
    bool persidengia=false;
    for(int i=0;i<potencialus_kaimynai.size();i++)
    {
        Point target=data->getPoint(potencialus_kaimynai[i]);
        double L2=vector_len(p-target)-p.R-target.R;
        if(L2<-EPSILON) persidengia=true;
    }
    return persidengia;


}
