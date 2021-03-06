#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int> &a, int l, int r)
{
    if (l < r) {
        int p = l + (r-l)/2;
        int i = l-1, j = r+1;

        while (1) {
            while (a[++i] < a[p]);
            while (a[--j] > a[p]);
            if (i >= j) break;
            swap(a[i], a[j]);
        }

        quick_sort(a, l, i-1);
        quick_sort(a, j+1, r);
    }
}

int main()
{
    vector<int> a {6, 5, 4, 3, 2, 1};
    quick_sort(a, 0, 5);

    for (auto elem: a) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
    return 0;
}
