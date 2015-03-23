//============================================================================
// Substring with Concatenation of All Words
// You are given a string, S, and a list of words, L, that are all of the
// same length. Find all starting indices of substring(s) in S that is a
// concatenation of each word in L exactly once and without any intervening
// characters.
//
// For example, given:
// S: "barfoothefoobarman"
// L: ["foo", "bar"]
//
// You should return the indices: [0,9].
// (order does not matter).
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> find(string s, vector<string> &L)
{
    map<string, int> to_find;
    map<string, int> has_found;

    for (int i = 0; i < L.size(); i++) {
        to_find[L[i]] += 1;
    }

    int n = L.size();
    int m = L[0].size();
    vector<int> res;

    for (int i = 0; i <= s.size() - n*m; i++) {
        has_found.clear();

        int j = 0;
        for (j = 0; j < n; j++) {
            int k = i + j*m;
            string sub = s.substr(k, m);

            if (to_find.find(sub) == to_find.end()) break;
            has_found[sub] += 1;
            if (has_found[sub] > to_find[sub]) break;
        }

        if (j == n) res.push_back(i);
    }

    return res;
}

int main()
{
    string s("barfoothefoobarman");
    vector<string> L {string("foo"), string("bar") };

    vector<int> idx = find(s, L);
    for (auto i: idx) {
        std::cout << i << std::endl;
    }

    return 0;
}
