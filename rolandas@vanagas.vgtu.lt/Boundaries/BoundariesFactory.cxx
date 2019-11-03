#include "BoundariesFactory.h"
#include "Boundaries/CubeShape.h"
#include "Boundaries/cylindershape.h"
#include "Boundaries/Mesh.h"
BoundariesShape::BoundariesShape()
{

}

BBoundaries* BoundariesShape::create(std::string type)
{
    if(type=="Cube")
    {
        return new CubeShape();
    }
    else if(type=="Cylinder")
    {
        return new CylinderShape();
    }
    else if(type=="Mesh")
    {
        return new Mesh();
    }

    std::cerr<<"Klaida tokio modulio nera!!!\n";
    exit(1000);
}
