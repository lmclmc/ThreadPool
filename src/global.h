#ifndef GLOBAL_H
#define GLOBAL_H

#include "strings/String.h"

class Global
{
public:
    Global(int argc, char *argv[]);

    int exec();

private:
    int mArgc;
    String mArgv;
};

#endif // GLOBAL_H
