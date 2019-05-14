#include "BoundariesShape.h"
#include "Boundaries/CubeShape.h"

BoundariesShape::BoundariesShape()
{

}

BBoundaries* BoundariesShape::create(BoundsTypes type)
{
    if(type==BoundsTypes::Cube)
    {
        return new CubeShape();
    }
    std::cerr<<"Klaida tokio modulio nera!!!\n";
    exit(1000);
}
