//============================================================================
// Write a function to find the longest common prefix string amongst an array
// of strings.
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longest_common_prefix(vector<string> strs)
{
    int n = strs.size();

    if (n == 0) return string("");

    int l = 0;
    while (l < strs[0].size()) {
        for (int i = 1; i < n; i++) {
            if (l == strs[i].size() || strs[i][l] != strs[0][l]) {
                return strs[i].substr(0, l);
            }
        }

        l++;
    }

    return strs[0];
}

int main(void)
{
    vector<string> input { string("1112abc"), string("111abc"), string("112abc"), string("111c") };
    cout << longest_common_prefix(input) << endl;
    return 0;
}
