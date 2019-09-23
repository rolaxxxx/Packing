#include "cylindershape.h"

CylinderShape::CylinderShape()
{

}
bool CylinderShape::check(Point newSphere){
    //cout << "min ir max tikrinimo vietoje " << endl;
    //fabs(vector_len(p1)-vector_len(p2));
		Point temp1;
		Point temp2;
		temp1=newSphere;
		temp2=newSphere;
        temp1=temp1-newSphere.R;
        temp2=temp2+newSphere.R;
		
        if(dot_prod(( temp1-min),(max-min))>=0&&dot_prod((temp1-max),(max-min))<=0
                &&  (((vector_len(cross_prod((temp1-min),(max-min))))/(vector_len(max-min)))<=radius))
					{
						 if(dot_prod(( temp2-min),(max-min))>=0&&dot_prod((temp2-max),(max-min))<=0
								&&  (((vector_len(cross_prod((temp2-min),(max-min))))/(vector_len(max-min)))<=radius))
									return true;
					}
        else return false;


}
void CylinderShape::initialization(json duomenys)
{

        bounds[0]=duomenys["BOUNDARIES"]["BOUNDS_MIN"][0];
        bounds[1]=duomenys["BOUNDARIES"]["BOUNDS_MAX"][0];

        bounds[2]=duomenys["BOUNDARIES"]["BOUNDS_MIN"][1];
        bounds[3]=duomenys["BOUNDARIES"]["BOUNDS_MAX"][1];

        bounds[4]=duomenys["BOUNDARIES"]["BOUNDS_MIN"][2];
        bounds[5]=duomenys["BOUNDARIES"]["BOUNDS_MAX"][2];

        min.x=duomenys["BOUNDARIES"]["CYLINDER_MIDDLE_MIN"][0];
         min.y=duomenys["BOUNDARIES"]["CYLINDER_MIDDLE_MIN"][1];
          min.z=duomenys["BOUNDARIES"]["CYLINDER_MIDDLE_MIN"][2];

          max.x=duomenys["BOUNDARIES"]["CYLINDER_MIDDLE_MAX"][0];
           max.y=duomenys["BOUNDARIES"]["CYLINDER_MIDDLE_MAX"][1];
            max.z=duomenys["BOUNDARIES"]["CYLINDER_MIDDLE_MAX"][2];
            radius=duomenys["BOUNDARIES"]["RADIUSSQ"];
            height=duomenys["BOUNDARIES"]["LENGTHSQ"];


}
