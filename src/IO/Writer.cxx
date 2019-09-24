#include "Writer.h"
#include <vtkCellArray.h>
using namespace std;
Writer::Writer()
{

}

void Writer::write(Data*data, ASearch *search ,json duomenys, REAL poringumas)
{
        ///Irasyti i faila prie daleles kad butu zinomas koks jos tipas tarp procentu 18 4 2 14 21
         vtkSmartPointer<vtkDoubleArray> radius =
         vtkSmartPointer<vtkDoubleArray>::New();

         vtkSmartPointer<vtkPoints> points =
         vtkSmartPointer<vtkPoints>::New();


     radius->SetName("RADIUS");
     radius->SetNumberOfComponents(1);
     radius->SetNumberOfTuples(data->getNumberOfPoints());




         PointType tempDalele;
         vtkSmartPointer<vtkCellArray> cells=vtkSmartPointer<vtkCellArray>::New();
        for(INT i=0;i<data->getNumberOfPoints();i++)
        {
             tempDalele=data->getPoint(i);
             //cout << tempDalele << endl;
             points->InsertNextPoint(tempDalele.x,tempDalele.y, tempDalele.z);

             radius->SetTuple1(i,  tempDalele.R);


             //cout << distance(intervals.begin(), find(intervals.begin(), intervals.end(), tempDalele.R)) <<  endl;
            // cout<< tempDalele.x << " " << tempDalele.y << " " << tempDalele.z << " " << tempDalele.R << endl;
             cells->InsertNextCell(1);
             cells->InsertCellPoint(i);
        }


        vtkSmartPointer<vtkPolyData> polydata =
              vtkSmartPointer<vtkPolyData>::New();
            polydata->SetPoints(points);
          polydata->GetPointData()->SetScalars(radius);
          polydata->SetVerts(cells);
          //polydata->GetPointData()->SetScalars(particle_probabilities);

          /*vtkSmartPointer<vtkDoubleArray> procentai = vtkDoubleArray::New();
              procentai->SetName("PARTICLE_TYPE");
       procentai->SetNumberOfComponents(1);
              for(int i=0;i<probabilities.size();i++){
                  procentai->InsertNextTuple1(probabilities[i]);
              }
        */
          vtkDoubleArray *por = vtkDoubleArray::New();

              por->SetName("PORINGUMAS");
              por->SetNumberOfComponents(1);
          por->InsertNextTuple1(poringumas);





              polydata->GetFieldData()->AddArray(por);



            //VTK_DOUBLE poring=poringumas;


// galima naudoti smart pointer nereikes delete funkcijos
          vtkSmartPointer<vtkDataSetWriter> dsw = vtkSmartPointer<vtkDataSetWriter>::New();
		  std::string filename=duomenys["WRITER"]["FILENAME"];
              //vtkDataSetWriter *dsw = vtkDataSetWriter::New(); // reikia pakeisti i smart pointer // ant cylindro luzta
                dsw->SetFileName(filename.c_str());
                dsw->SetFileTypeToBinary();
                dsw->SetInputData(polydata);

                dsw->Write();
            dsw->Delete();


                cout << "writing done " << endl;

    /// irasome duomenis greiciausiai i VTK faila kaip rezultata.

}
