//============================================================================
// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.
//
// For example,
// Given height = [2,1,5,6,2,3],
// return 10.
//============================================================================

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largest_rectangle(vector<int> &height)
{
    int n = height.size();
    vector<int> area(n, 0);
    stack<int> S;

    for (int i = 0; i < n; i++) {
        while (!S.empty() && height[i] <= height[S.top()]) S.pop();
        int j = (S.empty()) ? -1 : S.top();

        area[i] = i-j-1;
        S.push(i);
    }

    for (int i = n-1;  i >= 0; i--) {
        while (!S.empty() && height[i] <= height[S.top()]) S.pop();
        int j = (S.empty()) ? n : S.top();

        area[i] += j-i-1;
        S.push(i);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = (area[i] + 1)* height[i];
        if (res < t) res = t;
    }

    return res;
}

int main(void)
{
    vector<int> input {2,1,5,6,2,3};
    cout << largest_rectangle(input) << endl;
    return 0;
}
