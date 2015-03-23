//============================================================================
// Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest¿
// consecutive elements sequence.
//
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its¿
// length: 4.
//
// Your algorithm should run in O(n) complexity.
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, int> hashmap;

int longest_contiguous(vector<int> &nums)
{
    if (nums.empty()) return 0;
    hashmap left_len, right_len;

    int res = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (left_len.find(nums[i]) != left_len.end() || right_len.find(nums[i]) != right_len.end()) continue;

        left_len[nums[i]] = 1;
        right_len[nums[i]] = 1;

        if (left_len.find(nums[i]-1) != left_len.end()) {
            int lower = (nums[i] - 1) - left_len[nums[i]-1] + 1;
            int upper = (nums[i]) + right_len[nums[i]] - 1;
            int len = upper - lower + 1;

            right_len[lower] = len;
            left_len[upper] = len;

            res = max(res, len);
        }

        if (right_len.find(nums[i]+1) != right_len.end()) {
            int lower = (nums[i]) - left_len[nums[i]] + 1;
            int upper = (nums[i] + 1) + right_len[nums[i]+1] - 1;
            int len = upper - lower + 1;

            right_len[lower] = len;
            left_len[upper] = len;

            res = max(res, len);
        }
    }

    return res;
}

int main(void)
{
    vector<int> input {100, 4, 200, 1, 3, 2};
    cout << longest_contiguous(input) << endl;
    return 0;
}
