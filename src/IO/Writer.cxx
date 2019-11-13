#include "Writer.h"
#include <vtkCellArray.h>
using namespace std;
Writer::Writer() {}

void Writer::write(Data *data, ASearch *search, json duomenys,
                   REAL poringumas) {
  /// Irasyti i faila prie daleles kad butu zinomas koks jos tipas tarp procentu
  /// 18 4 2 14 21
  vtkSmartPointer<vtkDoubleArray> radius =
      vtkSmartPointer<vtkDoubleArray>::New();

  vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

  radius->SetName("RADIUS");
  radius->SetNumberOfComponents(1);
  radius->SetNumberOfTuples(data->getNumberOfPoints());

  PointType tempDalele;
  vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
  for (INT i = 0; i < data->getNumberOfPoints(); i++) {
    tempDalele = data->getPoint(i);
    // cout << tempDalele << endl;
    points->InsertNextPoint(tempDalele.x, tempDalele.y, tempDalele.z);

    radius->SetTuple1(i, tempDalele.R);

    cells->InsertNextCell(1);
    cells->InsertCellPoint(i);
  }

  vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
  polydata->SetPoints(points);
  polydata->GetPointData()->SetScalars(radius);
  polydata->SetVerts(cells);
  vtkDoubleArray *por = vtkDoubleArray::New();

  por->SetName("PORINGUMAS");
  por->SetNumberOfComponents(1);
  por->InsertNextTuple1(poringumas);

  polydata->GetFieldData()->AddArray(por);



  std::string filename = duomenys["WRITER"]["FILENAME"];
  if(!data->getPack_done()){

  filename += "_";
  filename += std::to_string(data->getNumberOfPoints());
  
  }



  vtkDataSetWriter *dsw =
      vtkDataSetWriter::New(); 
							   
							    filename += +".vtk";
  dsw->SetFileName(filename.c_str());
  dsw->SetFileTypeToBinary();
  dsw->SetInputData(polydata);

  dsw->Write();
  dsw->Delete();

  cout << "writing done " << endl;

  /// irasome duomenis greiciausiai i VTK faila kaip rezultata.
}
