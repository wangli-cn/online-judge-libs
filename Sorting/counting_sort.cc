#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

void counting_sort(vector<int> &a, int n, int K)
{
    int j = 0;
    std::vector<int> c(K+1, 0);

    REP(i, n) ++c[a[i]];
    REP(k, K) REP(i, c[k]) a[j++] = k;
}

int main(void)
{
    vector<int> a {7, 5, 4, 4, 4, 1, 3, 100};
    counting_sort(a, 8, 100);

    for (auto elem: a) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
    return 0;
}

