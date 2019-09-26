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
void Reader::readVTK(ASearch * search, std::string filename){


    vtkSmartPointer<vtkDataSetReader> reader=vtkSmartPointer<vtkDataSetReader>::New();
            reader->SetFileName(filename.c_str());
            reader->Update();

        double p[3];
        Point insert;
        for(int i=0;i<reader->GetOutput()->GetNumberOfPoints();i++){
            reader->GetOutput()->GetPoint(i,p);

            insert.x=p[0];
            insert.y=p[1];
            insert.z=p[2];

            insert.R=reader->GetOutput()->GetPointData()->GetArray("RADIUS")->GetTuple1(i);
            //insert.PrintStructure();
            search->addPoint(insert);

        }
}
