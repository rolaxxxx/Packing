#include "random/RandomFactory.h"
#include "search/SearchFactory.h"
#include "algorithm/AlgorithmFactory.h"
#include "core/Data.h"
#include "IO/Reader.h"
#include "IO/Writer.h"

bool CheckSpheres(PointType p1,PointType p2,PointType p3,PointType P)
{


    if(vector_len(p1-p2))
    return true;
}

void Test1()
{
    std::cout<<"Starting Test1\n";
    PointType P1;
    PointType P2;
    PointType P3;
    /// sudeti pradines koordinates ir radius, pagal kuri bus dedama kita sfera
    P1.x=0.5;
    P1.y=0.3;
    P1.z=0.2;
    P1.R=1;

    P2.x=1.75;
    P2.y=1.599;
    P2.z=-0.666;
    P2.R=1;

    P3.x=0.375;
    P3.y=2.24856;
    P3.z=0.633012;
    P3.R=1;

    REAL R=1;// pasirenkame radius
    Math math;
    PointsArrayType rez=math.getSpheresTouchingThreeOtherSpheres(P1,P2,P3,R);
    for (auto &P : rez) // access by reference to avoid copying
    {
        bool checkas=CheckSpheres(P1,P2,P3,P);/// tikriname ar atstumas tarp kiekvienos sferu poros yra apie R1+R2
        if(!checkas)
        {
            std::cout<<"Nepraejo cheko, issivedi detalesne info!\n";
        }else
        {
            std::cout<<"OK\n";
        }
    }
    std::cout<<"End of test Test1\n";

}

int main()
{

    Test1();
    return 0;
}
