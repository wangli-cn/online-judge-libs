//============================================================================
// Permutation Sequence
// The set [1,2,3,…,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
//
// Note: Given n will be between 1 and 9 inclusive.
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string next_permutation(string s)
{
    int n = s.length();

    int i = n-2;
    while (i >= 0 && s[i] > s[i+1]) i--;

    if (i == -1) {
        reverse(s.begin(), s.end());
        return s;
    }

    int j = n-1;
    while (s[i] > s[j]) j--;
    swap(s[i], s[j]);
    reverse(s.begin()+i+1, s.end());

    return s;
}

void gen_seq(int n, int k)
{
    stringstream ss;
    for (int i = 1; i <= n; i++) {
        ss << i;
    }
    string input = ss.str();

    cout << input << endl;
    for (int i = 0; i < k-1; i++) {
        string next = next_permutation(input);
        cout << next << endl;
        input = next;
    }
}

int main()
{
    gen_seq(3, 6);
    return 0;
}
