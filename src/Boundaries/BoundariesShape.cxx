#include "BoundariesShape.h"
#include "Boundaries/CubeShape.h"
#include "Boundaries/cylindershape.h"
BoundariesShape::BoundariesShape()
{

}

BBoundaries* BoundariesShape::create(BoundsTypes type)
{
    if(type==BoundsTypes::Cube)
    {
        return new CubeShape();
    }
    else if(type==BoundsTypes::Cylinder)
    {
        return new CylinderShape();
    }
    std::cerr<<"Klaida tokio modulio nera!!!\n";
    exit(1000);
}
