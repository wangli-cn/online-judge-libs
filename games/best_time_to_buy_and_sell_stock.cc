//============================================================================
// Best Time to Buy and Sell Stock
//
// Say you have an array for which the ith element is the price of a given
// stock on day i.
//
// If you were only permitted to complete at most one transaction (ie, buy
// one and sell one share of the stock), design an algorithm to find the
// maximum profit.
//
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int> &prices)
{
    if (prices.size() < 2) return 0;

    int min_i = 0;
    int res = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < prices[min_i]) min_i = i;

        int diff = prices[i] - prices[min_i];
        if (diff > res) res = diff;
    }

    return res;
}

int main(void)
{
    vector<int> prices {1,2,3,4,5};
    cout << max_profit(prices) << endl;
    return 0;
}
