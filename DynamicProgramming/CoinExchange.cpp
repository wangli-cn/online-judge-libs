#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

const int INF = 99999999;

vector<int> CoinExchange(int C, vector<int> &cs)
{
    int n = cs.size();
    vector<int> xs(C+1, INF);
    vector<int> ys(C+1);

    xs[0] = 0;
    for (int c = 1; c <= C; c++) {
        for (int i = 0; i < n; i++) {
            if (c >= cs[i]) {
                if (xs[c] > xs[c - cs[i]] + 1) {
                    xs[c] = xs[c - cs[i]] + 1;
                    ys[c] = c - cs[i];
                }
            }
        }
    }

    vector<int> zs;
    for (int c = C; c > 0; c = ys[c]) 
        zs.push_back(c - ys[c]);
    return zs;
}

int main(void)
{
    int a[4] = {1, 3, 4, 5};
    vector<int> cs(a, a+4);

    vector<int> res = CoinExchange(7, cs);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
