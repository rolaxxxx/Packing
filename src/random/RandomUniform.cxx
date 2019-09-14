#include "RandomUniform.h"

RandomUniform::RandomUniform()
{

}

REAL RandomUniform::getNextValue()
{

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
          std::default_random_engine re(seed);
          static std::uniform_real_distribution<REAL> unif(min, max);
          REAL a_random_double = unif(re);

          return a_random_double;
}
void RandomUniform::initialization(json duomenys)
{
    min=duomenys["DISTRIBUTION"]["RMIN"];
    max=duomenys["DISTRIBUTION"]["RMAX"];
}
