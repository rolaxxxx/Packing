#include "Boundaries/BoundariesShape.h"
#include "IO/Reader.h"
#include "algorithm/AlgorithmFactory.h"
#include "core/Data.h"
#include "core/time.h"
#include "random/RandomFactory.h"
#include "search/SearchFactory.h"
//#include "core/Check_json.h"
#include "IO/Writer.h"
using namespace std;
int main(int argc, char **argv) {
  // Timer taim;
  //  taim.StartTimer();
  // Check_json check_file;
  Reader reader;
  Writer writer;
  // double rez_time;

  Data *data = new Data();

  // nuskaitome duomenis is failo jeigu to reikia
  reader.read(data, argv[1]);
  // cout << argv[1] << endl;
  // galime ir rankomis sudeti pradinius taskus, naudojant Data klases objekta
  srand(time(NULL));
  /// koks failo formatas turi buti paduotas i funkcija dabar paduodamas string
  /// formatas
  json duomenys = json::parse(data->getDuomenys());
  // check_file.Validation(duomenys);
  RandomFactory randomFactory;
  SearchFactory searchFactory;
  AlgorithmFactory algorithmFactory;
  BoundariesShape shape;

  ARandom *random = randomFactory.create(duomenys["DISTRIBUTION"]["TYPE"]);
  ASearch *search = searchFactory.create(duomenys["SEARCH"]["TYPE"]);
  AAlgorithm *algorithm =
      algorithmFactory.create(duomenys["ALGORITHM"]["TYPE"]);

  BBoundaries *bounds = shape.create(duomenys["BOUNDARIES"]["TYPE"]);
  bounds->init(search, duomenys);
  search->SetBounds(bounds->getBounds());
  PointType P1, P2, P3, P4;

  double RMIN = duomenys["DISTRIBUTION"]["RMIN"];
  double *boundaries;
  boundaries = bounds->getBounds();
  Point half_bounds;

  half_bounds.x = (boundaries[1] + boundaries[0]) / 2;
  half_bounds.y = (boundaries[3] + boundaries[2]) / 2;
  half_bounds.z = (boundaries[5] + boundaries[4]) / 2;
  //  cout << " bounds struktura " << endl;
  // half_bounds.PrintStructure();
  // cout << "boundaries " << boundaries[0] << " " << boundaries[1] << " " << "
  // " << boundaries[2]<< " " << boundaries[3]<< " " << boundaries[4] << " " <<
  // boundaries[5] << endl;

  random->init(duomenys);
  search->init(data, duomenys);

  if (duomenys["INPUT"]["TYPE"] ==
      "STANDART") { // MESH_FILE OR THREE SPHERES HANDLED BY ELSE
    P1.x = half_bounds.x;
    P1.y = half_bounds.y;
    P1.z = half_bounds.z;
    P1.R = RMIN;

    P2.x = (half_bounds.x) + 2 * RMIN;
    P2.y = half_bounds.y;
    P2.z = half_bounds.z;
    P2.R = RMIN;

    P3.x = half_bounds.x + RMIN;
    P3.y = (2.0 * RMIN * sqrt(3.0) / 2.0) + half_bounds.y;
    P3.z = half_bounds.z;
    P3.R = RMIN;

    search->addPoint(P1);
    search->addPoint(P2);
    search->addPoint(P3);
  } else {

    std::string filename = duomenys["INPUT"]["filename"];
    reader.readVTK(search, filename);
  }

  algorithm->init(data, random, search, duomenys, bounds, 10, writer);
  // cout << data->getNumberOfPoints() << endl;
  /// atliekame tikraji pakinima
  algorithm->pack();
  // cout << data->getNumberOfPoints() << endl;
  writer.write(data, search, duomenys,
               algorithm->getPoringumas()); // irasome rezultata
                                            // taim.StopTimer();
  cout << "Program finished " << endl;
  //  rez_time+=taim.ElapsedTime("sec");
  // cout << rez_time << "laikas visai programai ------------ " << endl;
  return 0;
}
