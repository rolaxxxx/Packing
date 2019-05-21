#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>
#include <vector>
#include <random>
#include <nlohmann/json.hpp>
#include <map>
#include <boost/container/map.hpp>
#include <stdlib.h>
#include <unordered_map>
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

#include <boost/compute/system.hpp>
#include <boost/compute/command_queue.hpp>
#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/algorithm/fill.hpp>
#include <boost/compute/algorithm/find.hpp>
#include <boost/compute/algorithm/remove.hpp>
#include <boost/compute/allocator/pinned_allocator.hpp>
#include <boost/compute/container/vector.hpp>


#include <boost/compute/algorithm/count_if.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/random/default_random_engine.hpp>
#include <boost/compute/random/discrete_distribution.hpp>
#include <boost/compute/lambda.hpp>

#include <boost/random/discrete_distribution.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/assign/list_of.hpp>

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
#include <boost/fusion/container/map.hpp>
#include <boost/fusion/include/map.hpp>
#include <boost/fusion/container/map/map_fwd.hpp>
#include <boost/fusion/include/map_fwd.hpp>

using namespace std::chrono;
using boost::compute::uint_;
using boost::compute::lambda::_1;

/// surasome visas konstantas kurias naudosi

#define EPSILON 1.0E-12
#define PI 3.1415926535


typedef double REAL;
typedef int INT;
typedef boost::unordered_map<int, std::vector<INT>> unordered_map;



#endif // CONSTANTS_H
