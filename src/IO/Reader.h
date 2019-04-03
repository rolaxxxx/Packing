#ifndef READER_H
#define READER_H
#include "core/Data.h"

class Reader
{
public:
    Reader();
    void read(Data * data,std::string filename);

};

#endif // READER_H
