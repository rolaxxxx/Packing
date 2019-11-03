#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "core/json_reader.h"
#include <boost/container/map.hpp>
#include <iostream>
#include <map>
#include <random>
#include <stdlib.h>
#include <vector>

#include <unordered_map>
using std::cerr;
using std::cout;
using std::endl;
using json = nlohmann::json;
#include "core/time.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <list>
#include <string>
#include <utility>
#include <vtkCylinderSource.h>
#include <vtkDataSetWriter.h>
#include <vtkGenericDataObjectReader.h>

#include <vtkCellArray.h>

#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkDataSet.h>
#include <vtkDataSetAttributes.h>
#include <vtkDataSetReader.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkTriangle.h>
#include <vtkVersion.h>

#include <boost/assign/list_of.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/linear_congruential.hpp>

#include <vtkActor.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRegularPolygonSource.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkTriangleFilter.h>

#include "Check_json.h"
#include "vtkDataSetReader.h"
#include <boost/exception/diagnostic_information.hpp>
#include <boost/fusion/container/map.hpp>
#include <boost/fusion/container/map/map_fwd.hpp>
#include <boost/fusion/include/map.hpp>
#include <boost/fusion/include/map_fwd.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/unordered_map.hpp>
#include <chrono>
#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkCubeSource.h>
#include <vtkDataArray.h>
#include <vtkDoubleArray.h>
#include <vtkGlyph3D.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>

using namespace std::chrono;

/// surasome visas konstantas kurias naudosi

#define EPSILON 1.0E-12
#define PI 3.1415926535

typedef double REAL;
typedef int INT;

typedef boost::unordered_map<int, std::vector<INT>> unordered_map;

#endif // CONSTANTS_H
