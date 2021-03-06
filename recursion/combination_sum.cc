//============================================================================
// Given a set of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// The same repeated number may be chosen from C unlimited number of times.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [7]
// [2, 2, 3]
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

    for (int j = 0; j * candidates[i] <= rest; j++) {
        if (j != 0) {
            sol.push_back(candidates[i]);
            go(rest - candidates[i] * j, candidates, i+1, sol, res);
            sol.pop_back();
        } else {
            go(rest, candidates, i+1, sol, res);
        }
    }
}

vector<vector<int> > solve(int target, vector<int> &candidates)
{
    vector<int> sol;
    vector<vector<int> > res;

    sort(candidates.begin(), candidates.end());
    if (candidates[0] > target) {
        return std::move(res);
    }

    go(target, candidates, 0, sol, res);
    return std::move(res);
}

int main(void)
{
    vector<int> input {2,3,6,7};

    vector<vector<int> > res = solve(7, input);
    for (auto it1: res) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
