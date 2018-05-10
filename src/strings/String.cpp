#include "String.h"
#include <string.h>

#include <stdio.h>

String::String(int count, char **src):
    mString(src),
    mCount(count)
{

}

bool String::operator == (const char *src)
{
       if (strcmp(mString[1], src) == 0)
       {
           return true;
       }

       return false;
}

char *String::getString()
{
    return *mString;
}
