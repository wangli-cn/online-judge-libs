//============================================================================
// 4Sum
// Given an array S of n integers, are there elements a, b, c, and d in S such
// that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order.
// (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
// A solution set is:
// (-1,  0, 0, 1)
// (-2, -1, 1, 2)
// (-2,  0, 0, 2)
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TwoSum
{
    TwoSum(int idx1, int idx2, int val) :idx1(idx1), idx2(idx2), val(val) {}

    int idx1, idx2;
    int val;
};

bool operator<(const TwoSum &a, const TwoSum &b)
{
    return a.val < b.val;
}

vector<vector<int> > solve(vector<int> &nums, int target)
{
    vector<TwoSum> two_sums;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            two_sums.push_back(TwoSum(i, j, nums[i]+nums[j]));
        }
    }

    vector<vector<int> > result;

    sort(two_sums.begin(), two_sums.end());
    for (int i = 0; i < two_sums.size(); i++) {
        int rest = target - two_sums[i].val;

        TwoSum t(-1, -1, rest);
        vector<TwoSum>::iterator lower = lower_bound(two_sums.begin() + i, two_sums.end(), t);
        if (lower->val + two_sums[i].val != target) continue;
        //cout << lower->val << " " << two_sums[i].val << endl;

        vector<TwoSum>::iterator upper = upper_bound(two_sums.begin() + i, two_sums.end(), t);
        upper--;
        if (upper->val + two_sums[i].val != target) continue;

        int l = distance(two_sums.begin(), lower);
        int u = distance(two_sums.begin(), upper);

        for (int j = l; j <= u; j++) {
            if (two_sums[i].idx1 == two_sums[j].idx1 ||
                two_sums[i].idx2 == two_sums[j].idx1 ||
                two_sums[i].idx1 == two_sums[j].idx2 ||
                two_sums[i].idx2 == two_sums[j].idx2) {
                continue;
            }

            vector<int> sol;
            sol.push_back(nums[two_sums[i].idx1]);
            sol.push_back(nums[two_sums[i].idx2]);
            sol.push_back(nums[two_sums[j].idx1]);
            sol.push_back(nums[two_sums[j].idx2]);

            sort(sol.begin(), sol.end());

            if (find(result.begin(), result.end(), sol) == result.end()) {
                result.push_back(sol);
            }
        }
    }

    return result;
}

int main()
{
    vector<int> input {1,0,-1,0,-2,2};
    vector<vector<int> > results = solve(input, 0);

    for (auto it1: results) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
