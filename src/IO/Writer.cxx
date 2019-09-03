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

         vtkSmartPointer<vtkIntArray> radius_index =
         vtkSmartPointer<vtkIntArray>::New();

         vector<REAL>intervals;
         int index=duomenys["DISTRIBUTION"]["COUNT"];
         for(int k=0;k<index;k++)
         {
                 intervals.push_back(duomenys["DISTRIBUTION"]["RADIUS"][k]);
         }
     radius->SetName("RADIUS");
     radius->SetNumberOfComponents(1);
     radius->SetNumberOfTuples(data->getNumberOfPoints());

     radius_index->SetName("PARTICLE_TYPE");
     radius_index->SetNumberOfComponents(1);
     radius_index->SetNumberOfTuples(data->getNumberOfPoints());



         PointType tempDalele;
         vtkSmartPointer<vtkCellArray> cells=vtkSmartPointer<vtkCellArray>::New();
        for(INT i=0;i<data->getNumberOfPoints();i++)
        {
             tempDalele=data->getPoint(i);
             //cout << tempDalele << endl;
             points->InsertNextPoint(tempDalele.x,tempDalele.y, tempDalele.z);

             radius->SetTuple1(i,  tempDalele.R);
             radius_index->SetTuple1(i, distance(intervals.begin(), find(intervals.begin(), intervals.end(), tempDalele.R)));

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

              polydata->GetPointData()->AddArray(radius_index);

            //VTK_DOUBLE poring=poringumas;



          vtkDataSetWriter *dsw = vtkDataSetWriter::New();
                dsw->SetFileName("rezultatai.vtk");
                dsw->SetFileTypeToBinary();
                dsw->SetInputData(polydata);

                dsw->Write();
                cout << "writing done " << endl;




/*
                ///// cylinder output
                vtkSmartPointer<vtkPolyDataMapper> mapper =
                    vtkSmartPointer<vtkPolyDataMapper>::New();
                  mapper->SetInputConnection(cylinderSource->GetOutputPort());
                  vtkSmartPointer<vtkActor> actor =
                    vtkSmartPointer<vtkActor>::New();
                  actor->SetMapper(mapper);
                  actor->GetProperty()->SetOpacity(0.4);
                  //Create a renderer, render window, and interactor
                  vtkSmartPointer<vtkRenderer> renderer =
                    vtkSmartPointer<vtkRenderer>::New();
                  vtkSmartPointer<vtkRenderWindow> renderWindow =
                    vtkSmartPointer<vtkRenderWindow>::New();
                  renderWindow->AddRenderer(renderer);
                  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
                    vtkSmartPointer<vtkRenderWindowInteractor>::New();
                  renderWindowInteractor->SetRenderWindow(renderWindow);
                  // Add the actor to the scene
                  renderer->AddActor(actor);
                  renderer->SetBackground(.1, .3,.2); // Background color dark green
                  // Render and interact
                  renderWindow->Render();
                  renderWindowInteractor->Start();
*/

                  ////// cylinder output end

           vtkSmartPointer<vtkPolyData> glyph =
        vtkSmartPointer<vtkPolyData>::New();
            vtkSmartPointer<vtkSphereSource> SphereSource =
          vtkSmartPointer<vtkSphereSource>::New();
        SphereSource->SetPhiResolution(10);
         SphereSource->SetRadius(1); //radius visada vienas kai atvaizduoju sferas //reikia pakeisti/////
     SphereSource->SetThetaResolution(10);
            SphereSource.Get()->GetCenter();
            vtkSmartPointer<vtkGlyph3D> glyph3D =
              vtkSmartPointer<vtkGlyph3D>::New();
            glyph3D->SetColorModeToColorByScalar();
            glyph3D->SetScaleFactor(1);
          #if VTK_MAJOR_VERSION <= 5
            glyph3D->SetSource(SphereSource->GetOutput());
            glyph3D->SetInput(polydata);
          #else
            glyph3D->SetSourceConnection(SphereSource->GetOutputPort());
            glyph3D->SetInputData(polydata);
          #endif
        glyph3D->Update();
        vtkSmartPointer<vtkPolyDataMapper> mapper =
             vtkSmartPointer<vtkPolyDataMapper>::New();
       mapper->SetInputConnection(glyph3D->GetOutputPort());
       mapper->SetScalarRange(radius->GetRange());
       mapper->ColorByArrayComponent("RADIUS",0);
       mapper->SetScalarModeToUsePointFieldData();
       vtkSmartPointer<vtkCubeSource> cubeSource =
             vtkSmartPointer<vtkCubeSource>::New();
           cubeSource.Get()->SetBounds(-0.125, 0.125,-0.125, 0.125, -0.125, 0.125);
           //cubeSource.GetProperty()->SetOpacity(.4);
           // Visualize
           mapper->SetInputConnection(glyph3D->GetOutputPort());
           vtkSmartPointer<vtkPolyDataMapper> Cubemapper =
             vtkSmartPointer<vtkPolyDataMapper>::New();
           Cubemapper->SetInputConnection(cubeSource->GetOutputPort());
           /*vtkSmartPointer<vtkPolyDataMapper> Cylindermapper =
             vtkSmartPointer<vtkPolyDataMapper>::New();
           Cylindermapper->SetInputConnection(cylinderSource->GetOutputPort());
           vtkSmartPointer<vtkActor>Cylinderactor =
                 vtkSmartPointer<vtkActor>::New();
                 Cylinderactor->SetMapper(Cylindermapper);
                 Cylinderactor->GetProperty()->SetOpacity(.4);
*/
           vtkSmartPointer<vtkActor> Cubeactor =
             vtkSmartPointer<vtkActor>::New();
           Cubeactor->GetProperty()->SetOpacity(.2);
            Cubeactor->SetMapper(Cubemapper);
       vtkSmartPointer<vtkActor>Glyphactor =
             vtkSmartPointer<vtkActor>::New();
             Glyphactor->SetMapper(mapper);
           vtkSmartPointer<vtkRenderer> renderer =
             vtkSmartPointer<vtkRenderer>::New();
           vtkSmartPointer<vtkRenderWindow> renderWindow =
             vtkSmartPointer<vtkRenderWindow>::New();
           renderWindow->AddRenderer(renderer);
           vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
             vtkSmartPointer<vtkRenderWindowInteractor>::New();
           renderWindowInteractor->SetRenderWindow(renderWindow);
          renderer->AddActor(Cubeactor);
          // renderer->AddActor(Cylinderactor);
           renderer->AddActor(Glyphactor);
           renderer->SetBackground(255, 255, 255); // Background color green
           renderWindow->Render();
       renderWindowInteractor->Start();

    /// irasome duomenis greiciausiai i VTK faila kaip rezultata.

}
