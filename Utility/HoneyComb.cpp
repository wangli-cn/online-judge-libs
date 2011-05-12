#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

pair<int, int> maya(int x)
{
    if (x == 0) return pair<int, int>(0, 0);
    int n = static_cast<int>(ceil((-1.0 + sqrt(1.0 + 4.0/3.0 * x)) / 2.0));
    int a = 3 * n * (n-1);
    int d = static_cast<int>(ceil((1.0 * x - a) / n - 1.0));
    int k = x - a - n * d;
    switch (d) {
        case 0: return pair<int, int>(n-k, k);
        case 1: return pair<int, int>(-k, n);
        case 2: return pair<int, int>(-n, n-k);
        case 3: return pair<int, int>(-n+k, -k);
        case 4: return pair<int, int>(k, -n);
        case 5: return pair<int, int>(n, -n+k);
    }
}

int mayadist(const pair<int, int> &a, const pair<int, int> &b)
{
    int dx = abs(a.first - b.first);
    int dy = abs(a.second - b.second);
    int dz = abs(a.first + a.second - b.first - b.second);
    return min(dx + dy, min(dx + dz, dy + dz));
}

int main(void)
{
  return 0;
}
