//============================================================================
// Given a string, determine if it is a palindrome, considering only¿
// alphanumeric characters and ignoring cases.
//
// For example,
//
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

bool is_valid(string s)
{
    int start = 0, end = s.length()-1;

    while (start < end) {
        while (!isalpha(s[start]) && !isdigit(s[start])) start++;

        while (!isalpha(s[end]) && !isdigit(s[end])) end--;

        int diff = abs(s[start] - s[end]);
        if (diff == 0 || diff == 32) start++, end--;
        else return false;
    }

    return true;
}

int main(void)
{
    string input("A man, a plan, a canal: Panama");

    cout << std::boolalpha << is_valid(input) << endl;
    return 0;
}
