//============================================================================
// Best Time to Buy and Sell Stock
//¿
// Say you have an array for which the ith element is the price of a given¿
// stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most¿
// two transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must¿
// sell the stock before you buy again).
//
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int> &prices)
{
    int n = prices.size();
    if (n <= 1) return 0;

    int min_val = prices[0];
    vector<int> left(n, 0);
    for (int i = 1; i < n; i++) {
        if (prices[i] < min_val) min_val = prices[i];
        left[i] = max(left[i-1], prices[i] - min_val);
    }

    int max_val = prices[n-1];
    vector<int> right(n, 0);
    for (int i = n-2; i >= 0; i--) {
        if (prices[i] > max_val) max_val = prices[i];
        right[i] = max(right[i+1], max_val - prices[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, left[i] + right[i]);
    }

    return res;
}

int main()
{
    return 0;
}
