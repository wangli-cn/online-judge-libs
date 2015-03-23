//============================================================================
// Given n non-negative integers a1, a2, ..., an, where each represents a
// point at coordinate (i, ai). n vertical lines are drawn such that the two
// endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
// together with x-axis forms a container, such that the container contains
// the most water.
//
// Note: You may not slant the container.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int maximum = 0;

    while (i < j) {
        int smaller_h = (height[i] >= height[j] ? height[j] : height[i]);
        int area = smaller_h * (j - i);

        if (area > maximum) maximum = area;

        if (height[i] < height[j]) {
            i++;
            while (i < j && smaller_h > height[i]) i++;
        } else {
            j--;
            while (i < j && smaller_h > height[j]) j--;
        }
    }

    return maximum;
}

int main(void)
{
    vector<int> input {2,4,2,4};
    cout << solve(input) << endl;
    return 0;
}
