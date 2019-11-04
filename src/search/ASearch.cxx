#include "ASearch.h"

ASearch::ASearch() {}
void ASearch::init(Data *data, json duomenys) {
  this->data = data;

  this->RMax = duomenys["DISTRIBUTION"]["RMAX"];
  this->RMin = duomenys["DISTRIBUTION"]["RMIN"];

  this->CELL_SIZE = 2 * RMax;

  this->Nx = ceil((this->bmax.x - this->bmin.x) / this->CELL_SIZE) + 1;
  this->Ny = ceil((this->bmax.y - this->bmin.y) / this->CELL_SIZE) + 1;
  this->Nz = ceil((this->bmax.z - this->bmin.z) / this->CELL_SIZE) + 1;

  this->initialization();
}

Point ASearch::getBmax() const { return bmax; }

Point ASearch::getBmin() const { return bmin; }

INT ASearch::getNx() const { return Nx; }

INT ASearch::getNy() const { return Ny; }

INT ASearch::getNz() const { return Nz; }

void ASearch::SetBounds(double *boundai) {

  this->bmin.x = *(boundai + 0); //
  this->bmax.x = *(boundai + 1); //

  this->bmin.y = *(boundai + 2); //
  this->bmax.y = *(boundai + 3); //

  this->bmin.z = *(boundai + 4); //
  this->bmax.z = *(boundai + 5); //
}
