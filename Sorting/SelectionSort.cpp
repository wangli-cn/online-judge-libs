#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void SelectionSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        int idx = i;
        for (int j = i+1; j < n; ++j) {
            if (a[j] < a[idx])
                idx = j;
        }

        if (i != idx) 
            swap(a[i], a[idx]);
    }
}

int main(void)
{
    int a[8] = {8, 9, 2, 1, 100, 2, 3, 8};
    vector<int> vec(a, a+8);

    SelectionSort(vec);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
