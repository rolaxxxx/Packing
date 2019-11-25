#include "AAlgorithm.h"

AAlgorithm::AAlgorithm() {}
void AAlgorithm::init(Data *data, ARandom *random, ASearch *search,
                      json duomenys, BBoundaries *bounds, INT count,
                      Writer writer, std::string temp_rezults_switchas, INT particle_amount, std::string rand_generator_switchas) {
	
  this->data = data;
  this->random = random;
  this->search = search;
  this->bounds = bounds;
  this->duomenys = duomenys;
  this->count = count;
  
  
  this->rez_switch = temp_rezults_switchas;
  this->rand_gen_every_iteration= rand_generator_switchas;
  this->amount_particles = particle_amount;
  
  this->boundaries = bounds->getBounds();

  this->initialization();
}

REAL AAlgorithm::getPoringumas() const { return poringumas; }

void AAlgorithm::setPoringumas(const REAL &value) { poringumas = value; }
