#ifndef WRITER_H
#define WRITER_H
#include "core/Data.h"
#include "core/Constants.h"

class Writer
{
public:
    Writer();
    void write(Data*data,std::string filename);
};

#endif // WRITER_H
