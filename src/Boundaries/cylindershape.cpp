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

/*bool CylinderShape::check(Point newSphere )
{
    float dx, dy, dz;	// vector d  from line segment point 1 to point 2
    float pdx, pdy, pdz;	// vector pd from point 1 to test point
    float dot, dsq;

    dx = max.x - min.x;	// translate so min is origin.  Make vector from
    dy = max.y - min.y;     // min to max.  Need for this is easily eliminated
    dz = max.z - min.z;
    //newSphere.PrintStructure();
    pdx = newSphere.x - min.x;		// vector from min to test point.
    pdy = newSphere.y - min.y;
    pdz = newSphere.z - min.z;

    // Dot the d and pd vectors to see if point lies behind the
    // cylinder cap at min.x, min.y, min.z

    dot = pdx * dx + pdy * dy + pdz * dz;

    // If dot is less than zero the point is behind the min cap.
    // If greater than the cylinder axis line segment length squared
    // then the point is outside the other end cap at max.

    if( dot < 0.0f || dot > height )
    {
        return( -1.0f );
    }
    else
    {
        // Point lies within the parallel caps, so find
        // distance squared from point to line, using the fact that sin^2 + cos^2 = 1
        // the dot = cos() * |d||pd|, and cross*cross = sin^2 * |d|^2 * |pd|^2
        // Carefull: '*' means mult for scalars and dotproduct for vectors
        // In short, where dist is pt distance to cyl axis:
        // dist = sin( pd to d ) * |pd|
        // distsq = dsq = (1 - cos^2( pd to d)) * |pd|^2
        // dsq = ( 1 - (pd * d)^2 / (|pd|^2 * |d|^2) ) * |pd|^2
        // dsq = pd * pd - dot * dot / LENGTHSQ
        //  where LENGTHSQ is d*d or |d|^2 that is passed into this function

        // distance squared to the cylinder axis:

        dsq = (pdx*pdx + pdy*pdy + pdz*pdz) - dot*dot/height;

        if( dsq > radius )
        {
            false;
        }
        else
        {
            true;	// return distance squared to axis
        }
    }
}
*/
void CylinderShape::initialization(json duomenys)
{

    min.x=duomenys["BOUNDARIES"]["BMIN"][0];
    min.y=duomenys["BOUNDARIES"]["BMIN"][1];
    min.z=duomenys["BOUNDARIES"]["BMIN"][2];

    max.x=duomenys["BOUNDARIES"]["BMAX"][0];
    max.y=duomenys["BOUNDARIES"]["BMAX"][1];
    max.z=duomenys["BOUNDARIES"]["BMAX"][2];

    height=duomenys["BOUNDARIES"]["LENGTHSQ"];
    radius=duomenys["BOUNDARIES"]["RADIUSSQ"];
}
