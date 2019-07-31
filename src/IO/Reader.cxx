#include "Reader.h"

Reader::Reader()
{

}
void Reader::read(Data * data,std::string filename)
{
   /// nuskaitome pradines daleliu duomenis is failo  
   std::string configData;
         std::ifstream t(filename);
         std::string str((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
         configData=str;
         data->setDuomenys(configData);
}
void Reader::readVTK(Data * data,std::string filename)
{

    vtkDataSetReader* reader=vtkDataSetReader::New();
            reader->SetFileName(filename.c_str());
            reader->Update();
             vtkPoints * trianglePoints = vtkPoints::New();
            vtkSmartPointer<vtkTriangle> triangle =
              vtkSmartPointer<vtkTriangle>::New();
            vtkSmartPointer<vtkCellArray> triangles =
              vtkSmartPointer<vtkCellArray>::New();
            vtkSmartPointer<vtkPolyData> trianglePolyData =
              vtkSmartPointer<vtkPolyData>::New();

        int tasku_kiekis=reader->GetOutput()->GetNumberOfPoints();

      for(int i=0;i<tasku_kiekis*3;i+=3){
          double  p[4];
          int pid1 = i;
          int pid2 = i + 1;
          int pid3 = i + 2;


        reader->GetOutput()->GetPoint(i,p);
        trianglePoints->InsertPoint( pid1, p[0], p[1], p[2] );

        reader->GetOutput()->GetPoint(i,p);
        trianglePoints->InsertPoint(pid2, p[0], p[1], p[2]);

        reader->GetOutput()->GetPoint(i,p);
        trianglePoints->InsertPoint(pid3, p[0], p[1], p[2]);


        triangle->GetPointIds()->SetId ( 0, pid1 );
        triangle->GetPointIds()->SetId ( 0, pid2 );
        triangle->GetPointIds()->SetId ( 0, pid3 );

        triangles->InsertNextCell ( triangle );

        trianglePolyData->SetPoints (trianglePoints);

        trianglePolyData->SetPolys ( triangles );
      }


}
