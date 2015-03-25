//============================================================================
// Given an array of non-negative integers, you are initially positioned at
// the first index of the array.
//
// Each element in the array represents your maximum jump length at that
// position.
//
// Determine if you are able to reach the last index.
//
// For example:
// A = [2,3,1,1,4], return true.
//
// A = [3,2,1,0,4], return false.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

bool go(vector<int> &a, int i)
{
    int n = a.size();
    if (n <= i) {
        return true;
    }

    for (int j = 1; j <= a[i]; j++) {
        if (go(a, i+j)) {
            return true;
        }
    }

    return false;
}

bool can_jump(vector<int> a)
{
    return go(a, 0);
}

int main()
{
    vector<int> input {2,3,1,1,4};
    cout << can_jump(input) << endl;
    return 0;
}
