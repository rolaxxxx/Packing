    #include "SpherePackingAlgorithm.h"

    using namespace std;
    SpherePackingAlgorithm::SpherePackingAlgorithm() {}
    void SpherePackingAlgorithm::pack() {
      INT temp;
      std::random_device
          rd; // Will be used to obtain a seed for the random number engine
      std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
      Timer time;
      int i = 0;

      PointType pasirinkta_dalele;

      double isvedimas = amount_particles;

      double new_R = random->getNextValue();
      do {   
          if(rand_gen_every_iteration=="true"){
                 new_R = random->getNextValue();
          }

        int dydis = F.size();
        if (isvedimas < 0&& rez_switch=="true") {
          writer->write(data, search, duomenys,
                        data->getParticle_turis() / bounds->getTuris());
          isvedimas = amount_particles;
        }


        std::uniform_int_distribution<> dis(0, F.size() - 1);
        INT rand_particle_index_f_index = dis(gen);
        INT rand_particle_index = F[rand_particle_index_f_index];


        vector<INT> neighbours = search->getGridNeigbours(rand_particle_index);
        pasirinkta_dalele = data->getPoint(rand_particle_index);

        for (int t = 0; t < neighbours.size(); t++) {
          if (vector_len(pasirinkta_dalele - data->getPoint(neighbours[t])) >
              pasirinkta_dalele.R + data->getPoint(neighbours[t]).R +
                  2 * pasirinkta_dalele.R) // galima pakeisti i tam tikros daleles
            neighbours.erase(neighbours.begin() + t);
        }

        pasirinkta_dalele.koordinacinis_num = neighbours.size();

        temp = rand_particle_index;
        int check = i;

        for (INT j = 0; j < neighbours.size() - 1; j++) {
          for (INT l = j + 1; l < neighbours.size(); l++) {

            PointsArrayType newSphere =
                this->math.getSpheresTouchingThreeOtherSpheres(
                    data->getPoint(neighbours[j]), data->getPoint(neighbours[l]),
                    data->getPoint(rand_particle_index), new_R);

            for (int z = 0; z < newSphere.size(); z++) {

              if (newSphere[z].R != 0) {
				  if(search->check_sphere_touch(data->getPoint(neighbours[j]), data->getPoint(neighbours[l]), data->getPoint(rand_particle_index), newSphere[z])){
                if (!search->intersect(newSphere[z], neighbours)) {

                  if (bounds->check(newSphere[z])) {
                    search->addPoint(newSphere[z]);
                    F.push_back(data->getNumberOfPoints() - 1);
                    i++;
                    if(rand_gen_every_iteration=="false"){
                    new_R = random->getNextValue();
                    }
                    isvedimas--;
                  }
                }
				  }
              }
            }
          }
        }

        if (check == i) {

          remove(F.begin(), F.end(), rand_particle_index);
          F.pop_back();
        }

        std::cout << "viso daleliu " << data->getNumberOfPoints() << "\n";
        std::cout << "poringumas " << data->getParticle_turis() / bounds->getTuris()
                  << endl;
      } while (F.size());

      std::cout << "packing done\n";
      data->setPack_done(true);
    }

    void SpherePackingAlgorithm::initialization() {
      for (int i = 0; i < data->getNumberOfPoints(); i++) {
        F.push_back(i);
      }
      std::cout << "Performing initialization\n";
    }

