#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define INF 99999999

#define index_of(xs, x) \
    distance(xs.begin(), lower_bound(xs.begin(), xs.end(), x))

vector<int> lis(const vector<int> &a)
{
    const int n = a.size();
    vector<int> id(n);
    vector<int> A(n, INF);

    REP(i, n) {
        id[i] = index_of(A, a[i]);
        A[id[i]] = a[i];
    }

    int m = *max_element(id.begin(), id.end());
    vector<int> b(m+1);
    for (int i = n-1; i >= 0; i--) {
        if (id[i] == m) {
            b[m--] = a[i];
        }
    }

    return b;
}

int main(void)
{
    vector<int> a {3,2,1,100,2,3,11,4};
    vector<int> res = lis(a);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
