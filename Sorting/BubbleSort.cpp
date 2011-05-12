#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

void BubbleSort(vector<int> &a)
{
    int n = a.size();
    bool swapped;
    do {
        swapped = false;
        n -= 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main(void)
{
    int a[8] = {7, 507, 4999, 4000, 4, 1, 3, 100};

    vector<int> vec(a, a+8);
    BubbleSort(vec);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
