//============================================================================
// Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.
//
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int trapping_water(vector<int> a)
{
    int n = a.size();

    if (n <= 2) return 0;

    vector<int> left_max(n, 0);
    vector<int> right_max(n, 0);

    left_max[0] = a[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i-1], a[i]);
    }

    right_max[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        right_max[i] = max(right_max[i+1], a[i]);
    }

    int total = 0;
    for (int i = 1; i < n-1; i++) {
        int low = min(left_max[i-1], right_max[i+1]);
        total += (low > a[i]) ? low - a[i] : 0;
    }

    return total;
}

int main(void)
{
    vector<int> input {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapping_water(input) << endl;
    return 0;
}
