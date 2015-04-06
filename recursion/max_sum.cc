//============================================================================
// Find the contiguous subarray within an array (containing at least one
// number) which has the largest sum.
//
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.
//============================================================================

#include <iostream>
#include <vector>

int max_sum(const std::vector<int> &a, int n, int &start, int &end)
{
    int sum = -99999999;
    int b = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        b += a[i];

        if (b > sum) {
            sum = b;
            start = s;
            end = i;
        }

        if (b < 0) {
            b = 0;
            s = i+1;
        }
    }

    return sum;
}

int main()
{
    std::vector<int> a {-2,1,-3,4,-1,2,1,-5,4};
    int start = 0, end = 0;

    std::cout << max_sum(a, 9, start, end) << std::endl;
    return 0;
}
