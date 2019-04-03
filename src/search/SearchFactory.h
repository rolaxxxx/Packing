#ifndef SEARCHFACTORY_H
#define SEARCHFACTORY_H
#include "search/ASearch.h"

enum class SearchTypes
{
    Uniform
};

class SearchFactory
{
public:
    SearchFactory();
    ASearch* create(SearchTypes type);
};

#endif // SEARCHFACTORY_H
