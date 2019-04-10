#include "Math.h"
using namespace std;
Math::Math()
{

}

PointsArrayType Math::getSpheresTouchingThreeOtherSpheres(PointType p1,PointType p2,PointType p3,REAL r)
{
    PointsArrayType data;

    INT spind;

    REAL ds1, ds2, ds3;
    Point S1, S2, S3;
    Point rez_sphere_coords_positive, rez_sphere_coords_negative;
    REAL saved_R;
    spind=r;
    //rez_sphere_coords[3]=particle.Distribution[spind];
    rez_sphere_coords_positive.R=1;
    rez_sphere_coords_negative.R=1;
    saved_R=rez_sphere_coords_positive.R;

    S1=p1;
    S2=p2;
    S3=p3;
//cout << S1.x << " " << S1.y << " " << S1.z << endl;
    ds1=S1.R+rez_sphere_coords_positive.R;
    ds2=S2.R+rez_sphere_coords_positive.R;
    ds3=S3.R+rez_sphere_coords_positive.R;

    //cout << S1 << " " << S2 << " " << S3 << endl;
    Point vector_u, vector_v, vector_w;
    Point temporS1, temporS3;

    temporS1=S1-S2;
    temporS3=S1-S3;

    vector_u=temporS1/vector_len(temporS1);
    vector_v=temporS3/vector_len(temporS3);

    //cout << vector_w << endl;
    vector_w=S1*(-2);
    //cout << vector_w << endl;

    REAL calc_a, calc_b, calc_c;
    calc_a=(pow(ds2,2)-pow(ds1,2)+pow(S1.x,2)-pow(S2.x,2)+pow(S1.y,2)-pow(S2.y,2)+pow(S1.z,2)-pow(S2.z,2))/
           (2*vector_len(temporS1));
    calc_b=(pow(ds3,2)-pow(ds1,2)+pow(S1.x,2)-pow(S3.x,2)+pow(S1.y,2)-pow(S3.y,2)+pow(S1.z,2)-pow(S3.z,2))/
           (2*vector_len(temporS3));
    calc_c=pow(ds1,2)-pow(S1.x,2)-pow(S1.y,2)-pow(S1.z,2);

    Point vector_t;
    Point xProd=cross_prod(vector_u, vector_v);
    vector_t=xProd/vector_len(xProd);
    //cout << vector_t<< endl;

    REAL rez_calc_a, rez_calc_b, rez_calc_c, rez_calc_d_positive, rez_calc_d_negative;
    rez_calc_a=(calc_a-calc_b*dot_prod(vector_u, vector_v))/(1-pow(dot_prod(vector_u, vector_v),2));
    rez_calc_b=(calc_b-calc_a*dot_prod(vector_u, vector_v))/(1-pow(dot_prod(vector_u, vector_v),2));

    rez_calc_c=pow(rez_calc_a,2)+pow(rez_calc_b,2)+2*rez_calc_a*rez_calc_b*dot_prod(vector_u, vector_v)
           +rez_calc_a*dot_prod(vector_u, vector_w)+rez_calc_b*dot_prod(vector_v, vector_w)-calc_c;

    rez_calc_d_positive=(0.5)*(-dot_prod(vector_w, vector_t)+sqrt(pow(dot_prod(vector_w, vector_t),2)-4*rez_calc_c)); // ar reikia minusines reiksmes
    rez_calc_d_negative=(0.5)*(-dot_prod(vector_w, vector_t)-sqrt(pow(dot_prod(vector_w, vector_t),2)-4*rez_calc_c));

    rez_sphere_coords_positive=rez_calc_a*vector_u+rez_calc_b*vector_v+rez_calc_d_positive*vector_t;


    rez_sphere_coords_negative=rez_calc_a*vector_u+rez_calc_b*vector_v+rez_calc_d_negative*vector_t;

    rez_sphere_coords_positive.R=1;
    rez_sphere_coords_negative.R=1;
    data.push_back(rez_sphere_coords_positive);
    data.push_back(rez_sphere_coords_negative);
    /// Tavo kodas
    return data;
}
REAL Math::getDistanceBetweenTwoSpheres(PointType p1,PointType p2)
{
   REAL length;
   length=fabs(vector_len(p1)-vector_len(p2));
   return length;
}
