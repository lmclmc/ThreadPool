#include <stdio.h>

#include "src/global.h"
#include "src/check/md5check.h"

int main(int argc, char *argv[]){
    Md5Check *m = Md5Check::getInstance();

    Global g(argc, argv);

    return g.exec();
}
