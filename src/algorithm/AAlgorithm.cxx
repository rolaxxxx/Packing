#include "AAlgorithm.h"

AAlgorithm::AAlgorithm()
{

}
void AAlgorithm::init(Data *data, ARandom *random, ASearch *search, BBoundaries *bounds, INT count)
{
    this->data=data;
    this->random=random;
    this->search=search;
    this->bounds=bounds;
    this->count=count;
    this->initialization();


}
