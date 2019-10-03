#include "Point.h"




Point operator * (Point A, INT B)
{
    A.x*=B;
    A.y*=B;
    A.z*=B;
    A.R*=B;
    return A;
}
Point operator + (Point A, Point B)
{
    A.x+=B.x;
    A.y+=B.y;
    A.z+=B.z;
    A.R+=B.R;
    return A;
}
Point operator - (Point A, REAL B)
{
    A.x-=B;
    A.y-=B;
    A.z-=B;
    return A;
}

Point operator + (Point A, REAL B)
{
    A.x+=B;
    A.y+=B;
    A.z+=B;
    return A;
}
Point operator * (REAL A, Point B)
{
    B.x*=A;
    B.y*=A;
    B.z*=A;
    B.R*=A;
    return B;
}

Point operator * (Point A, Point B)
{
    A.x*=B.x;
    A.y*=B.y;
    A.z*=B.z;
    A.R*=B.R;
    return A;
}

Point operator / (Point A,  REAL B )
{
    A.x/=B;
    A.y/=B;
    A.z/=B;
    A.R/=B;
    return A;
}
Point operator - (Point A,  Point B )
{
    A.x-=B.x;
    A.y-=B.y;
    A.z-=B.z;
    A.R-=B.R;
    return A;
}
bool operator != (PointType A, PointType B){
    if(A.x!=B.x&&A.y!=B.y&&A.z!=B.z)
        return true;
    return false;
}
REAL dot_prod(Point vec_a, Point vec_b){  // dot produkto skaiciavimas
    REAL dot_prod_rez;
    dot_prod_rez=vec_a.x*vec_b.x + vec_a.y*vec_b.y + vec_a.z*vec_b.z;
    return dot_prod_rez;
}
Point cross_prod(Point vec_a, Point vec_b){ //  cross produkto skaiciavimas
    Point prod_rez;
    prod_rez.x=vec_a.y*vec_b.z-vec_a.z*vec_b.y;
    prod_rez.y=vec_a.z*vec_b.x-vec_a.x*vec_b.z;
    prod_rez.z=vec_a.x*vec_b.y-vec_a.y*vec_b.x;
    return prod_rez;
}
/*Point cross2D(Point vec_a, Point vec_b){ //  cross produkto skaiciavimas
    Point prod_rez;
    prod_rez=vec_a.x*vec_b.y-vec_b.y*vec_a.x;
    return prod_rez;
}
*/
REAL tripleScalarProd(Point vec_a, Point vec_b, Point vec_c){
     REAL tripleProdRez;
    tripleProdRez=dot_prod(cross_prod(vec_a, vec_b), vec_c);
    return tripleProdRez;

}

REAL vector_len(Point vec){
    return std::sqrt(vec.x*vec.x + vec.y*vec.y+vec.z*vec.z);
}
REAL vec_distance(Point a, Point c)
{
	REAL d;
	d = pow(pow((c.x - a.x),2) + pow((c.y - a.y),2) + pow((c.z- a.y),2),0.5);
	return d;
}

