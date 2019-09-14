#include "cylindershape.h"

CylinderShape::CylinderShape()
{

}
bool CylinderShape::check(Point newSphere){
    //cout << "min ir max tikrinimo vietoje " << endl;
    //fabs(vector_len(p1)-vector_len(p2));


        if(dot_prod(( newSphere-min),(max-min))>=0&&dot_prod((newSphere-max),(max-min))<=0
                &&  (((vector_len(cross_prod((newSphere-min),(max-min))))/(vector_len(max-min)))<=radius))
            return true;
        else return false;


}
void CylinderShape::initialization(json duomenys)
{

    bounds[0]=duomenys["SEARCH"]["BMIN"][0];
        bounds[1]=duomenys["SEARCH"]["BMAX"][0];
        bounds[2]=duomenys["SEARCH"]["BMIN"][1];

        bounds[3]=duomenys["SEARCH"]["BMAX"][1];
        bounds[4]=duomenys["SEARCH"]["BMIN"][2];
        bounds[5]=duomenys["SEARCH"]["BMAX"][2];

        min.x=duomenys["BOUNDARIES"]["BMIN"][0];
         min.y=duomenys["BOUNDARIES"]["BMIN"][1];
          min.z=duomenys["BOUNDARIES"]["BMIN"][2];

          max.x=duomenys["BOUNDARIES"]["BMAX"][0];
           max.y=duomenys["BOUNDARIES"]["BMAX"][1];
            max.z=duomenys["BOUNDARIES"]["BMAX"][2];
            radius=duomenys["BOUNDARIES"]["RADIUSSQ"];
            height=duomenys["BOUNDARIES"]["LENGTHSQ"];


}
