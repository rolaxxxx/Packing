#include "SearchUnform.h"

SearchUnform::SearchUnform()
{

}
std::vector<INT> SearchUnform::getNeighboursID(INT id)
{
    std::vector<INT> ids;
    Point temp, tempPID;
    Point coords;
    INT pid;
    REAL L;
    REAL temp_cur_rad, temp_pid_rad;
    REAL TEMP_LEN;
    INT TEMP_ID;
    std::vector<INT> potencialus_kaimynai;
    std::vector<INT> rasti_kaimynu_indexai;
    //cout << nx << " " << ny << " " << nz << endl;

    INT kiekis=0;

    temp=data->getPoint(id);
    //cout << particle.F[search_particle_index] << endl;
    //cout <<MAP_BOUNDS_MIN << " " << CELLSIZE << endl;
    coords.x=floor((temp.x-bmin.x)/CELL_SIZE);
    coords.y=floor((temp.y-bmin.y)/CELL_SIZE);
    coords.z=floor((temp.z-bmin.z)/CELL_SIZE);
    temp_cur_rad=1;// kol vienodi spinduliai bus vienas o po to reikia keisti

   // cout << CE
    //cout << temp << endl;
    for(INT x=coords.x-1;x<=coords.x+1;x++){ // pakeliau atstuma nes neradau kaimynu
           for(INT y=coords.y-1;y<=coords.y+1;y++){
               for(INT z=coords.z-1;z<=coords.z+1;z++){
                  // if(x<map_boundai.Nx&&y<map_boundai.Ny&&z<map_boundai.Nz&&x>=0&&y>=0&&z>=0){
                        TEMP_ID=x+y*Nx+z*Nx*Ny;
                           //cout << TEMP_ID << endl;
                                    potencialus_kaimynai=data->getPoints(TEMP_ID);
                                           //cout << potencialus_kaimynai.size() << endl;
                                    for(auto it=potencialus_kaimynai.begin();it!=potencialus_kaimynai.end();it++){
                                            pid=*it;
                                            //cout << pid << " " <<particle.F[pid] << endl;
                                       if(pid!=id)
                                               {
                                               tempPID=data->getPoint(pid);
                                               temp_pid_rad=tempPID.z;
                                               tempPID.z=0;

                                       TEMP_LEN=vector_len(temp-tempPID);

                                       L=TEMP_LEN-(temp_cur_rad+temp_pid_rad);
                                       //cout <<particle.F.size() << " "<<search_particle_index<< "nuo ieskomo kaimyno nutole " <<  L << " " << 2*temp_cur_rad << endl;
                                       if(L<=2*temp_cur_rad){
                                          // cout << rasti_kaimynu_indexai[kiekis] << endl;
                                           ids.push_back(pid);
                                           //cout << rasti_kaimynu_indexai.size() << endl;
                                           kiekis++;
                                           //cout << pid << endl;
                                       }

                                        }
                         }
                   }
               }
   }
    return ids;
}
bool SearchUnform::intersectionTest(PointType p)
{
    PointType temp, tempPID;
    Point coords;
    INT pid;
    REAL L;
    REAL temp_cur_rad, temp_pid_rad;
    REAL TEMP_LEN;
    INT TEMP_ID;
    std::vector<INT> potencialus_kaimynai;
    std::vector<INT> rasti_kaimynu_indexai;
    REAL LEN1, LEN2;

    INT kiekis=0;

    temp=p;
    coords.x=floor((temp.x-bmin.x)/CELL_SIZE);
    coords.y=floor((temp.y-bmin.y)/CELL_SIZE);
    coords.z=floor((temp.z-bmin.z)/CELL_SIZE);
    coords.R=0;
    LEN1=vector_len(p);
    bool ans=false;
    for(INT i=0;i<data->getNumberOfPoints();i++) // susikirtimo tikrinimas
    {
        tempPID=data->getPoint(i);
        tempPID.R=0;
        LEN2=vector_len(tempPID);
        if(fabs(LEN1-LEN2)<0.01&&tempPID!=p)
        {ans=true;
        }
    }
    /// TAVO kodas
    return false;
}
PointsArrayType SearchUnform::getNeighboursPoints(INT id)
{
    PointsArrayType array;
    /// TAVO kodas
    return array;
}

void SearchUnform::initialization()
{
    /// TAVO kodas
}

void SearchUnform::addPoint(PointType p)
{
    /// TAVO kodas
}
