#include "SearchUnform.h"

using namespace std;
SearchUnform::SearchUnform()
{

}
void SearchUnform::initialization()
{
    SUFORMUOTAS_GRIDAS.resize(Nx*Ny*Nz);
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
    //cout << SUFORMUOTAS_GRIDAS.max_size() << endl;
    int id=data->getNumberOfPoints();
    INT calc_id=calculateID(p);
   // cout << "suskaiciuotas taskas  ir tasko id " << calc_id <<  endl;
    //p.PrintStructure();
if(calc_id<0){
    p.PrintStructure();
}
        //cout << calc_id << " " << " neigiama reiksme " << endl;
    //cout << SUFORMUOTAS_GRIDAS.size() << " " << calc_id <<  endl;

    std::vector<INT>temp=SUFORMUOTAS_GRIDAS[calc_id];
   // cout << calculateID(p) << endl;

    temp.push_back(id);

    SUFORMUOTAS_GRIDAS[calc_id]=temp;
    //cout << calc_id << " " << SUFORMUOTAS_GRIDAS.size() << endl;
    p.ID=id;
    data->insertNextPoint(p);
    //p.PrintStructure();

}


std::vector<INT>& SearchUnform::getCellElements(INT id){

    return SUFORMUOTAS_GRIDAS[id];
}
std::vector<INT> SearchUnform::GetPotentialNeighbours(Point temp)
{
    std::vector<INT> ids;

    INT xx=(int)floor((temp.x-bmin.x)/CELL_SIZE);
    INT yy=(int)floor((temp.y-bmin.y)/CELL_SIZE);
    INT zz=(int)floor((temp.z-bmin.z)/CELL_SIZE);
    //cout << xx << " " << yy << " " << zz << endl;

    //cout << bmin.x<< " " << bmin.y << " " << bmin.z << " " << CELL_SIZE << endl;
   // cout << ((temp.x-bmin.x)/CELL_SIZE) << " " << (int)floor((temp.x-bmin.x)/CELL_SIZE) << endl;
 // time.StartTimer();
    for(INT x=xx-1;x<=xx+1;x++){
        for(INT y=yy-1;y<=yy+1;y++){
            for(INT z=zz-1;z<=zz+1;z++){
    //cout << x << " " << y << " " << z << endl;

                if(x<Nx&&y<Ny&&z<Nz&&x>=0&&y>=0&&z>=0)
                {
                INT  TEMP_ID=x+y*Nx+z*Nx*Ny;
                //cout << Nx << " " << Ny << " " << Nz << endl;
                //cout << x << " " << y << " " << z << endl;
               // cout << TEMP_ID << endl;
               // cout << Nx << " " << Ny << " " << Nz << endl;
                std::vector<INT>& potencialus_kaimynai=getCellElements(TEMP_ID);


                //cout <<potencialus_kaimynai.size()  << " " << TEMP_ID <<  endl;

                //

                for (INT i = 0; i < potencialus_kaimynai.size(); i++) {

                    if(temp.ID!=potencialus_kaimynai[i])
                       ids.push_back(potencialus_kaimynai[i]);
                      }

              }

        }
    }
}


 //cout << time.CumulativeTime("sec") << " " << " laikas sekundemis"<< endl;
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

    //cout << "iteracijos laikas " << time.ElapsedTime("sec") << endl;
    //cout << "visas laikas  " << time.CumulativeTime("sec") <<endl;

   // cout << potencialus_kaimynai.size() << endl;

    for(int i=0;i<potencialus_kaimynai.size();i++)
    {
        Point target=data->getPoint(potencialus_kaimynai[i]);
        double L2=vector_len(p-target)-p.R-target.R;
        if(L2<-EPSILON) return true;
    }
     //time.StopTimer();
   // rez+=time.ElapsedTime("sec");
   // cout << rez << " praeitas laikas " << endl;

    return false;
}

