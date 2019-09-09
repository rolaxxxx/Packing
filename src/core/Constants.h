#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>
#include <vector>
#include <random>
#include "core/json_reader.h"
#include <map>
#include <boost/container/map.hpp>
#include <stdlib.h>
#include <unordered_map>
using std::cout;
using std::endl;
using json = nlohmann::json;
#include <list>
#include <cmath>
#include <vtkCylinderSource.h>
#include <utility>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include <algorithm>
#include "core/time.h"
#include <utility>
#include <vtkDataSetWriter.h>
#include <vtkGenericDataObjectReader.h>

#include <vtkCellArray.h>

#include <vtkDataSetReader.h>
#include <vtkDataSetAttributes.h>
#include <vtkDataSet.h>
#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkTriangle.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkPolyDataReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>



#include <boost/random/discrete_distribution.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/assign/list_of.hpp>

#include <vtkSmartPointer.h>
#include <vtkProperty.h>
#include <vtkPolyData.h>
#include <vtkTriangleFilter.h>
#include <vtkRegularPolygonSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkDoubleArray.h>
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkGlyph3D.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>
#include <vtkCubeSource.h>
#include <boost/unordered_map.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <chrono>
#include "vtkDataSetReader.h"
#include <boost/fusion/container/map.hpp>
#include <boost/fusion/include/map.hpp>
#include <boost/fusion/container/map/map_fwd.hpp>
#include <boost/fusion/include/map_fwd.hpp>

using namespace std::chrono;

/// surasome visas konstantas kurias naudosi

#define EPSILON 1.0E-12
#define PI 3.1415926535


typedef double REAL;
typedef int INT;

typedef boost::unordered_map<int, std::vector<INT>> unordered_map;



#endif // CONSTANTS_H
