#include <iostream>
#include <vector>

void merge_sort(std::vector<int> &a)
{
    const int n = a.size();

    if (n > 1) {
        std::vector<int> b(a.begin(), a.begin() + n/2);
        std::vector<int> c(a.begin() + n/2, a.end());

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


void inplace_merge(std::vector<int> &a, int i, int m, int j)
{
    std::vector<int> b(a.begin()+i, a.begin()+m+1);
    std::vector<int> c(a.begin()+m+1, a.begin()+j+1);

    for (int p = i, q = 0, r = 0; p <= j; p++) {
        if (r == c.size()) a[p] = b[q++];
        else if (q == b.size()) a[p] = c[r++];
        else if (b[q] < c[r]) a[p] = b[q++];
        else a[p] = c[r++];
    }
}


void inplace_merge_sort(std::vector<int> &a, int i, int j)
{
    if (i < j) {
        int m = (i+j) / 2;
        inplace_merge_sort(a, i, m);
        inplace_merge_sort(a, m+1, j);
        inplace_merge(a, i, m+1, j);
    }
}


int main()
{
    std::vector<int> a { 6, 5, 4, 3, 2, 1 };
    merge_sort(a);
    for (auto elem: a) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
    return 0;
}
