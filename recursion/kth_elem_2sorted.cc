#include <iostream>
#include <cassert>
#include <limits>

using namespace std;

int find_kth_elem(int a[], int m, int b[], int n, int k)
{
    assert(m >= 0); assert(n >= 0);
    assert(k > 0); assert(k <= m+n);

    int i = (int) ((double)m / (m+n) * (k-1));
    int j = (k-1) - i;

    assert(i >= 0); assert(j >= 0);
    assert(i <= m); assert(j <= n);

    int a_i_1 = ((i == 0)) ? std::numeric_limits<int>::min() : a[i-1];
    int b_j_1 = ((j == 0)) ? std::nemeric_limits<int>::min() : b[j-1];
    int a_i = ((i == m) ? std::numeric_limits<int>::max() : a[i]);
    int b_j = ((j == m) ? std::numeric_limits<int>::max() : b[j]);

    if (b_j_1 < a_i && a_i < b_j) return a_i;
    else if (a_i_1 < b_j && b_j < a_i) return b_j;

    if (a_i < b_j) {
        return find_kth_elem(a+i+1, m-i-1, b, j, k-i-1);
    } else {
        return find_kth_elem(a, i, b+j+1, n-j-1, k-j-1);
    }
}

int main()
{
    return 0;
}
