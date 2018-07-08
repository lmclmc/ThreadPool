#ifndef MD5CHECK_H
#define MD5CHECK_H

#include <memory>
#include <atomic>

class Md5Check
{
public:
    static Md5Check* getInstance();
    ~Md5Check();

private:
    static std::shared_ptr<Md5Check> pMd5Check;
    Md5Check();

    std::atomic<bool> bStatus;
};

#endif // MD5CHECK_H
