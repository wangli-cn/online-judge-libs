//============================================================================
// Given an array of integers, find two numbers such that they add up to a
// specific target number.
//
// The function twoSum should return indices of the two numbers such that they
// add up to the target,
// where index1 must be less than index2.
// Please note that your returned answers (both index1 and index2) are not
// zero-based.
//
// You may assume that each input would have exactly one solution.
//
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> two_sum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    vector<int> sorted(numbers.begin(), numbers.end());
    sort(sorted.begin(), sorted.end());

    int i = 0, j = n-1;
    while (i < j) {
        int sum = sorted[i] + sorted[j];
        if (sum > target) j--;
        else if (sum < target) i++;
        else break;
    }

    auto it1 = find(numbers.begin(), numbers.end(), sorted[i]);
    auto it2 = find(numbers.begin(), numbers.end(), sorted[j]);

    return make_pair(distance(numbers.begin(), it1), distance(numbers.begin(), it2));
}

int main(void)
{
    vector<int> input {2,7,11,15};

    pair<int, int> p = two_sum(input, 9);

    cout << p.first+1 << " " << p.second+1 << endl;

    return 0;
}
