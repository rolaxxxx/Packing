#include "ASearch.h"

ASearch::ASearch()
{

}
void ASearch::init(Data*data, json duomenys)
{
    this->data=data;
    //cout << (duomenys["SEARCH"]["BMIN"][0]) << endl;


    this->RMax=duomenys["DISTRIBUTION"]["RMAX"];
    //cout << this->RMax << " " << bmax.x << " " << bmax.y << " " << bmax.z << endl;
    this->CELL_SIZE=2*RMax;
    this->Nx=ceil((this->bmax.x-this->bmin.x)/this->CELL_SIZE); // + 1 buvo prie visu uzdetas jeigu neveiks reikia pakeisti
    this->Ny=ceil((this->bmax.y-this->bmin.y)/this->CELL_SIZE);
    this->Nz=ceil((this->bmax.z-this->bmin.z)/this->CELL_SIZE);
    //cout << Nx << " " << Ny << " " << Nz << " rybu reiksmes " << endl;

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


void ASearch::SetBounds(double *boundai)
{


     this->bmin.x=*(boundai+0);//
     this->bmax.x=*(boundai+1);//

     this->bmin.y=*(boundai+2);//
     this->bmax.y=*(boundai+3);//

     this->bmin.z=*(boundai+4);//
     this->bmax.z=*(boundai+5);//



}
