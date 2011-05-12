#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int s, f;
    Interval(int s, int f)
        :s(s), f(f) {}
};

bool compare_f(const Interval &x, const Interval &y)
{
    return x.f < y.f;
}

vector<Interval> IntervalScheduling(vector<Interval> J)
{
    vector<Interval> A;
    sort(J.begin(), J.end(), compare_f);
    
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
    return 0;
}
