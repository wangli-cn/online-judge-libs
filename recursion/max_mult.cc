#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int max_mult(vector<int> &a)
{
    int n = a.size();

    if (n == 1) return a[0];

    int pos = 1, neg = 1;
    int ans = std::numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            neg *= a[i];
            pos *= a[i];
        } else {
            int t = neg;
            neg = pos * a[i];
            pos = t * a[i];
        }

        ans = max(ans, pos);
    }

    return ans;
}

int main()
{
    vector<int> input {1,-2,-4,3,5,1};
    cout << max_mult(input) << endl;

    return 0;
}
