#include "Data.h"

Data::Data() {}

void Data::insertNextPoint(PointType p) {
  data.push_back(p);
  particle_turis += (4.0 / 3.0) * PI * pow(p.R, 3);
}
PointType Data::getPoint(INT i) { return data[i]; }
INT Data::getNumberOfPoints() { return data.size(); }

std::string Data::getDuomenys() const { return duomenys; }

bool Data::Json_cheker(json duomenys, std::string file){
	
 
     // call contains
   
		if(duomenys["BOUNDARIES"]["TYPE"]=="Mesh"){
			
			if(file.find("RMAX") != std::string::npos){
				if(file.find("RMIN") != std::string::npos){
					if(file.find("RADIUS") != std::string::npos){
						if(file.find("AMOUNT_PARTICLES") != std::string::npos){
							if(file.find("TEMP_REZULTS_SWITCH") != std::string::npos){
								
									
								}
									else std::cerr<<"Klaida   WRITER/TEMP_REZULTS_SWITCH REIKSME NERASTA  \n";
							}
								else std::cerr<<"Klaida   WRITER/AMOUNT_PARTICLES REIKSME NERASTA  \n";
						
						}	
							else std::cerr<<"Klaida   DISTRIBUTION/RADIUS REIKSME NERASTA  \n";
					}
						else std::cerr<<"Klaida   DISTRIBUTION/RMIN REIKSME NERASTA  \n";
				}
					else std::cerr<<"Klaida   DISTRIBUTION/RMAX REIKSME NERASTA  \n";
		}
		else if(duomenys["BOUNDARIES"]["TYPE"]=="Cube")
			if(file.find("RMAX") != std::string::npos){
				if(file.find("RMIN") != std::string::npos){
					if(file.find("RADIUS") != std::string::npos){
						if(file.find("AMOUNT_PARTICLES") != std::string::npos){
							if(file.find("TEMP_REZULTS_SWITCH") != std::string::npos){
								
									
								}
									else std::cerr<<"Klaida   WRITER/TEMP_REZULTS_SWITCH REIKSME NERASTA  \n";
							}
								else std::cerr<<"Klaida   WRITER/AMOUNT_PARTICLES REIKSME NERASTA  \n";
						
						}	
							else std::cerr<<"Klaida   DISTRIBUTION/RADIUS REIKSME NERASTA  \n";
					}
						else std::cerr<<"Klaida   DISTRIBUTION/RMIN REIKSME NERASTA  \n";
				}
					else std::cerr<<"Klaida   DISTRIBUTION/RMAX REIKSME NERASTA  \n";
					
		else if(duomenys["BOUNDARIES"]["TYPE"]=="Cylinder")
			if(file.find("RMAX") != std::string::npos){
				if(file.find("RMIN") != std::string::npos){
					if(file.find("RADIUS") != std::string::npos){
						if(file.find("AMOUNT_PARTICLES") != std::string::npos){
							if(file.find("TEMP_REZULTS_SWITCH") != std::string::npos){
								
									
								}
									else std::cerr<<"Klaida   WRITER/TEMP_REZULTS_SWITCH REIKSME NERASTA  \n";
							}
								else std::cerr<<"Klaida   WRITER/AMOUNT_PARTICLES REIKSME NERASTA  \n";
						
						}	
							else std::cerr<<"Klaida   DISTRIBUTION/RADIUS REIKSME NERASTA  \n";
					}
						else std::cerr<<"Klaida   DISTRIBUTION/RMIN REIKSME NERASTA  \n";
				}
					else std::cerr<<"Klaida   DISTRIBUTION/RMAX REIKSME NERASTA  \n";
		
}


void Data::setDuomenys(const std::string &value) { duomenys = value; }

REAL Data::getParticle_turis() const { return particle_turis; }

bool Data::getPack_done() const
{
    return pack_done;
}

void Data::setPack_done(bool value)
{
    pack_done = value;
}
