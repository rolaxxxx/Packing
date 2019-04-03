#include "RandomUniform.h"

RandomUniform::RandomUniform()
{

}
REAL RandomUniform::getNextValue()
{
    srand (time(NULL));
       std::uniform_real_distribution<REAL> unif(minValue, maxValue);
       std::default_random_engine re;
       REAL a_random_double = unif(re);
       return a_random_double;
}
void RandomUniform::initialization()
{

}
