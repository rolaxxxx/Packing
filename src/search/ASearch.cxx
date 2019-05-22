#include "ASearch.h"

ASearch::ASearch()
{

}
void ASearch::init(Data*data, json duomenys)
{
    this->data=data;
    //cout << (duomenys["SEARCH"]["BMIN"][0]) << endl;
    this->bmin.x=(duomenys["SEARCH"]["BMIN"][0]);
    this->bmin.y=(duomenys["SEARCH"]["BMIN"][1]);
    this->bmin.z=(duomenys["SEARCH"]["BMIN"][2]);

    this->bmax.x=(duomenys["SEARCH"]["BMAX"][0]);
    this->bmax.y=(duomenys["SEARCH"]["BMAX"][1]);
    this->bmax.z=(duomenys["SEARCH"]["BMAX"][2]);

    this->RMax=duomenys["DISTRIBUTION"]["RMAX"];
    //cout << this->RMax << " " << bmax.x << " " << bmax.y << " " << bmax.z << endl;
    this->CELL_SIZE=2*RMax;
    this->Nx=ceil((this->bmax.x-this->bmin.x)/this->CELL_SIZE)+1;
    this->Ny=ceil((this->bmax.y-this->bmin.y)/this->CELL_SIZE)+1;
    this->Nz=ceil((this->bmax.z-this->bmin.z)/this->CELL_SIZE)+1;

    this->initialization();
}

Point ASearch::getBmax() const
{
    return bmax;
}

Point ASearch::getBmin() const
{
    return bmin;
}

INT ASearch::getNx() const
{
    return Nx;
}

INT ASearch::getNy() const
{
    return Ny;
}

INT ASearch::getNz() const
{
    return Nz;
}
