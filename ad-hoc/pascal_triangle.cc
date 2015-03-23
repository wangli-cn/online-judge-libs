#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;

VVI generate(int n)
{
    VVI res;

    if (n < 1) return res;

    res.reserve(n);
    res.push_back(vector<int>(1, 1));

    for (int i = 1; i < n; i++) {
        vector<int> row;
        row.reserve(i+1);
        row.push_back(1);
        for (int j = 0; j < i-1; j++) {
            row.push_back(res[i-1][j] + res[i-1][j+1]);
        }

        row.push_back(1);
        res.push_back(row);
    }

    return res;
}

int main()
{
    VVI res = generate(10);

    return 0;
}
