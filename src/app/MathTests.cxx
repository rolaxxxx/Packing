#include "IO/Reader.h"
#include "IO/Writer.h"
#include "algorithm/AlgorithmFactory.h"
#include "core/Data.h"
#include "random/RandomFactory.h"
#include "search/SearchFactory.h"

bool CheckSpheres(PointType p1, PointType p2, PointType p3, PointType p) {
  double l1 = fabs(vector_len(p - p1) - p.R - p1.R);
  double l2 = fabs(vector_len(p - p2) - p.R - p2.R);
  double l3 = fabs(vector_len(p - p3) - p.R - p3.R);
  if (l1 < 1E-6 && l2 < 1E-6 && l3 < 1E-6) {
    return true;
  } else {
    return false;
  }
}

void Test1() {
  std::cout << "Starting Test1\n";
  PointType P1;
  PointType P2;
  PointType P3;
  /// sudeti pradines koordinates ir radius, pagal kuri bus dedama kita sfera
  P1.x = 0.5;
  P1.y = 0.3;
  P1.z = 0.2;
  P1.R = 1;

  P2.x = 1.75;
  P2.y = 1.599;
  P2.z = -0.666;
  P2.R = 1;

  P3.x = 0.375;
  P3.y = 2.24856;
  P3.z = 0.633012;
  P3.R = 1;

  REAL R = 1; // pasirenkame radius
  Math math;
  PointsArrayType rez = math.getSpheresTouchingThreeOtherSpheres(P1, P3, P2, R);
  for (auto &P : rez) // access by reference to avoid copying
  {
    bool checkas = CheckSpheres(
        P1, P2, P3,
        P); /// tikriname ar atstumas tarp kiekvienos sferu poros yra apie R1+R2
    if (!checkas) {
      std::cout << "Nepraejo cheko, issivedi detalesne info!\n";
      std::cout << P.x << " " << P.y << " " << P.z << " " << P.R << endl;

    } else {
      std::cout << P.x << " " << P.y << " " << P.z << " " << P.R << endl;
    }
  }
  std::cout << "End of test Test1\n";
}

int main() {

  Test1();
  return 0;
}
