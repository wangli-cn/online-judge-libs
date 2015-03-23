//============================================================================
// Given a collection of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// Each number in C may only be used once in the combination.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]
//============================================================================

#include <iostream>
#include <vector>

using namespace std;


void go(int rest, vector<int> &candidates, size_t i, vector<int> &sol, vector<vector<int> > &res)
{
    if (rest < 0) return;
    if (rest == 0) {
        if (find(res.begin(), res.end(), sol) == res.end()) {
            res.push_back(sol);
        }
    }

    if (i == candidates.size()) return;

    sol.push_back(candidates[i]);
    go(rest - candidates[i], candidates, i+1, sol, res);
    sol.pop_back();

    go(rest, candidates, i+1, sol, res);
}

vector<vector<int> > solve(int target, vector<int> &candidates)
{
    vector<int> sol;
    vector<vector<int> > res;

    sort(candidates.begin(), candidates.end());
    if (candidates[0] > target) {
        return res;
    }

    go(target, candidates, 0, sol, res);
    return res;
}

int main(void)
{
    vector<int> input {10,1,2,7,6,1,5};

    vector<vector<int> > res = solve(8, input);
    for (auto it1: res) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
