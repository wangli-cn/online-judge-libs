#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <algorithm>

using namespace std;

void NumberFactoring(int n, vector<int> &v)
{
    int sq = (int) sqrt((double) n); 
    for (int i = 2; i <= sq; ++i) {
        if (n % i) continue;
        v.push_back(i);
        n /= i--;
        sq = (int) sqrt((double) n);
    }
    if (n > 1) v.push_back(n);
}

int main(void)
{
    vector<int> v;

    NumberFactoring(100, v);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));   
    return 0;
}
