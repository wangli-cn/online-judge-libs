#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

const int INF = 99999999;

#define index_of(as, x) \
    distance(as.begin(), lower_bound(as.begin(), as.end(), x))

vector<int> LIS_fast(const vector<int> &a)
{
    const int n = a.size();
    vector<int> A(n, INF);
    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        id[i] = index_of(A, a[i]);
        A[id[i]] = a[i];
    }

    int m = *max_element(id.begin(), id.end());
    vector<int> b(m+1);
    for (int i = n-1; i >= 0; --i) {
        if (id[i] == m)
            b[m--] = a[i];
    }
    return b;
}

int main(void)
{
    int a[8] = {8, 8, 8, 8, 9, 1, 10, 3};

    vector<int> vec(a, a+8);
    vector<int> res = LIS_fast(vec);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
