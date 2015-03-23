#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <thread>

class LogFile
{
    std::mutex m_mutex;
    std::ofstream f;

public:
    LogFile() {
        f.open("log.txt");
    }

    void shared_print(std::string id, int value) {
        std::lock_guard<std::mutex> locker(m_mutex);
        f << "From " << id << ": " << value << std::endl;
    }
};

class semaphore
{
    private:
        int v;
        std::mutex m;

    public:
        semaphore(int v) :v(v) {}

        void post()
        {
            m.lock();
            v += 1;
            m.unlock();
        }

        void wait()
        {
            m.lock();
            while (v <= 0) {
                m.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(2));
                m.lock();
            }

            m.unlock();
        }
};

semaphore S(1);

void task1(LogFile &log)
{
    S.wait();
    for (int i = 0; i < 10; i++) {
        log.shared_print(std::string("From t1: "), i);
    }
    S.post();
}

void task2(LogFile &log)
{
    S.wait();
    for (int i = 0; i < 10; i++) {
        log.shared_print(std::string("From t2: "), i);
    }
    S.post();
}


int main()
{
    LogFile log;
    std::thread t1(task1, std::ref(log));
    std::thread t2(task2, std::ref(log));

    t1.join();
    t2.join();

    return 0;
}
