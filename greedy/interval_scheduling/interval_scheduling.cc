#include <iostream>
#include <vector>
#include <algorithm>

class Interval
{
public:
    int s, f;

    explicit Interval(int s, int f) :s(s), f(f) {}
};

std::vector<Interval> IntervalScheduling(std::vector<Interval> J)
{
    std::vector<Interval> A;
    std::sort(J.begin(), J.end(), [&](const Interval &x, const Interval &y) { return x.f < y.f; } );

    int f = 0;
    for (int i = 0; i < J.size(); ++i) {
        if (J[i].s >= f) {
            A.push_back(J[i]);
            f = J[i].f;
        }
    }
    return A;
}

int main(void)
{
    std::vector<Interval> J;

    J.push_back(Interval(1, 10));
    J.push_back(Interval(2, 4));
    J.push_back(Interval(5, 10));
    J.push_back(Interval(9, 12));

    auto &&ans = IntervalScheduling(J);

    for (auto elm: ans) {
        std::cout << elm.s << " " << elm.f << std::endl;
    }
    return 0;
}
