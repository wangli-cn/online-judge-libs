#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &a)
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
    vector<int> a {8, 9, 2, 1, 100, 2, 3, 8};
    selection_sort(a);

    for (auto elem: a) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
    return 0;
}
