//============================================================================
// Given two integers n and k, return all possible combinations of k numbers
// out of 1 ... n.
//
// For example,
// If n = 4 and k = 2, a solution is:
//
//[
// [2,4],
// [3,4],
// [2,3],
// [1,2],
// [1,3],
// [1,4],
//]
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

void gen_combination(int n, int k, int pos, vector<int> &sol)
{
    if (pos > n) return;

    if (pos == n) {
        if (sol.size() == k) {
            cout << "[";
            for (int i = 0; i < sol.size(); i++) cout << sol[i] << ((i == sol.size()-1) ? "" : " ");
            cout << "]" << endl;
        }
        return;
    }

    gen_combination(n, k, pos+1, sol);

    sol.push_back(pos);
    gen_combination(n, k, pos+1, sol);
    sol.pop_back();
}

void solve(int n, int k)
{
    vector<int> sol;

    gen_combination(n, k, 0, sol);
}

int main()
{
    solve(4, 2);
    return 0;
}
