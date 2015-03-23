#include <iostream>
#include <vector>

#define INF 99999999

using namespace std;

int select(vector<int> &a, int k, int l, int r)
{
    if (l > r) return INF;

    int p = l + (r-l)/2;
    int i = l-1, j=r+1;

    while (1) {
        while (a[++i] < a[p]);
        while (a[--j] > a[p]);
        if (i >= j) break;
        swap(a[i], a[j]);
    }


    int t = i-l+1;
    if (k == t) return a[i];
    else if (k < t) return select(a, k, l, i-1);
    else return select(a, k-t, j+1, r);
}

int main(void)
{
    vector<int> vec {1000, 999, 1001, 7, 3, 2, 1, 10000};
    cout << select(vec, 1, 0, 7) << endl;
    return 0;
}
