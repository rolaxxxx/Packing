#include "Data.h"

Data::Data() {}

void Data::insertNextPoint(PointType p) {
  data.push_back(p);
  particle_turis += (4.0 / 3.0) * PI * pow(p.R, 3);
}
PointType Data::getPoint(INT i) { return data[i]; }
INT Data::getNumberOfPoints() { return data.size(); }

std::string Data::getDuomenys() const { return duomenys; }

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
