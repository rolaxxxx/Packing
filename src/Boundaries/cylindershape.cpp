#include "cylindershape.h"

CylinderShape::CylinderShape()
{

}
bool CylinderShape::check(Point newSphere){
   // newSphere.PrintStructure();
   // cout << newSphere.z << " " << center.y+height << " " <<  center.y << endl;
cout << newSphere.y << " " << center.y+radius << " " << center.y-radius << endl;
/*
            CILINDO RIBU PAIESKOS PRATESTI CIA


*/
    if( newSphere.x<center.x+radius&&newSphere.x>center.x-radius&&
             newSphere.y<center.y+radius&&newSphere.y>center.y-radius&&
            newSphere.z<center.z+height && newSphere.z>center.z
            ){

         //newSphere.PrintStructure();

        return true;
    }
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
