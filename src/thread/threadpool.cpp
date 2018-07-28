#include "threadpool.h"

ThreadPool *ThreadPool::getInstance()
{
    if (pThreadPool == nullptr)
        pThreadPool = (std::shared_ptr<ThreadPool>)new ThreadPool(8);
    return pThreadPool.get();
}

ThreadPool::ThreadPool(int num)
{
    for (int i=0; i<num; i++){
        vWork.push_back(std::thread([this]{
            std::mutex localMutex;
            std::unique_lock<std::mutex> localLock(localMutex);
            for (;;){
                this->condition.wait(localLock, [this]{
                    return !this->tasks.empty();});

                this->list_mutex.lock();
                if (this->tasks.size() <= 0){
                    this->list_mutex.unlock();
                    continue;
                }

                auto tmpTask = this->tasks.front();
                this->tasks.erase(this->tasks.begin());
                this->list_mutex.unlock();
                tmpTask();
            }
        }));
    }
    std::cout<<"ThreadPool init successful"<<std::endl;
}

ThreadPool::~ThreadPool()
{
    std::cout<<"ThreadPool destory successful"<<std::endl;
}

std::shared_ptr<ThreadPool> ThreadPool::pThreadPool = nullptr;


