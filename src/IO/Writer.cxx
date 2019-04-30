#include "Writer.h"
using namespace std;
Writer::Writer()
{

}

void Writer::write(Data*data, ASearch *search, std::string filename)
{

         vtkSmartPointer<vtkDoubleArray> radius =
         vtkSmartPointer<vtkDoubleArray>::New();

         vtkSmartPointer<vtkPoints> points =
         vtkSmartPointer<vtkPoints>::New();


    radius->SetName("RADIUS");

         PointType tempDalele;
        for(INT i=0;i<data->getNumberOfPoints();i++)
        {
             tempDalele=data->getPoint(i);
             //cout << tempDalele << endl;
             points->InsertNextPoint(tempDalele.x,tempDalele.y, tempDalele.z);
             radius->InsertNextTuple1(tempDalele.R);
            // cout<< tempDalele.x << " " << tempDalele.y << " " << tempDalele.z << " " << tempDalele.R << endl;
        }


        vtkSmartPointer<vtkPolyData> polydata =
              vtkSmartPointer<vtkPolyData>::New();
            polydata->SetPoints(points);
          polydata->GetPointData()->SetScalars(radius);
            vtkSmartPointer<vtkPolyData> glyph =
        vtkSmartPointer<vtkPolyData>::New();

            vtkSmartPointer<vtkSphereSource> SphereSource =
          vtkSmartPointer<vtkSphereSource>::New();

        SphereSource->SetPhiResolution(4);
         SphereSource->SetRadius(1); //radius visada vienas kai atvaizduoju sferas //reikia pakeisti/////
     SphereSource->SetThetaResolution(4);
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
           cubeSource.Get()->SetBounds(-15,15,-15,15,-15, 15);
           //cubeSource.GetProperty()->SetOpacity(.4);
           // Visualize

           mapper->SetInputConnection(glyph3D->GetOutputPort());


           vtkSmartPointer<vtkPolyDataMapper> Cubemapper =
             vtkSmartPointer<vtkPolyDataMapper>::New();
           Cubemapper->SetInputConnection(cubeSource->GetOutputPort());

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
           renderer->AddActor(Glyphactor);
           renderer->SetBackground(255, 255, 255); // Background color green

           renderWindow->Render();
       renderWindowInteractor->Start();

    /// irasome duomenis greiciausiai i VTK faila kaip rezultata.
}
