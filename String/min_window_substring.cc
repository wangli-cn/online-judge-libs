//============================================================================
// Given a string S and a string T, find the minimum window in S which will
// contain all the characters in T in complexity O(n).
//
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
//
// Note:
// If there is no such window in S that covers all characters in T, return the
// empty string "".
//
// If there are multiple such windows, you are guaranteed that there will
// always be only one unique minimum window in S.
//============================================================================

#include <iostream>
#include <string>
#include <limits>

using namespace std;

string min_window(string s, string t)
{
    int needs_to_find[256] = {0};
    int has_found[256] = {0};

    for (int i = 0; i < t.length(); i++) {
        needs_to_find[static_cast<int>(t[i])] += 1;
    }

    string res;
    int min_len = std::numeric_limits<int>::max();
    int count = 0;
    int begin = 0, end = 0;
    while (end < s.length()) {
        if (needs_to_find[static_cast<int>(s[end])] == 0) {
            end += 1;
            continue;
        }

        has_found[static_cast<int>(s[end])] += 1;
        if (has_found[static_cast<int>(s[end])] <= needs_to_find[static_cast<int>(s[end])]) count += 1;

        if (count >= t.length()) {
            while (begin < end && (needs_to_find[static_cast<int>(s[begin])] == 0 || has_found[static_cast<int>(s[begin])] > needs_to_find[static_cast<int>(s[begin])])) {
                begin += 1;
                count -= 1;
            }

            int len = end - begin + 1;
            if (len < min_len) {
                min_len = len;
                res = s.substr(begin, len);
            }
        }

        end += 1;
    }

    return res;
}

int main()
{
    string s("ADOBECODEBANC");
    string t("ABC");

    cout << min_window(s, t) << endl;

    return 0;
}
