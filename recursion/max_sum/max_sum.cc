//============================================================================
// Find the contiguous subarray within an array (containing at least one
// number) which has the largest sum.
//
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.
//============================================================================

#include <iostream>
#include <vector>
#include <limits>

using Range = std::pair<int, int>;

std::pair<int, Range>  max_sum(const std::vector<int> &a, int n)
{
    int sum = std::numeric_limits<int>::min();
    int b = 0;
    int s = 0;

    int start = 0, end = 0;
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

    return std::make_pair(sum, std::make_pair(start, end));
}

int main()
{
    std::vector<int> a {-2,1,-3,4,-1,2,1,-5,4};

    auto&& res = max_sum(a, 9);
    std::cout << res.first << std::endl;
    return 0;
}
