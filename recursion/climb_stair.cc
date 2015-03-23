//============================================================================
// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?
//============================================================================

#include <iostream>
#include <cassert>

using namespace std;

const int MAXN = 100;
int f[MAXN];

int solve(int n)
{
    assert(n > 0);

    if (n == 1) return 1;
    else if (n == 2) return 2;
    else {
        return solve(n-2) + solve(n-1);
    }
}

int main()
{
    cout << solve(4) << endl;
    return 0;
}
