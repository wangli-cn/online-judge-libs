#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void InsertionSort(vector<int> &a)
{
    int n = a.size();
    int i, j, val;

    for (i = 1; i < n; ++i) {
        val = a[i];
        for (j = i-1; j >= 0 && a[j] > val; --j) {
            a[j+1] = a[j];
        }
        a[j+1] = val;
    }
}

int main(void)
{
    int a[8] = {8, 9, 2, 1, 100, 2, 3, 8};
    vector<int> vec(a, a+8);

    InsertionSort(vec);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
