#include "ASearch.h"

ASearch::ASearch()
{

}
void ASearch::init(Data*data,REAL bminx,REAL bminy,REAL bminz,REAL bmaxx,REAL bmaxy,REAL bmaxz,REAL RMax)
{
    this->data=data;
    this->bminx=bminx;
    this->bminy=bminy;
    this->bminz=bminz;
    this->bmaxx=bmaxx;
    this->bmaxy=bmaxy;
    this->bmaxz=bmaxz;
    this->RMax=RMax;
    this->CELL_SIZE=CELL_SIZE*RMax;
    this->initialization();
}
