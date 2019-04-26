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
    INT rez;
    // cout << p.x << " " << p.y <<" "<< p.z << endl;
    temp_coords.x=floor((p.x-bmin.x)/CELL_SIZE);
    temp_coords.y=floor((p.y-bmin.y)/CELL_SIZE);
    temp_coords.z=floor((p.z-bmin.z)/CELL_SIZE);
    //cout << floor((p.z - bmin.z)  /  CELL_SIZE)<< endl;
    rez=temp_coords.x+temp_coords.y*Nx+temp_coords.z*Nx*Ny;

    return rez;
}

void SearchUnform::addPoint(PointType p)
{
    //std::cout << p.x << " " << p.y << " " << p.z << " " << p.R << std::endl;

    SUFORMUOTAS_GRIDAS[calculateID(p)].push_back(data->getNumberOfPoints());
    // cout << p.x << " " << p.y << " " << p.z << " " << calculateID(p) << " " <<data->getNumberOfPoints() << endl;
    data->insertNextPoint(p);


}
INT SearchUnform::getMapSIZE() {
    return SUFORMUOTAS_GRIDAS.size();
}
std::vector<INT> SearchUnform::getCellElements(INT id){
    return SUFORMUOTAS_GRIDAS[id];
}

std::vector<INT> SearchUnform::getGridNeigbours(INT id)
{
    std::vector<INT> ids;
    Point temp;
    Point coords;
    INT TEMP_ID;
    std::vector<INT> potencialus_kaimynai;
    temp=data->getPoint(id);
    coords.x=floor((temp.x-bmin.x)/CELL_SIZE);
    coords.y=floor((temp.y-bmin.y)/CELL_SIZE);
    coords.z=floor((temp.z-bmin.z)/CELL_SIZE);
    for(INT x=coords.x-1;x<=coords.x+1;x++){ // pakeliau atstuma nes neradau kaimynu
        for(INT y=coords.y-1;y<=coords.y+1;y++){
            for(INT z=coords.z-1;z<=coords.z+1;z++){
                TEMP_ID=x+y*Nx+z*Nx*Ny;
                potencialus_kaimynai=getCellElements(TEMP_ID);
                //cout << potencialus_kaimynai.size() << endl;
                for (INT i = 0; i < potencialus_kaimynai.size(); i++) {
                    //cout << potencialus_kaimynai[i] << " " << id << endl;
                    if(potencialus_kaimynai[i]!=id){
                        ids.push_back(potencialus_kaimynai[i]);
                        //cout << "potencialus kaimynas " << potencialus_kaimynai[i] << endl;
                    }
                }
            }
        }
    }
    // cout << " ____ " << endl;
    return ids;
}

std::vector<INT> SearchUnform::getNeighboursID(INT id)
{
    std::vector<INT>grid_neighbours=getGridNeigbours(id);
    //cout << grid_neighbours.size() << " " << data->getNumberOfPoints() <<  endl;
    //cout<<"dydis "<<grid_neighbours.size()<<"\n";
    std::vector<INT>rasti_kaimynu_indexai;
    PointType  main_point=data->getPoint(id);
    for (INT i = 0; i < grid_neighbours.size(); i++) {
        INT pid = grid_neighbours[i];
        if (pid != id)
        {
            PointType potentialPoint = data->getPoint(pid);// kadangi ids yra nuo size 1< tasko gavimas is data vektoriaus
            REAL L = (vector_len(main_point-potentialPoint) - (main_point.R + potentialPoint.R));
           // std::cout<<"m "<<main_point.x<<" "<<main_point.R<<"\n";
           // std::cout<<"p "<<potentialPoint.x<<" "<<potentialPoint.R<<"\n";
           // std::cout<<"L "<<L <<"\n";


            if (L < 1E-4 && L > -1E-4) //&&L < 1E-5 && L > -1E-5
            {// cout << L << " " << 1E-4 << " " << L << " " << -1E-4 << endl;
                rasti_kaimynu_indexai.push_back(pid);
                  //cout << id << " " <<pid << " " << data->getNumberOfPoints() <<  endl;
                //cout << pid <<" "<<data->getPoint(pid).x <<" " << data->getPoint(pid).y <<" " << data->getPoint(pid).z << " "  << "        "<< id <<" "<<data->getPoint(id).x <<" " << data->getPoint(id).y <<" " << data->getPoint(id).z << " "  << endl;
            }
        }
    }

  //  cout << "_____" << endl;
//cout <<rasti_kaimynu_indexai.size()  << endl;
    return rasti_kaimynu_indexai;
}
bool SearchUnform::intersect(PointType p, INT rand)
{
    std::vector<INT> ids=getNeighboursID(rand);
    //cout << data->getNumberOfPoints() << endl;
    //cout << ids.size() << endl;
    PointType vec1;
    REAL veclen1, veclen2;
    PointType vec2;

   /* vec1.x=0.499959;
    vec1.y=0.299996;
    vec1.z=0.200017;
    vec1.R=1;

    vec2.x=0.5;
    vec2.y=0.3;
    vec2.z=0.2;
    vec2.R;
     cout << fabs(vector_len(vec1-vec2)-vec1.R-vec2.R)<<endl;
     */
    vec1=p;


    for(int i=0;i<ids.size();i++)
    {

        vec2=data->getPoint(ids[i]);

        //cout <<ids[i] << " " <<  vec2.x << " " << vec2.y << " " << vec2.z << endl;
        veclen1=vector_len(vec1);
        veclen2=vector_len(vec2);
//cout << vec1.x << " " << vec1.y << " " << vec1.z << " vektorius 2 " << vec2.x << " " << vec2.y << " "<< vec2.z << endl;
        //cout <<  " vektorius 2 " << vec2.x << " " << vec2.y << " "<< vec2.z << endl;

        if(fabs(vector_len(vec1-vec2)-vec1.R-vec2.R)<1e-8){
//cout << "_____" << endl;
            return true;
        }
    }
//cout << "______" << endl;
    return false;


}
