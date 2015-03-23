#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &a)
{
    const int n = a.size();

    if (n > 1) {
        vector<int> b(a.begin(), a.begin() + n/2);
        vector<int> c(a.begin() + n/2, a.end());

        merge_sort(b);
        merge_sort(c);

        for (int i = 0, j = 0, k = 0; i < n; i++) {
            if (k == c.size()) a[i] = b[j++];
            else if (j == b.size()) a[i] = c[k++];
            else if (b[j] < c[k]) a[i] = b[j++];
            else a[i] = c[k++];
        }
    }
}

int main()
{
    vector<int> a { 6, 5, 4, 3, 2, 1 };
    merge_sort(a);
    for (auto i: a) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}
