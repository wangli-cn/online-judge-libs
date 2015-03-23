//============================================================================
// Given a digit string, return all possible letter combinations that the
// number could represent.
//
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be
// in any order you want.
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

const string keypad[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void go(string &digits, size_t i, string sol, vector<string> &results)
{
    if (i == digits.size()) {
        results.push_back(sol);
        return;
    }

    int pos = digits[i] - '2';
    for (int j = 0; j < keypad[pos].size(); j++) {
        go(digits, i+1, sol + keypad[pos][j], results);
    }
}

vector<string> letter_combinations(string digits)
{
    vector<string> results;

    go(digits, 0, "", results);

    return results;
}

int main(void)
{
    string input("23");

    vector<string> results = letter_combinations(input);
    copy(results.begin(), results.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
