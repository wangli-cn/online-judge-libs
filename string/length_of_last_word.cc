//============================================================================
// Given a string s consists of upper/lower-case alphabets and empty space
// characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space
// characters only.
//
// For example,
// Given s = "Hello World",
// return 5.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int length_of_last_word(string s)
{
    if (s.length() == 0) return 0;

    size_t i;
    if ((i = s.find_last_not_of(" ")) != std::string::npos) {
        int j = i;
        while (j >= 0 && s[j] != ' ') j--;

        return (i-j);
    } else {
        return 0;
    }
}

int main(void)
{
    string input("    sdtdsafd   ");

    cout << length_of_last_word(input) << endl;
    return 0;
}
