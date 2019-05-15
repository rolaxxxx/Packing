#ifndef WRITER_H
#define WRITER_H
#include "core/Data.h"
#include "core/Constants.h"
#include "search/SearchUnform.h"

class Writer
{
public:
    Writer();
    void write(Data*data, ASearch *search, std::vector<REAL> intervals, std::vector<REAL> probabilities, std::string filename);
};

#endif // WRITER_H
