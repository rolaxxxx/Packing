#include "RandomFactory.h"
#include "random/RandomDiscrete.h"
#include "random/RandomUniform.h"

RandomFactory::RandomFactory() {}

ARandom *RandomFactory::create(std::string type) {
  if (type == "Uniform") {
    return new RandomUniform();
  } else if (type == "Discrete") {
    return new RandomDiscrete();
  }
  std::cerr << "Klaida tokio modulio nera!!!\n";
  exit(1000);
}
