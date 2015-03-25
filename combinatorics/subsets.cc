//============================================================================
// Subsets
// Given a set of distinct integers, S, return all possible subsets.
//
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,3], a solution is:
//
// [
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
// ]
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;

void go(vector<pair<int, int> > &S, int i, vector<int> &curr, VVI &sols)
{
    if (i == S.size()) {
        sols.push_back(curr);
        return;
    }

    go(S, i+1, curr, sols);

    size_t curr_size = curr.size();
    for (size_t k = 1; k <= S[i].second; k++) {
        curr.push_back(S[i].first);
        go(S, i+1, curr, sols);
    }
    curr.resize(curr_size);
}

VVI subsets(vector<pair<int, int> > &S)
{
    VVI sols;
    vector<int> curr;

    go(S, 0, curr, sols);

    return sols;
}

VVI power_sets(vector<int> &S)
{
    int n = S.size();
    uint32_t upper = 1 << n;
    VVI res;

    for (uint32_t i = 0; i < upper; i++) {
        vector<int> sol;

        uint32_t k = i;
        int j = 0;
        while (k > 0) {
            if (k & 0x01) sol.push_back(S[j]);
            k >>= 1;
            j += 1;
        }

        sort(sol.begin(), sol.end());
        res.push_back(sol);
    }

    sort(res.begin(), res.end());
    return res;
}

int main(void)
{
    vector<int> input {1,2,3};

    VVI res = power_sets(input);
    for (auto r: res) {
        for (auto i: r) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
