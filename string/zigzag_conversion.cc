//============================================================================
// ZigZag Conversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given
// number of rows like this: (you may want to display this pattern in a fixed
// font for better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//============================================================================


#include <iostream>
#include <string>

using namespace std;

string convert(string s, int n_rows)
{
    if (n_rows < 2) return s;

    int n = s.size();
    int step = 2 * n_rows - 2;

    string res;
    for (int i = 0; i < n; i += step) {
        res.push_back(s[i]);
    }

    for (int i = 1; i < n_rows-1; i++) {
        for (int j = i; j < n; j += step) {
            res.push_back(s[j]);

            int k = (j-i) + n_rows + (i-1);
            if (k < n) {
                res.push_back(s[k]);
            }
        }
    }

    for (int i = n_rows-1; i < n; i += step) {
        res.push_back(s[i]);
    }

    return res;
}

int main()
{
    cout << convert(string("PAYPALISHIRING"), 3) << endl;;
    return 0;
}
