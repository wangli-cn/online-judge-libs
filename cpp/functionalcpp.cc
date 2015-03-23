#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct accumulator {
    int operator()(int oldval, int newval) const {
        return oldval + 2*newval;
    }
};

int main()
{
    vector<int> v {1, 2, 3, 4, 5, 6, 7};

    int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());
    int sum = accumulate(v.begin(), v.end(), 0);
    int formula = accumulate(v.begin(), v.end(), 0, accumulator());
    int formula2 = accumulate(v.begin(), v.end(), 0, [](int oldval, int newval) { return oldval - 3*newval;});

    cout << product << endl;
    cout << sum << endl;
    cout << formula << endl;
    cout << formula2 << endl;
}
