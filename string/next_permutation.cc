//============================================================================
// NextPermutation
// Implement next permutation, which rearranges numbers into the
// lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest
// possible order (ie, sorted in ascending order).
//
// The replacement must be in-place, do not allocate extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its
// corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void next_permutation(string &s)
{
    int n = s.length();

    int i = n-2;
    while (i >= 0 && s[i] > s[i+1]) i--;

    if (-1 == i) {
        reverse(s.begin(), s.end());
        return;
    }

    int j = n-1;
    while (i < j && s[i] > s[j]) j--;
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
}

int main(void)
{
    string input("abcdef");

    cout << input << endl;
    for (int i = 0; i < 10; ++i) {
        next_permutation(input);
        cout << input << endl;
    }

    return 0;
}
