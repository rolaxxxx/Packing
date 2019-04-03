#include "random/RandomFactory.h"
#include "search/SearchFactory.h"
#include "algorithm/AlgorithmFactory.h"
#include "core/Data.h"
#include "IO/Reader.h"
#include "IO/Writer.h"

bool CheckSpheres(PointType p1,PointType p2,PointType p3,PointType p4)
{
    return true;
}

void Test1()
{
    std::cout<<"Starting Test1\n";
    PointType P1;
    PointType P2;
    PointType P3;
    /// sudeti pradines koordinates ir radius, pagal kuri bus dedama kita sfera
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
