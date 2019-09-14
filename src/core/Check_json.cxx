#include "Check_json.h"

Check_json::Check_json()
{

}

void Check_json::Validation(json duomenys){
    if(duomenys["BOUNDARIES"]["TYPE"]=="Cube"){
        if(duomenys["DISTRIBUTION"]["TYPE"]=="Discrete"||duomenys["DISTRIBUTION"]["TYPE"]=="Uniform"){

           // if (duomenys.find("")!= o.end()) { variantas kaip rasti ar raktas yra json faile
              // there is an entry with key "foo"
           // }
        }

        else cerr << "neisvestas pasiskirstymo tipas. Galimi tipai Discrete/Uniform " << endl;

    }
    else if(duomenys["BOUNDARIES"]["TYPE"]=="Cylinder"){

        if(duomenys["DISTRIBUTION"]["TYPE"]=="Discrete"||duomenys["DISTRIBUTION"]["TYPE"]=="Uniform"){

        }
        else cerr << "neisvestas pasiskirstymo tipas. Galimi tipai Discrete/Uniform " << endl;
    }
    else if(duomenys["BOUNDARIES"]["TYPE"]=="Mesh")
    {
        if(duomenys["DISTRIBUTION"]["TYPE"]=="Discrete"||duomenys["DISTRIBUTION"]["TYPE"]=="Uniform"){

        }
        else cerr << "neisvestas pasiskirstymo tipas. Galimi tipai Discrete/Uniform " << endl;
    }
    else cerr << "nerasta ivesta Boundaries figura. Galimi variantai Cube/Cylinder/Mesh " << endl;
}






