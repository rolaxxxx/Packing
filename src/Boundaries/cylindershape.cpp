#include "cylindershape.h"

CylinderShape::CylinderShape()
{

}
bool CylinderShape::check(Point newSphere){
    if( newSphere.x<max.x
                 &&newSphere.y<max.y
                 &&newSphere.z<max.z
                 &&newSphere.x>min.x
                 &&newSphere.y>min.y
                 &&newSphere.z>min.z
                   )
        return true;
    else return false;

}
void CylinderShape::initialization(json duomenys)
{
    radius=duomenys["BOUNDARIES"]["RADIUS"];
    height=duomenys["BOUNDARIES"]["HEIGHT"];
    center.x=duomenys["BOUNDARIES"]["CENTER"][0];
    center.y=duomenys["BOUNDARIES"]["CENTER"][1];
    center.z=duomenys["BOUNDARIES"]["CENTER"][2];
}
