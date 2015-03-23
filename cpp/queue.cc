#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mu;
std::deque<int> q;
std::condition_variable cond;

void producer()
{
    int count = 10;
    while (count > 0) {
        std::unique_lock<std::mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        cond.notify_one();
        cond.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count -= 1;
    }
}

void consumer()
{
    int data = 0;
    while (data != 1) {
        std::unique_lock<std::mutex> locker(mu);

        cond.wait(locker, [](){return !q.empty();});
        data = q.back();
        q.pop_back();
        locker.unlock();
        std::cout << "t2 got a value from t1: " << data << std::endl;
    }
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
