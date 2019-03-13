#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <future>

#ifdef SPIN_MUTEX 
    #define MUTEX_TYPE SpinMutex
#endif

#ifdef MUTEX 
    #define MUTEX_TYPE std::mutex	
#endif	

class SpinMutex {
    std::atomic<bool> flag = ATOMIC_VAR_INIT(false);
public:
    SpinMutex() = default;
    SpinMutex(const SpinMutex&) = delete;
    SpinMutex& operator= (const SpinMutex&) = delete;
    void lock();
    void unlock();
};

class ThreadPool final{
public:
    static ThreadPool *getInstance();

    template <typename F, typename... Args>
    auto addTask(F&& f, Args&&... args) throw() -> std::future<typename std::result_of<F(Args...)>::type>;

    void addThread() throw();

    ThreadPool(const ThreadPool& t) = delete;
    void destoryPool() throw(); 

private:
    static ThreadPool *pThreadPool;
    ThreadPool() = default;
    ~ThreadPool();

private:
    std::atomic<bool> bStop;
    std::vector<std::thread> vWork;

    MUTEX_TYPE list_mutex;

    std::condition_variable condition;
    std::list<std::function<void()>> tasks;
};

template <typename F, typename... Args>
auto ThreadPool::addTask(F&& f, Args&&... args) throw()
-> std::future<typename std::result_of<F(Args...)>::type>{
    using returnType = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<returnType()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::future<returnType> returnRes = task.get()->get_future();
    list_mutex.lock();
    tasks.push_back([task]{(*task)();});
    list_mutex.unlock();
    condition.notify_one();

    return returnRes;
}

#endif // THREADPOOL_H
