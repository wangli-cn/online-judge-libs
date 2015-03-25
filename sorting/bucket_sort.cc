#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

void bucket_sort(vector<int> &a, int base, int times)
{
    int n = a.size();
    vector<vector<int>> bucket(base, vector<int>());

    int divisor = 1;
    REP(i, times) {
        REP(j, n) {
            int idx = (a[j] / divisor) % base;
            bucket[idx].push_back(a[j]);
        }

        a.clear();
        REP(j, base) {
            REP(k, bucket[j].size())
                a.push_back(bucket[j][k]);
            bucket[j].clear();
        }
        divisor *= base;
    }
}

int main(void)
{
    vector<int> a {7, 507, 4999, 4000, 4, 1, 3, 100};

    bucket_sort(a, 10, 4);

    for (auto elem: a) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
    return 0;
}
