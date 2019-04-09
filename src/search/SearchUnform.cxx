#include "SearchUnform.h"

using namespace std;
SearchUnform::SearchUnform()
{

}
void SearchUnform::initialization()
{
    addPoint(data->getPoint(0));
    addPoint(data->getPoint(1));
    addPoint(data->getPoint(2));
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
   SUFORMUOTAS_GRIDAS[calculateID(p)].push_back(data->getNumberOfPoints());
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
                  // if(x<map_boundai.Nx&&y<map_boundai.Ny&&z<map_boundai.Nz&&x>=0&&y>=0&&z>=0){
                        TEMP_ID=x+y*Nx+z*Nx*Ny;
                           //cout << TEMP_ID << endl;
                                    potencialus_kaimynai=getCellElements(TEMP_ID);
                                    ids.insert(ids.end(), potencialus_kaimynai.begin(), potencialus_kaimynai.end());
               }
           }
    }
    return ids;
}

std::vector<INT> SearchUnform::getNeighboursID(INT id)
{
            std::vector<INT>grid_neighbours=getGridNeigbours(id);
            PointType temp, tempPID;
            PointType coords;
            std::vector<INT>rasti_kaimynu_indexai;
            INT pid;
            REAL L;
            REAL temp_cur_rad, temp_pid_rad;
            REAL TEMP_LEN;
            INT TEMP_ID;

            for(INT i=0;i<grid_neighbours.size();i++){
               pid=i;
                   if(pid!=id)
               {
               tempPID=data->getPoint(pid);
               temp_pid_rad=tempPID.R;
               tempPID.R=0;
               TEMP_LEN=fabs(vector_len(temp)-vector_len(tempPID));
               L=TEMP_LEN-(temp_cur_rad+temp_pid_rad);

               if(L<=2*temp_cur_rad){
                   rasti_kaimynu_indexai.push_back(pid);
               }
            }
        }
            return rasti_kaimynu_indexai;
}
bool SearchUnform::intersect(INT p)
{
    std::vector<INT> ids=getGridNeigbours(p);
    PointType vec1;
    REAL veclen1, veclen2;
    PointType vec2;

    vec1=data->getPoint(p);
    for(int i=0;i<ids.size();i++)
    {
        vec2=data->getPoint(ids[i]);

        veclen1=vector_len(vec1);
        veclen2=vector_len(vec2);

        if(fabs(veclen1-veclen2)<0.0001)
            return true;
    }
    return false;

}
