//============================================================================
// Roman to Integer
// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.
//============================================================================

#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int roman_to_integer(string s)
{
    map<char, int> dict;

    dict.insert(make_pair('M', 1000));
    dict.insert(make_pair('D', 500));
    dict.insert(make_pair('C', 100));
    dict.insert(make_pair('L', 50));
    dict.insert(make_pair('X', 10));
    dict.insert(make_pair('V', 5));
    dict.insert(make_pair('I', 1));

    int res = 0;
    size_t i = 0;
    while (i < s.size()-1) {
        if (dict[s[i]] < dict[s[i+1]]) res -= dict[s[i]];
        else res += dict[s[i]];

        i++;
    }

    res += dict[s[i]];
    return res;
}

int main()
{
    std::cout << roman_to_integer("MDIV") << std::endl;
    return 0;
}
