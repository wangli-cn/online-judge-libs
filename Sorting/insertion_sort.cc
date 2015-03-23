#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &a)
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

int main()
{
    vector<int> a {8, 9, 2, 1, 100, 2, 3, 8};
    insertion_sort(a);

    for (auto elem: a) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
    return 0;
}
