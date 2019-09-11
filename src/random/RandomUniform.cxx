#include "RandomUniform.h"

RandomUniform::RandomUniform()
{

}

REAL RandomUniform::getNextValue()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
          static std::uniform_real_distribution<REAL> unif(min, max);
          std::default_random_engine re(seed);
          REAL a_random_double = unif(re);

          return a_random_double;
}
void RandomUniform::initialization(json duomenys)
{
    //cout << duomenys["DISTRIBUTION"]["COUNT"] << endl;
    int index=duomenys["DISTRIBUTION"]["COUNT"];

    for(int k=0;k<index;k++)
    {
            intervals.push_back(duomenys["DISTRIBUTION"]["RADIUS"][k]);

    }
    for(int k=0;k<index;k++)
    {
            probs.push_back(duomenys["DISTRIBUTION"]["PROBABILITY"][k]);
    }

}
