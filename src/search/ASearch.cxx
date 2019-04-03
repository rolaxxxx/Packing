#include "ASearch.h"

ASearch::ASearch()
{

}
void ASearch::init(Data*data,Point bmin, Point bmax, REAL RMax)
{
    this->data=data;
    this->SUFORMUOTAS_GRIDAS=SUFORMUOTAS_GRIDAS;
    this->bmin=bmin;
    this->bmax=bmax;
    this->RMax=RMax;
    this->CELL_SIZE=CELL_SIZE*RMax;
    //suskaiciuoju ribas
    this->Nx=ceil((this->bmax.x-this->bmin.x)/this->CELL_SIZE);
    this->Ny=ceil((this->bmax.y-this->bmin.y)/this->CELL_SIZE);
    this->Nz=ceil((this->bmax.z-this->bmin.z)/this->CELL_SIZE);

    this->initialization();
}
