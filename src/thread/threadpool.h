#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <future>

class ThreadPool{
public:
    static ThreadPool* getInstance();

    template <typename F, typename... Args>
    auto addTask(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

    void addThread();

    ThreadPool(const ThreadPool& t) = delete;
    ~ThreadPool();

private:
    static std::shared_ptr<ThreadPool> pThreadPool;
    ThreadPool(int num);

private:
    std::atomic<bool> bStop;
    std::vector<std::thread> vWork;

    std::mutex list_mutex;

    std::condition_variable condition;
    std::list<std::function<void()>> tasks;
};

template <typename F, typename... Args>
auto ThreadPool::addTask(F&& f, Args&&... args)
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
