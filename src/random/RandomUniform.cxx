#include "RandomUniform.h"

RandomUniform::RandomUniform()
{

}

REAL RandomUniform::getNextValue()
{
    
        
       static std::uniform_real_distribution<REAL> unif(min, max);
	   std::default_random_engine re(seed);
       REAL a_random_double = unif(re);
     
	 
	 return a_random_double;
      
}
void RandomUniform::initialization(json duomenys)
{
    //cout << duomenys["DISTRIBUTION"]["COUNT"] << endl;
    int index=duomenys["DISTRIBUTION"]["COUNT"];
    min=duomenys["DISTRIBUTION"]["RMIN"];
	max=duomenys["DISTRIBUTION"]["RMAX"];
	
	

}