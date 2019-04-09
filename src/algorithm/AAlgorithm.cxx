#include "AAlgorithm.h"

AAlgorithm::AAlgorithm()
{

}
void AAlgorithm::init(Data *data, ARandom *random, ASearch *search, INT count)
{
    this->data=data;
    this->random=random;
    this->search=search;
    this->initialization();
    this->count=count;

}
