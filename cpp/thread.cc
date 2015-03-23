#include <mutex>
#include <thread>


struct BoundedBuffer
{
    int *buffer;
    int capacity;

    int front;
    int rear;
    int count;

    std::mutex lock;
    std::condition_variable not_full;
    std::condition_variable not_empty;

    BoundedBuffer(int capacity) :capacity(capacity), front(0), rear(0), count(0) {
        buffer = new int[capacity];
    }

    ~BoundedBuffer() {
        delete [] buffer;
    }

    void deposit(int data) {
        std::unique_lock<std::mutex> l(lock);

        not_full.wait(l, [&count, &capacity](){ return count != capacity; });

        buffer[rear] = data;
        rear = (rear + 1) % capacity;
        count += 1;

        not_empty.notify_one();
    }

    int fetch() {
        std::unique_lock<std::mutex> l(lock);

        not_empty.wait(l, [&count](){return count != 0;});

        int result = buffer[front];
        front = (front + 1) % capacity;
        count -= 1;
        not_full.notify_one();
        return result;
    }
};

int main()
{
    return 0;
}
