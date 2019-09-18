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
inline float TriArea2D(float x1, float y1, float x2, float y2, float x3, float y3)
{
return (x1-x2)*(y2-y3) - (x2-x3)*(y1-y2);
}
// Compute barycentric coordinates (u, v, w) for
// point p with respect to triangle (a, b, c)
void Barycentric(Point a, Point b, Point c, Point p, float &u, float &v, float &w)
{
// Unnormalized triangle normal
				Point m = cross_prod(b - a, c - a);
				// Nominators and one-over-denominator for u and v ratios
				float nu, nv, ood;
				// Absolute components for determining projection plane
				float x = abs(m.x), y = abs(m.y), z = abs(m.z);
				// Compute areas in plane of largest projection
				if (x >= y && x >= z) {
				// x is largest, project to the yz plane
				nu = TriArea2D(p.y, p.z, b.y, b.z, c.y, c.z); // Area of PBC in yz plane
				nv = TriArea2D(p.y, p.z, c.y, c.z, a.y, a.z); // Area of PCA in yz plane
				ood = 1.0f / m.x; // 1/(2*area of ABC in yz plane)

				

				} else if (y >= x && y >= z) {
				// y is largest, project to the xz plane
				nu = TriArea2D(p.x, p.z, b.x, b.z, c.x, c.z);
				nv = TriArea2D(p.x, p.z, c.x, c.z, a.x, a.z);
				ood = 1.0f / -m.y;
				} else {
				// z is largest, project to the xy plane
				nu = TriArea2D(p.x, p.y, b.x, b.y, c.x, c.y);
				nv = TriArea2D(p.x, p.y, c.x, c.y, a.x, a.y);
				ood = 1.0f / m.z;
				}
				u = nu * ood;
				v = nv * ood;
				w = 1.0f - u - v;
}
int Mesh::PointInTriangle(Point p, Point a, Point b, Point c)
{
								// Translate point and triangle so that point lies at origin

			float u, v, w;
			Barycentric(a, b, c, p, u, v, w);
			return v >= 0.0f && w >= 0.0f && (v + w) <= 1.0f;

				

}
int Mesh::IntersectLineTriangle(Point p, Point q, Point a, Point b, Point c)
                                    {
    float u, v, w, t;
	
	
	
	Point r;
    Point ab = b - a;
			Point ac = c - a;
			Point qp = p - q;
			Point pq = q - p;
			Point pa = a - p;
			Point pb = b - p;
			Point pc = c - p;
			// Compute triangle normal. Can be precalculated or cached if
			// intersecting multiple segments against the same triangle
			Point n = cross_prod(ab, ac);
			// Compute denominator d. If d <= 0, segment is parallel to or points
			// away from triangle, so exit early
			float d = dot_prod(qp, n);
			if (d <= 0.0f) return 0;
			// Compute intersection t value of pq with plane of triangle. A ray
			// intersects iff 0 <= t. Segment intersects iff 0 <= t <= 1. Delay
			// dividing by d until intersection has been found to pierce triangle

			Point ap = p - a;
			t = dot_prod(ap, n);
			
			if (t < 0.0f) return 0;
			if (t > d) return 0; // For segment; exclude this code line for a ray test
			// Compute barycentric coordinate components and test if within bounds
			if(t<0&& t>1)
				return 0;
			
			Point e = cross_prod(qp, ap);
			v = dot_prod(ac, e);
			if (v < 0.0f || v > d) return 0;
			w = -dot_prod(ab, e);
			if (w < 0.0f || v + w > d) return 0;
			// Segment/ray intersects triangle. Perform delayed division and
			// compute the last barycentric coordinate component
			float ood = 1.0f / d;
			t *= ood;
			v *= ood;
			w *= ood;
			u = 1.0f - v - w;
			
			
				
				
			r = u*a + v*b + w*c;
			if(PointInTriangle(r,  a, b, c))
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
		//q.PrintStructure();
        //cout << " ribu reiksmes " << bounds[0] << " " << bounds[1] << " " << bounds[2] << " " << bounds[3] << " " << bounds[4] << " " << bounds[5] << endl;
       // newSphere.PrintStructure();
        //std::cout << "tikrinamas taskas " << endl;
      // Timer timer;
       //double rezultatai;
      // timer.StartTimer();
        for(int i=0, j=0;i<tria_kiekis;i++, j+=3){
           // cout << j <<"-------------- j reiksme " << " ---- ---- i reiksme >>> " << i <<  endl;
            if(newSphere.x+newSphere.R<bounds[1]&& newSphere.x-newSphere.R>bounds[0]&& newSphere.y+newSphere.R<bounds[3]&& newSphere.y-newSphere.R>bounds[2]&& newSphere.z+newSphere.R<bounds[5]&& newSphere.z-newSphere.R>bounds[4]){

               
                //taskai[j].PrintStructure();
				
				
               if(IntersectLineTriangle(newSphere, q, taskai[j+2], taskai[j+1], taskai[j])){
                count++;
            }
			    if(IntersectLineTriangle(newSphere, q, taskai[j], taskai[j+1], taskai[j+2])){
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
            count++;s
        }
        */
        //cout << count << " susikirtimu skaicius naujam suskaiciuotam taskui " << endl;
        //cout << "daleles reiksme ======" << endl;
        //newSphere.PrintStructure();
        //cout << "daleles reiksme ===== " << endl;
        //cout << "susikirtimu reiksme ===== " << count << " =========" <<  endl;


        if(count%2!=0)
		{
			
			//cout << " susikirtimu skaicius " << count << endl;
			//cout << "sfera kuri praeis" << endl;
			//newSphere.PrintStructure();
			return 1;
				
	
		}
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
