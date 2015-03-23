#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Range;

bool go(int sum, Range x, Range y, Range z, int a, int b, int c, int n, int m)
{
    if (sum < 0) return false;

    if (sum == 0) {
        int s = a * x.first + b * y.first + c * z.first;

        if (s >= m) return true;
        else return false;
    }

    if (go(sum - x.second, x, y, z, a+1, b, c, n, m)) return true;
    if (go(sum - y.second, x, y, z, a, b+1, c, n, m)) return true;
    if (go(sum - z.second, x, y, z, a, b, c+1, n, m)) return true;

    return false;
}

bool solve(Range x, Range y, Range z, int n, int m)
{
    for (int i = n; i >= m; i--) {
        if (go(i, x, y, z, 0, 0, 0, n, m)) return true;;
    }

    return false;
}

int main()
{
    Range x = make_pair(2, 2);
    Range y = make_pair(2, 2);
    Range z = make_pair(2, 2);

    cout << solve(x, y, z, 7, 6) << endl;
    return 0;
}
