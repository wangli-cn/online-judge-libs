//============================================================================
// Restore IP Addresses
// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.
//
// For example:
// Given "25525511135",
//
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

void go(string s, int i, int k, string sol, vector<string> &res)
{
    if (k < 0) return;
    if (i == s.size()) {
        if (k == 0) res.push_back(sol);
        return;
    }

    int j = i;
    int x = 0;
    while (j < s.size()) {
        x = x * 10 + (s[j] - '0');
        if (x > 255) break;

        if (k != 4 && i == j) sol.push_back('.');

        sol.push_back(s[j]);
        go(s, j+1, k-1, sol, res);

        j += 1;
        if (x == 0) break;
    }
}

vector<string> restore_ip_address(string s)
{
    vector<string> res;
    if (s.size() < 4 || s.size() > 12) return res;

    go(s, 0, 4, string(""), res);

    return res;
}

int main(void)
{
    vector<string> res = restore_ip_address(string("25525511135"));

    copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
