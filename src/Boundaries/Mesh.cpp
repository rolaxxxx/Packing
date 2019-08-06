#include "Mesh.h"

Mesh::Mesh(){
    
}
bool Mesh::check(Point p, Point a, Point b, Point c){
    a -= p; b -= p; c -= p;
    float ab = dot_prod(a, b);
    float ac = dot_prod(a, c);
    float bc = dot_prod(b, c);
    float cc = dot_prod(c, c);
    // Make sure plane normals for pab and pbc point in the same direction
    if (((bc * ac) - (cc * ab)) < 0.0f)
        return 0;
    // Make sure plane normals for pab and pca point in the same direction
    float bb = dot_prod(b, b);
    if (((ab * bc) - (ac * bb)) < 0.0f) return 0;
    // Otherwise P must be in (or on) the triangle
    return 1;
}



void Mesh::initialization(json duomenys){

}
