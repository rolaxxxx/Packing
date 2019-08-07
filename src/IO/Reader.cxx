#include "Reader.h"

Reader::Reader()
{

}
void Reader::read(Data * data,std::string filename)
{
   /// nuskaitome pradines daleliu duomenis is failo  
   std::string configData;
         std::ifstream t(filename);
         std::string str((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
         configData=str;
         data->setDuomenys(configData);
}
