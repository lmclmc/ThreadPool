#include "md5check.h"

#include <iostream>

Md5Check *Md5Check::getInstance()
{
    if (pMd5Check == nullptr){
        pMd5Check = (std::shared_ptr<Md5Check>)new Md5Check;
    }

    return pMd5Check.get();
}

Md5Check::Md5Check()
{
    bStatus = true;
    std::cout<<"open"<<std::endl;
}

Md5Check::~Md5Check()
{
    if (pMd5Check == nullptr){
        return;
    }
    std::cout<<"close"<<std::endl;
}

std::shared_ptr<Md5Check> Md5Check::pMd5Check = nullptr;
