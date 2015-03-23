//============================================================================
// Text Justification
// Given an array of words and a length L, format the text such that each line
// has exactly L characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words
// as you can in each line. Pad extra spaces ' ' when necessary so that each
// line has exactly L characters.
//
// Extra spaces between words should be distributed as evenly as possible. If
// the number of spaces on a line do not divide evenly between words, the empty
// slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is
// inserted between words.
//
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
//
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.
//
// Corner Cases:
// A line other than the last line might contain only one word. What should
// you do in this case?
// In this case, that line should be left-justified.
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

string make_one_line(vector<string> &words, int &idx, int L)
{
    if (words.size() == idx) return string("");

    vector<int> spaces;
    int begin = idx, end = idx+1;
    int total = words[begin].length();
    spaces.push_back(0);

    while (end < words.size()) {
        int t = total + 1 + words[end].length();
        if (t > L)  break;

        spaces.push_back(1);
        total = t;

        end += 1;
    }

    int rest = (L - total);


    //split spaces
    int k = 1;
    while (k < spaces.size() && rest > 0) {
        spaces[k] += 1;
        rest -= 1;

        if (rest == 0) break;

        k = (k == spaces.size()-1) ? 1 : k+1;
    }

    for (int i = 1; i < spaces.size(); i++) {
        spaces[i] += 1;
        rest -= 1;
    }

    string res;

    for (int i = begin; i < end; i++) {
        for (int j = 0; j < spaces[i-begin]; j++) {
            res.push_back(' ');
        }

        res.append(words[i]);
    }

    idx = end;
    return res;
}

vector<string> full_justify(vector<string> &words, int L)
{
    //check if all words are less than L

    int idx = 0;
    vector<string> res;

    while (idx < words.size()) {
        string s = make_one_line(words, idx, L);
        res.push_back(s);
    }

    return res;
}

int main(void)
{
    string a[7] = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> input(a, a+7);

    vector<string> res = full_justify(input, 16);

    copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
