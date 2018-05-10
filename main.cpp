#include <stdio.h>

#include "src/global.h"

int main(int argc, char *argv[]){
    Global g(argc, argv);

    return g.exec();
}
