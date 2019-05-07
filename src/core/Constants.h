#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <stdlib.h>
#include <list>
#include <cmath>
#include <utility>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <algorithm>



#include <boost/compute/system.hpp>
#include <boost/compute/command_queue.hpp>
#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/algorithm/fill.hpp>
#include <boost/compute/algorithm/find.hpp>
#include <boost/compute/algorithm/remove.hpp>
#include <boost/compute/allocator/pinned_allocator.hpp>
#include <boost/compute/container/vector.hpp>


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

#include <chrono>

using namespace std::chrono;
/// surasome visas konstantas kurias naudosi

#define EPSILON 1.0E-12
#define PI 3.1415926535


typedef double REAL;
typedef int INT;



#endif // CONSTANTS_H
