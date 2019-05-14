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
    mp[calculateID(p)].push_back(id);
    p.ID=id;
    data->insertNextPoint(p);
    //p.PrintStructure();
}


std::vector<INT> SearchUnform::getCellElements(INT id){

    return mp[id];
     //cout << time.CumulativeTime("sec") << " laikas sekundemis paimti elementams is mapo " << endl;
}


std::vector<INT> SearchUnform::GetPotentialNeighbours(Point temp)
{
    std::vector<INT> ids;
    std::vector<INT> potencialus_kaimynai;
    INT xx=(int)floor((temp.x-bmin.x)/CELL_SIZE);
    INT yy=(int)floor((temp.y-bmin.y)/CELL_SIZE);
    INT zz=(int)floor((temp.z-bmin.z)/CELL_SIZE);

   // cout << bmin.x<< " " << bmin.y << " " << bmin.z << " " << CELL_SIZE << endl;

    for(INT x=xx-1;x<=xx+1;x++){
        for(INT y=yy-1;y<=yy+1;y++){
            for(INT z=zz-1;z<=zz+1;z++){
   // cout << x << " " << y << " " << z << endl;
                INT  TEMP_ID=x+y*Nx+z*Nx*Ny;
                 time.StartTimer();
                potencialus_kaimynai=getCellElements(TEMP_ID);
                time.StopTimer();

                //

                for (INT i = 0; i < potencialus_kaimynai.size(); i++) {

                    if(temp.ID!=potencialus_kaimynai[i])
                       ids.push_back(potencialus_kaimynai[i]);
            }
        }
    }
}
 cout << time.CumulativeTime("sec") << " " << " laikas sekundemis"<< endl;
    //cout << " ____ " << endl;
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

   // std::cout<<"Potencialus kaimynu skaicius "<<potencialus_kaimynai.size()<<"\n";
    std::vector<INT> ids;
    //cout << potencialus_kaimynai.size() << endl;
    for(int i=0;i<potencialus_kaimynai.size();i++)
    {
        //std::cout<<"target id "<<p.ID<<"  potencialus kaimynas "<<potencialus_kaimynai[i]<<"\n";
        Point target=data->getPoint(potencialus_kaimynai[i]);
        double L=vector_len(p-target);
        double L2=L-p.R-target.R;

        if(L2<= 4*RMax)//  EPSILON 2*RMax // paimti daugiau kad po to nereiketu vel kartoti funkcijos
        {

            ids.push_back(potencialus_kaimynai[i]);
           // target.PrintStructure();
          // cout << potencialus_kaimynai[i] << endl;
        }
    }
   // std::cout<<"real neigb "<<ids.size()<<"\n";
    //cout << "_______" << endl;
    return ids;
}
bool SearchUnform::intersect(PointType p, vector<INT>neighbours)
{


   // time.StartTimer();
    // cout << neighbours.size() << " kaimynu kiekis " << endl;
   // std::vector<INT> potencialus_kaimynai=;
    std::vector<INT> potencialus_kaimynai=GetPotentialNeighbours(p);
    //time.StopTimer();

    //cout << "iteracijos laikas " << time.ElapsedTime("sec") << endl;
    //cout << "visas laikas  " << time.CumulativeTime("sec") << " ir kaimynai " << potencialus_kaimynai.size() <<endl;

   // cout << potencialus_kaimynai.size() << endl;

    for(int i=0;i<potencialus_kaimynai.size();i++)
    {
        Point target=data->getPoint(potencialus_kaimynai[i]);
        double L2=vector_len(p-target)-p.R-target.R;
        if(L2<-EPSILON) return true;
    }
    return false;


}
