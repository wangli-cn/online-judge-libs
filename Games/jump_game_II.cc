//============================================================================
// Given an array of non-negative integers, you are initially positioned at
// the first index of the array.
//
// Each element in the array represents your maximum jump length at that
// position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// For example:
// Given array A = [2,3,1,1,4]
//
// The minimum number of jumps to reach the last index is 2. (Jump 1 step
// from index 0 to 1, then 3 steps to the last index.)
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int BFS(vector<int> &a)
{
    queue< pair<int, int> > Q;

    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        pair<int, int> curr = Q.front(); Q.pop();

        if (curr.first >= a.size()-1) return curr.second;

        for (int j = 1; j <= a[curr.first]; j++) {
            Q.push(make_pair(curr.first+j, curr.second+1));
        }
    }

    return std::numeric_limits<int>::max();
}

int jump_steps(vector<int> a)
{
    return BFS(a);
}

int main(void)
{
    vector<int> input {2,3,1,1,4};
    cout << jump_steps(input) << endl;
    return 0;
}
