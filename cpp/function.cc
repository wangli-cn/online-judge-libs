#include <functional>

float calc(std::function<float(float)> f) { return -1.0f * f(3.3f) + 666.0f; }

int main()
{
    float result = 0;
    for (int i = 0; i < 100000000; ++i) {
        result += calc([](float arg) { return arg * 0.5f; });
    }
}
