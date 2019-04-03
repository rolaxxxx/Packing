#ifndef WRITER_H
#define WRITER_H
#include "core/Data.h"

class Writer
{
public:
    Writer();
    void write(Data*data,std::string filename);
};

#endif // WRITER_H
