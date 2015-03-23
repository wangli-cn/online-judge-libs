//============================================================================
// Given an array S of n integers, find three integers in S such that the sum
// is closest to a given number, target. Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
//
// For example, given array S = {-1 2 1 -4}, and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//============================================================================


#include <iostream>
#include <vector>

using namespace std;

int closest(vector<int> nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int res = nums[0] + nums[1] + nums[2];
    for (int k = 0; k < n-2; k++) {
        int i = k+1;
        int j = n-1;
        while (i < j) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) return sum;
            if (abs(sum - target) < abs(res - target)) res = sum;
            if (sum > target) j--;
            else i++;
        }
    }

    return res;
}

int main(void)
{
    vector<int> nums {-1,2,1,4};
    int res = closest(nums, 1);
    cout << res << endl;
    return 0;
}
