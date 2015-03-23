#include <atomic>

class SharedObject
{
    public:
        SharedObject();

    private:
        mutable std::atomic<int> count;
};

void SharedObject::addReference() const
{
    std::atomic_fetch_add_explicit(&count, 1u, std::memory_order_relaxed);
}

void SharedObject::removeReference() const
{
    if (std::atomic_fetch_sub_explicit(&count, 1u, std::memory_order_release) == 1) {
         std::atomic_thread_fence(boost::memory_order_acquire);
         delete this;
    }
}

int main()
{
    return 0;
}
