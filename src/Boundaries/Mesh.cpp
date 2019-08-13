#include "Mesh.h"

Mesh::Mesh(){
    
}
bool Mesh::check(Point newSphere){

Point a, b, c;

    for(int i=0;i<trianglePolyData->GetNumberOfPoints()*3;i+=3){
        double p[3];
        trianglePolyData->GetPoint(i, p);
        a.x=p[0];
        a.y=p[1];
        a.z=p[2];
        trianglePolyData->GetPoint(i, p);
        b.x=p[0];
        b.y=p[1];
        b.z=p[2];
        trianglePolyData->GetPoint(i, p);
        c.x=p[0];
        c.y=p[1];
        c.z=p[2];

        a =a - newSphere;
        b =b - newSphere;
        c =c - newSphere;
        float ab = dot_prod(a, b);
        float ac = dot_prod(a, c);
        float bc = dot_prod(b, c);
        float cc = dot_prod(c, c);
        // Make sure plane normals for pab and pbc point in the same direction
        if (((bc * ac) - (cc * ab)) < 0.0f)
            return 0;
        // Make sure plane normals for pab and pca point in the same direction
        float bb = dot_prod(b, b);
        if (((ab * bc) - (ac * bb)) < 0.0f) return false;
        // Otherwise P must be in (or on) the triangle
        return true;
    }
}



void Mesh::initialization(json duomenys){

    std::string filename=duomenys["MESH"]["FILENAME"];
    vtkDataSetReader* reader=vtkDataSetReader::New();
            reader->SetFileName(filename.c_str());
            reader->Update();


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
