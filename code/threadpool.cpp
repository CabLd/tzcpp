#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<string>
#include<vector>
#include<functional>
using namespace std;

class ThreadPool {
public:
    //构造函数
    ThreadPool(int numThreads) :stop(false) {
        for(int i = 0; i < numThreads; ++i) {
            threads.emplace_back([this] {
                while(1) {
                    //取任务
                    std::unique_lock<std::mutex> lock(mtx); //共享部分加锁
                    //条件变量 防止任务空掉
                    condition.wait(lock, [this]{
                        return !tasks.empty() || stop;
                    });
                    //停止信号 并且将任务队列的任务完成才能结束
                    if(stop && tasks.empty()) {
                        return;
                    }
                    //function将任务包装进来
                    std::function<void()> task(std::move(tasks.front()));
                    tasks.pop();
                    lock.unlock();
                    task();
                }
            });
        }
    }
    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(mtx);
            stop = true;
        }
        condition.notify_all();
        for(auto& t : threads) {
            t.join();
        }
    }
    //添加任务
    template<typename F, typename... Args>
    void enqueue(F&& f, Args&&... args) {
        std::function<void()> task(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        {
            std::unique_lock<std::mutex> lock(mutex);
            tasks.emplace(std::move(task));
        }
        condition.notify_one();
    }

private:
    //线程数组
    std::vector<std::thread> threads;
    //任务队列
    std::queue<std::function<void()> > tasks;

    std::mutex mtx; //互斥锁
    std::condition_variable condition; 

    bool stop; //表示线程池什么时候终止

};
int main() {
    ThreadPool pool(4);
    for (int i = 0; i < 8; ++i) {
        pool.enqueue([i] {
            std::cout << "Task " << i << " is running in thread " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Task " << i << " is done" << std::endl;
        });
    }
    return 0;
}
