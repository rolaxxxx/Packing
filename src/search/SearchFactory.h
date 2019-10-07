#ifndef SEARCHFACTORY_H
#define SEARCHFACTORY_H
#include "search/ASearch.h"

class SearchFactory {
public:
  SearchFactory();
  ASearch *create(std::string type);
};

#endif // SEARCHFACTORY_H
