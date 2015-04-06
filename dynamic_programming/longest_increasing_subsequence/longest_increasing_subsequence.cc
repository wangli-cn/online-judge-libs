#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "utils/common.h"

#define index_of(as, x) \
    distance(as.begin(), lower_bound(as.begin(), as.end(), x))

std::vector<int> lis_fast(const std::vector<int> &a)
{
    const int n = a.size();
    std::vector<int> A(n, INF);
    std::vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        id[i] = index_of(A, a[i]);
        A[id[i]] = a[i];
    }

    int m = *std::max_element(id.begin(), id.end());
    std::vector<int> b(m+1);
    for (int i = n-1; i >= 0; --i) {
        if (id[i] == m)
            b[m--] = a[i];
    }
    return std::move(b);
}

int main(void)
{
    std::vector<int> vec {8, 8, 8, 8, 9, 1, 10, 3};

    std::vector<int> res = lis_fast(vec);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
