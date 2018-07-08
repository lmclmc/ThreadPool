#include "global.h"
#include "string.h"

#include <iostream>

using namespace std;

Global::Global(int argc, char *argv[]):
    mArgc(argc),
    mArgv(argc, argv)
{

}

int Global::exec()
{
    if (mArgc < 2){
        cout<<"Too little input parameters"<<endl;
        return 0;
    }

    if (mArgv == "--help"){
        cout<<"this is a console application"<<endl;
        cout<<"input parameter:"<<endl;
        cout<<"    --help:  Lookup usage"<<endl;

        return 0;
    }

}
