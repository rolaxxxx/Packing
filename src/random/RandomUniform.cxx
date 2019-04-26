#include "RandomUniform.h"

RandomUniform::RandomUniform()
{

}
REAL RandomUniform::getNextValue()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
       static std::uniform_real_distribution<REAL> unif(minValue, maxValue);
	   std::default_random_engine re(seed);
       REAL a_random_double = unif(re);
       return a_random_double;
}
void RandomUniform::initialization()
{

}
