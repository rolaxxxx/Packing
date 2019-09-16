#include "Mesh.h"

Mesh::Mesh(){
    
}
// Given segment pq and triangle abc, returns whether segment intersects
// triangle and if so, also returns the barycentric coordinates (u,v,w)
// of the intersection point
bool Mesh::SameSign(int x, int y)
{
    return (x >= 0) ^ (y < 0);
}
int Mesh::PointInTriangle(Point p, Point a, Point b, Point c)
{


/*
                float pab = cross2D(p – a, b – a);
                float pbc = cross2D(p – b, c – b);

                // If P left of one of AB and BC and right of the other, not inside triangle
                if (!SameSign(pab, pbc)) return 0;
                float pca = cross2D(p – c, a – c);
                // If P left of one of AB and CA and right of the other, not inside triangle
                if (!SameSign(pab, pca)) return 0;
                // P left or right of all edges, so must be in (or on) the triangle
                return 1;
                */
}
int Mesh::IntersectLineTriangle(Point p, Point q, Point a, Point b, Point c)
                                    {
    float u, v, w, t;
    Point r;
    Point pq = q - p;
    Point pa = a - p;
    Point pb = b - p;
    Point pc = c - p;
    // Test if pq is inside the edges bc, ca and ab. Done by testing
    // that the signed tetrahedral volumes, computed using scalar triple
    // products, are all positive
    u = tripleScalarProd(pq, pc, pb);
    if (u < 0.0f) return 0;
    v = tripleScalarProd(pq, pa, pc);
    if (v < 0.0f) return 0;
    w = tripleScalarProd(pq, pb, pa);
    if (w < 0.0f) return 0;
    // Compute the barycentric coordinates (u, v, w) determining the
    // intersection point r, r = u*a + v*b + w*c
    float denom = 1.0f / (u + v + w);
    u *= denom;
    v *= denom;
    w *= denom;
    // w = 1.0f - u - v;
    r=u*a + v*b + w*c;

    // w = 1.0f - u - v;
    if(PointInTriangle(r, a, b, c))
        return 1;
    else return 0;



}
bool Mesh::check(Point newSphere){

        float u, v, w;
        float t;
        int count=0;
        // naudoti paprastus masyvus
        int susikirtimu_skaicius;
        Point q,a;
        q.x=bounds[1]+(bounds[1]/2);
        q.y=bounds[3]+(bounds[3]/2);
        q.z=bounds[5]+(bounds[5]/2);
        //cout << " ribu reiksmes " << bounds[0] << " " << bounds[1] << " " << bounds[2] << " " << bounds[3] << " " << bounds[4] << " " << bounds[5] << endl;
       // newSphere.PrintStructure();
        //std::cout << "tikrinamas taskas " << endl;
      // Timer timer;
       //double rezultatai;
      // timer.StartTimer();
        for(int i=0, j=0;i<tria_kiekis;i++, j+=3){
           // cout << j <<"-------------- j reiksme " << " ---- ---- i reiksme >>> " << i <<  endl;
            if(newSphere.x+newSphere.R<bounds[1]&& newSphere.x-newSphere.R>bounds[0]&& newSphere.y+newSphere.R<bounds[3]&& newSphere.y+newSphere.R>bounds[2]&& newSphere.z+newSphere.R<bounds[5]&& newSphere.z-newSphere.R>bounds[4]){

                //cout << "trikampis paziureti jo x y z reiksmes =====" << endl;
                //taskai[j].PrintStructure();

                if(IntersectLineTriangle(newSphere, q, taskai[j], taskai[j+1], taskai[j+2])&& newSphere.x<bounds[1]&& newSphere.x>bounds[0]&& newSphere.y<bounds[3]&& newSphere.y>bounds[2]&& newSphere.z<bounds[5]&& newSphere.z>bounds[4]){
                count++;
            }
            }

        }

       // cout << "daleles patikra baigta -------" << endl;
        //cout << "newSphere taskas ir susikirtimai " << count << " ";
      // newSphere.PrintStructure();
        //cout <<"----------" <<  endl;
        //timer.StopTimer();
        //rez+=timer.ElapsedTime("sec");
        //cout << rez<< " boundaries check laikas  " << endl;
       /* if(newSphere.x<bounds[0]||newSphere.x>bounds[1]||newSphere.y<bounds[2]||newSphere.y>bounds[3]||newSphere.z<bounds[4]||newSphere.z>bounds[5]&&count==1)
        {
           newSphere.PrintStructure();
           cout << "neigiama dalele su vienu kirtimu " << endl;
            count++;
        }
        */
        //cout << count << " susikirtimu skaicius naujam suskaiciuotam taskui " << endl;
        //cout << "daleles reiksme ======" << endl;
        //newSphere.PrintStructure();
        //cout << "daleles reiksme ===== " << endl;
        //cout << "susikirtimu reiksme ===== " << count << " =========" <<  endl;


        if(count%2!=0)
            return 1;
        else return 0;
}
// susikirtimu skaiciavimas su tiese per erdve

void Mesh::initialization(json duomenys){

    std::string filename=duomenys["MESH"]["FILENAME"];
    vtkDataSetReader* reader=vtkDataSetReader::New();
            reader->SetFileName(filename.c_str());
            reader->Update();

            bounds=reader->GetOutput()->GetBounds();

        //int tasku_kiekis=reader->GetOutput()->GetNumberOfPoints();
        tria_kiekis=reader->GetOutput()->GetNumberOfCells();
       //cout << tria_kiekis << "---------- trikampiu kiekis " << endl;
        double p[3];

        int pid1;
        int pid2;
        int pid3;
        //std::vector<REAL4> kruptis(tria_kikeis); galbut naudosiu per vtk susitvakryt
        //cout << "trikampiu kiekis----------- " << endl;
        for(int i=0;i<tria_kiekis;i++){
            //gauname cele kuri saugo i Pointo sujungimus
            vtkCell*cell=reader->GetOutput()->GetCell(i);
            //cout << cell->GetPointIds()->GetNumberOfIds() << endl;
            if(cell->GetPointIds()->GetNumberOfIds()==3){
                         pid1=cell->GetPointId(0);
                         pid2=cell->GetPointId(1);
                         pid3=cell->GetPointId(2);

          //  cout << pid1 << " " << pid2 <<  " " << pid3 << " pid reiksmes is eiles pagal trikampi " << endl;

            Point temp;
            reader->GetOutput()->GetPoint(pid1,p);
            temp.x=p[0];
            temp.y=p[1];
            temp.z=p[2];

            taskai.push_back(temp);

            reader->GetOutput()->GetPoint(pid2,p);
            temp.x=p[0];
            temp.y=p[1];
            temp.z=p[2];

            taskai.push_back(temp);
            reader->GetOutput()->GetPoint(pid3,p);
            temp.x=p[0];
            temp.y=p[1];
            temp.z=p[2];

            taskai.push_back(temp);
}
         }

      }
