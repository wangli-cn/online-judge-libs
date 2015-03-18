//============================================================================
// There are two sorted arrays A and B of size m and n respectively. Find the
// median of the two sorted arrays. The overall run time complexity should be
// O(log (m+n)).
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int go(int a[], int n, int b[], int m, int k)
{
    if (n <= 0) return b[k-1];
    if (m <= 0) return a[k-1];
    if (k <= 1) return min(a[0], b[0]);

    if (b[m/2] >= a[n/2]) {
        if (n/2 + 1 + m/2 >= k) {
            return go(a, n, b, m/2, k);
        } else {
            return go(a + n/2 + 1, n - (n/2+1), b, m, k - (n/2+1));
        }
    } else {
        if (n/2 + 1 + m/2 >= k) {
            return go(a, n/2, b, m, k);
        } else {
            return go(a, n, b + m/2 + 1, m - (m/2+1), k  - (m/2+1));
        }
    }
}

double median(int a[], int n, int b[], int m)
{
    if ((m+n) % 2 == 1) {
        return static_cast<double>(go(a, n, b, m, (m+n)/2 + 1));
    } else {
        return (go(a, n, b, m, (m+n)/2) + go(a, n, b, m, (m+n)/2 + 1)) / 2.0;
    }
}

int main()
{
    int a[6] = {6,7,8,9,10,11};
    int b[5] = {1,2,3,4,5};

    cout << median(a, 6, b, 5) << endl;
    return 0;
}
