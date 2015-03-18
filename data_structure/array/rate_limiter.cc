#include <thread>
#include <chrono>

using namespace std::chrono;

double rate = 5.0;
double per = 8.0;
double allowance = rate;
system_clock::time_point last_check = system_clock::now();

void discard()
{

}

void forward()
{

}

void message_receive_callback()
{
    system_clock::time_point curr = system_clock::now();
    system_clock::duration time_passed = duration_cast<std::chrono::seconds>(curr - last_check);

    allowance += time_passed.count() * (rate / per);
    if (allowance > rate) {
        allowance = rate;
    }

    if (allowance < 1.0) {
        discard();
    } else {
        forward();
        allowance -= 1.0;
    }
}

int main()
{
    for (int i = 1; i < 20; i++) {
        message_receive_callback();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
