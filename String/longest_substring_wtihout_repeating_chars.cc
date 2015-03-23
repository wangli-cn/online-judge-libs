//============================================================================
// Given a string, find the length of the longest substring without repeating
// characters. For example,
//
// the longest substring without repeating letters for "abcabcbb" is "abc",
// which the length is 3. For "bbbbb" the longest substring is "b", with the
// length of 1.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int substring_no_repeat(string s)
{
    bool visited[256] = {false};
    int start = 0, end = 0;
    int res = 0;

    while (end < s.size()) {
        if (visited[static_cast<int>(s[end])]) {
            res = max(res, end-start);
            while (s[start] != s[end]) {
                visited[static_cast<int>(s[start])] = false;
                start += 1;
            }

            start += 1;
            end += 1;
        } else {
            visited[static_cast<int>(s[end])] = true;
            end += 1;
        }
    }

    res = max(res, end - start);
    return res;
}

int main(void)
{
    string input("abcabcbb");
    cout << substring_no_repeat(input) << endl;
    return 0;
}
