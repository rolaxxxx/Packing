#include "AAlgorithm.h"

AAlgorithm::AAlgorithm() {}
void AAlgorithm::init(Data *data, ARandom *random, ASearch *search,
                      json duomenys, BBoundaries *bounds, INT count,
                      Writer writer) {

  this->data = data;
  this->random = random;
  this->search = search;
  this->bounds = bounds;
  this->duomenys = duomenys;
  this->count = count;
  this->rez_switch = duomenys["WRITER"]["TEMP_REZULTS_SWITCH"];
  this->amount_particles = duomenys["WRITER"]["AMOUNT_PARTICLES"];
  this->boundaries = bounds->getBounds();

  this->initialization();
}

REAL AAlgorithm::getPoringumas() const { return poringumas; }

void AAlgorithm::setPoringumas(const REAL &value) { poringumas = value; }
