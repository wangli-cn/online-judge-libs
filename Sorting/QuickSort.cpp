#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void QuickSort(vector<int> &a, int l, int r)
{
    if (l < r) {
        int p = a[(l+r)/2];
        int i = l-1, j = r+1;
        while (1) {
            while (a[++i] < p);
            while (a[--j] > p);
            if (i >= j) break;
            swap(a[i], a[j]);
        }
        QuickSort(a, l, i-1);
        QuickSort(a, j+1, r);
    }
}

void QuickSort(vector<int> &a) 
{
    QuickSort(a, 0, a.size()-1);     
}


int main(void)
{
    int a[8] = {8, 9, 2, 1, 100, 2, 3, 8};
    vector<int> vec(a, a+8);

    QuickSort(vec);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    return 0;
}

