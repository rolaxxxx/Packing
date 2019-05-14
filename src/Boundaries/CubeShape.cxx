#include "CubeShape.h"


CubeShape::CubeShape(){

}
bool CubeShape::check(Point newSphere, Point min, Point max){
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
void CubeShape::initialization()
{

}
