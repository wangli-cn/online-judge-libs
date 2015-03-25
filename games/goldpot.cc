#include <iostream>
#include <vector>

using namespace std;

int max_coin(vector<int> &coin, int start, int end)
{
    if (start > end) return 0;

    int a = coin[start] + min(max_coin(coin, start+2, end), max_coin(coin, start+1, end-1));
    int b = coin[end] + min(max_coin(coin, start+1, end-1), max_coin(coin, start, end-2));

    return max(a, b);
}

int main()
{
    return 0;
}
