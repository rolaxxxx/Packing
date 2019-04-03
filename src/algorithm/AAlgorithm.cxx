#include "AAlgorithm.h"

AAlgorithm::AAlgorithm()
{

}
void AAlgorithm::init(Data *data, ARandom *random, ASearch *search)
{
    this->data=data;
    this->random=random;
    this->search=search;
    this->initialization();

}
