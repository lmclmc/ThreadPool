#include "threadpool.h"

ThreadPool *ThreadPool::getInstance()
{
    if (pThreadPool == nullptr)
        pThreadPool = (std::shared_ptr<ThreadPool>)new ThreadPool(3);
    return pThreadPool.get();
}

ThreadPool::ThreadPool(int num):
    bStop(false)
{
    for (int i=0; i<num; i++){
        addThread();
    }
    std::cout<<"ThreadPool init successful"<<std::endl;
}

void ThreadPool::addThread()
{
    vWork.push_back(std::thread([this]{
        std::mutex localMutex;
        std::unique_lock<std::mutex> localLock(localMutex);
        for (;;){
            if (bStop)
                break;

            this->condition.wait(localLock, [this]{
                return bStop || !this->tasks.empty();});

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
        std::cout<<"des"<<std::endl;
    }));
}

ThreadPool::~ThreadPool()
{
    bStop = true;

    list_mutex.lock();
    tasks.clear();
    list_mutex.unlock();

    for (auto& tmpWork : vWork){
        for (auto& tmp : vWork){
            condition.notify_one();
        }
        tmpWork.join();
    }

    std::cout<<"ThreadPool destory successful"<<std::endl;
}

std::shared_ptr<ThreadPool> ThreadPool::pThreadPool = nullptr;


