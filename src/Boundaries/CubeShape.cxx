#include "CubeShape.h"


CubeShape::CubeShape(){

}
bool CubeShape::check(Point newSphere){
     //newSphere.PrintStructure();
   //  max.PrintStructure();
    /*



*/
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
void CubeShape::initialization(json duomenys)
{
    min.x=duomenys["BOUNDARIES"]["BMIN"][0];
    min.y=duomenys["BOUNDARIES"]["BMIN"][1];
    min.z=duomenys["BOUNDARIES"]["BMIN"][2];

    max.x=duomenys["BOUNDARIES"]["BMAX"][0];
    max.y=duomenys["BOUNDARIES"]["BMAX"][1];
    max.z=duomenys["BOUNDARIES"]["BMAX"][2];
}
