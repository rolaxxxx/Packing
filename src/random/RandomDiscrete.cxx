#include "RandomDiscrete.h"

RandomDiscrete::RandomDiscrete(){

}

REAL RandomDiscrete::getNextValue()
{

    boost::random::discrete_distribution<> dist(probs);
       return intervals[dist(gen)];
}
void RandomDiscrete::initialization(json duomenys)
{
    //cout << duomenys["DISTRIBUTION"]["COUNT"] << endl;
    int index=duomenys["DISTRIBUTION"]["COUNT"];
    for(int k=0;k<index;k++)
    {
            intervals.push_back(duomenys["DISTRIBUTION"]["RADIUS"][k]);
             //cout << duomenys["DISTRIBUTION"]["RADIUS"][k] <<  "radius " << endl;
    }
    for(int k=0;k<index;k++)
    {
            probs.push_back(duomenys["DISTRIBUTION"]["PROBABILITY"][k]);
            // cout << duomenys["DISTRIBUTION"]["PROBABILITY"][k] <<  "probability " << endl;
    }


}
