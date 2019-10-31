#include "SearchUnform.h"

using namespace std;
SearchUnform::SearchUnform() {}
void SearchUnform::initialization() { SUFORMUOTAS_GRIDAS.resize(Nx * Ny * Nz); }

INT SearchUnform::calculateID(PointType p) {
  PointType temp_coords;
  INT xx = (int)floor((p.x - bmin.x) / CELL_SIZE);
  INT yy = (int)floor((p.y - bmin.y) / CELL_SIZE);
  INT zz = (int)floor((p.z - bmin.z) / CELL_SIZE);
  return xx + yy * Nx + zz * Nx * Ny;
}

void SearchUnform::addPoint(PointType p) {
  int id = data->getNumberOfPoints();
  INT calc_id = calculateID(p);
  if (calc_id >= 0) {

    std::vector<INT> temp = SUFORMUOTAS_GRIDAS[calc_id];

    temp.push_back(id);

    SUFORMUOTAS_GRIDAS[calc_id] = temp;

    p.ID = id;
    data->insertNextPoint(p);
  }
}

std::vector<INT> &SearchUnform::getCellElements(INT id) {

  return SUFORMUOTAS_GRIDAS[id];
}
std::vector<INT> SearchUnform::GetPotentialNeighbours(Point temp) {
  std::vector<INT> ids;

  INT xx = (int)floor((temp.x - bmin.x) / CELL_SIZE);
  INT yy = (int)floor((temp.y - bmin.y) / CELL_SIZE);
  INT zz = (int)floor((temp.z - bmin.z) / CELL_SIZE);
  for (INT x = xx - 1; x <= xx + 1; x++) {
    for (INT y = yy - 1; y <= yy + 1; y++) {
      for (INT z = zz - 1; z <= zz + 1; z++) {

        if (x < Nx && y < Ny && z < Nz && x >= 0 && y >= 0 && z >= 0) {
          INT TEMP_ID = x + y * Nx + z * Nx * Ny;

          std::vector<INT> &potencialus_kaimynai = getCellElements(TEMP_ID);

          for (INT i = 0; i < potencialus_kaimynai.size(); i++) {

            if (temp.ID != potencialus_kaimynai[i])
              ids.push_back(potencialus_kaimynai[i]);
          }
        }
      }
    }
  }

  return ids;
}

std::vector<INT> SearchUnform::getGridNeigbours(INT id) {
  Point p = data->getPoint(id);

  std::vector<INT> potencialus_kaimynai = GetPotentialNeighbours(p);
  return potencialus_kaimynai;
}

std::vector<INT> SearchUnform::getNeighboursID(INT id) {

  Point p = data->getPoint(id);
  std::vector<INT> potencialus_kaimynai = GetPotentialNeighbours(p);

  std::vector<INT> ids;

  for (int i = 0; i < potencialus_kaimynai.size(); i++) {

    Point target = data->getPoint(potencialus_kaimynai[i]);
    double L = vector_len(p - target);
    double L2 = L - p.R - target.R;

    if (L2 <= 4 * RMax) //  EPSILON 2*RMax // paimti daugiau kad po to nereiketu

    {

      ids.push_back(potencialus_kaimynai[i]);
    }
  }

  return ids;
}
bool SearchUnform::intersect(PointType p, vector<INT> neighbours) {

  std::vector<INT> potencialus_kaimynai = GetPotentialNeighbours(p);

  for (int i = 0; i < potencialus_kaimynai.size(); i++) {
    Point target = data->getPoint(potencialus_kaimynai[i]);
    double L2 = vector_len(p - target) - p.R - target.R;
    if (L2 < -EPSILON)
      return true;
  }
  return false;
}
bool SearchUnform::check_sphere_touch(PointType s1, PointType s2, PointType s3, PointType calculated_point){
	
}
