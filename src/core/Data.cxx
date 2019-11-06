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
									else {std::cerr<<"Klaida   WRITER/TEMP_REZULTS_SWITCH REIKSME NERASTA  \n";
									return 0;
									}
							}
								else {std::cerr<<"Klaida   WRITER/AMOUNT_PARTICLES REIKSME NERASTA  \n";
								return 0;
								}
						
						}	
							else {std::cerr<<"Klaida   DISTRIBUTION/RADIUS REIKSME NERASTA  \n";
							return 0;
							}
					}
						else { std::cerr<<"Klaida   DISTRIBUTION/RMIN REIKSME NERASTA  \n";
						return 0;
						}
				}
					else {std::cerr<<"Klaida   DISTRIBUTION/RMAX REIKSME NERASTA  \n";
					return 0;
					}
		}
		else if(duomenys["BOUNDARIES"]["TYPE"]=="Cube")
			if(file.find("RMAX") != std::string::npos){
				if(file.find("RMIN") != std::string::npos){
					if(file.find("RADIUS") != std::string::npos){
						if(file.find("AMOUNT_PARTICLES") != std::string::npos){
							if(file.find("TEMP_REZULTS_SWITCH") != std::string::npos){
								if(file.find("BMIN") != std::string::npos){
									if(file.find("BMAX") != std::string::npos){
										
									}
									else {std::cerr<<"Klaida   BOUNDARIES/BMAX REIKSME NERASTA  \n";
									return 0;
									}
								}
								else {std::cerr<<"Klaida   BOUNDARIES/BMIN REIKSME NERASTA  \n";
								return 0;
								}
									
								}
									else {std::cerr<<"Klaida   WRITER/TEMP_REZULTS_SWITCH REIKSME NERASTA  \n";
									return 0;
									}
							}
								else {std::cerr<<"Klaida   WRITER/AMOUNT_PARTICLES REIKSME NERASTA  \n";
								return 0;
								}
						
						}	
							else {std::cerr<<"Klaida   DISTRIBUTION/RADIUS REIKSME NERASTA  \n";
							return 0;
							}
					}
						else {std::cerr<<"Klaida   DISTRIBUTION/RMIN REIKSME NERASTA  \n";
						return 0;
						}
				}
					else {std::cerr<<"Klaida   DISTRIBUTION/RMAX REIKSME NERASTA  \n";
					return 0;
					}
					
		else if(duomenys["BOUNDARIES"]["TYPE"]=="Cylinder")
			if(file.find("RMAX") != std::string::npos){
				if(file.find("RMIN") != std::string::npos){
					if(file.find("RADIUS") != std::string::npos){
						if(file.find("AMOUNT_PARTICLES") != std::string::npos){
							if(file.find("TEMP_REZULTS_SWITCH") != std::string::npos){
								if(file.find("CYLINDER_MIDDLE_MIN") != std::string::npos){
									if(file.find("CYLINDER_MIDDLE_MAX") != std::string::npos){
										if(file.find("BOUNDS_MIN") != std::string::npos){
											if(file.find("BOUNDS_MAX") != std::string::npos){
												if(file.find("RADIUSSQ") != std::string::npos){
													
												}
												else {std::cerr<<"Klaida   BOUNDARIES/RADIUSSQ REIKSME NERASTA  \n";
												return 0;
												}
											}
											else {std::cerr<<"Klaida   BOUNDARIES/BOUNDS_MAX REIKSME NERASTA  \n";
											return 0;
											}
										}
										else {std::cerr<<"Klaida   BOUNDARIES/BOUNDS_MIN REIKSME NERASTA  \n";
										return 0;
										}
									}
									else {std::cerr<<"Klaida   BOUNDARIES/CYLINDER_MIDDLE_MAX REIKSME NERASTA  \n";
									return 0;
									}
								}
								else {std::cerr<<"Klaida   BOUNDARIES/CYLINDER_MIDDLE_MIN REIKSME NERASTA  \n";
								return 0;
								}
									
								}
									else {std::cerr<<"Klaida   WRITER/TEMP_REZULTS_SWITCH REIKSME NERASTA  \n";
									return 0;
									}
							}
								else {std::cerr<<"Klaida   WRITER/AMOUNT_PARTICLES REIKSME NERASTA  \n";
								return 0;
								}
						
						}	
							else {std::cerr<<"Klaida   DISTRIBUTION/RADIUS REIKSME NERASTA  \n";
							return 0;
							}
					}
						else {std::cerr<<"Klaida   DISTRIBUTION/RMIN REIKSME NERASTA  \n";
						return 0;
						}
				}
					else {std::cerr<<"Klaida   DISTRIBUTION/RMAX REIKSME NERASTA  \n";
					return 0;
					}
		
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
