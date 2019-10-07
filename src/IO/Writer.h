#ifndef WRITER_H
#define WRITER_H
#include "core/Constants.h"
#include "core/Data.h"
#include "search/SearchUnform.h"

class Writer {
public:
  Writer();
  void write(Data *data, ASearch *search, json duomenys, REAL poringumas);
};

#endif // WRITER_H
