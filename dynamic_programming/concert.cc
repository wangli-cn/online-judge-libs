// Field Test: http://tioj.ck.tp.edu.tw/problems/1100
//
#include <iostream>
#include <vector>
#include <limits>

using VVI = std::vector<std::vector<int>>;
using VVLL = std::vector<std::vector<long long>>;

class Interval
{
public:
    explicit Interval(long long a, long long b, long long p): a(a), b(b), p(p) {}

    long long a, b, p;
};

long long f(std::vector<Interval> &v, VVLL& dp, long long i, long long j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (i < j) return dp[i][j] = 0LL;
    if (j == 1) {
        if (i == 1) {
            return dp[i][j] = v[j-1].a + v[j-1].p - 1;
        } else if (i > 0) {
            dp[i][j] = v[j-1].a + v[j-1].p - 1;
            if (f(v, dp, i-1, j) > 0) {
                if (f(v, dp, i-1, j) < dp[i][j]) {
                    dp[i][j] = f(v, dp, i-1, j);
                }
            }

            return dp[i][j];
        }
    }

    long long right = 0;
    if (f(v, dp, i-1, j) > 0) {
        right = f(v, dp, i-1, j);
    }

    if (f(v, dp, i-1, j-1) > 0) {
        if (v[i-1].b - v[i-1].p + 1 > f(v, dp, i-1, j-1)) {
            long long left = std::max(f(v, dp, i-1, j-1)+1, v[i-1].a);
            long long curr_right = left + v[i-1].p - 1;
            if (right == 0 || right > curr_right) {
                right = curr_right;
            }
        }
    }

    return dp[i][j] = right;
}


void solve(std::vector<Interval>& v)
{
    int n = v.size();
    VVLL dp(n+1, std::vector<long long>(n+1, -1LL));

    for (int i = n; i >= 1; i--) {
        if (f(v, dp, n, i) > 0) {
            std::cout << i << std::endl;
            goto out;
        }
    }

out:
    //for (int i = 0; i <= n; i++) {
        //for (int j = 0; j <= n; j++) {
            //std::cout << dp[i][j] << " ";
        //}
        //std::cout << std::endl;
    //}
    return;
}


int main()
{
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        long long a, b, p;
        std::vector<Interval> v;
        for (int i = 0; i < n; i++) {
            std::cin >> a >> b >> p;
            v.push_back(Interval(a, b, p));
        }

        solve(v);
    }

    return 0;
}
