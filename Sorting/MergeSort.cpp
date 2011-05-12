#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void MergeSort(vector<int> &a)
{
    int n = a.size();
    if (n > 1) {
        vector<int> b(a.begin(), a.begin() + n/2);
        vector<int> c(a.begin() + n/2, a.end());
        MergeSort(b);
        MergeSort(c);
        for (int i = 0, j = 0, k = 0; i < n; ++i) {
            if (k == c.size()) a[i] = b[j++];
            else if (j == b.size()) a[i] = c[k++];
            else if (b[j] < c[k]) a[i] = b[j++];
            else a[i] = c[k++];
        }
    }
}

int main(void)
{
    int a[8] = {999, 998, 100, 19, 8, 420, 0, 1};
    vector<int> vec(a, a+8);

    MergeSort(vec);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
