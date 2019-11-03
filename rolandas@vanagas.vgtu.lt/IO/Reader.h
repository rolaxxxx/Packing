#ifndef READER_H
#define READER_H
#include "core/Constants.h"
#include "core/Data.h"
#include "search/ASearch.h"
class Reader {
public:
  Reader();
  void read(Data *data, std::string filename);
  void readVTK(ASearch *search, std::string filename);
};

#endif // READER_H
