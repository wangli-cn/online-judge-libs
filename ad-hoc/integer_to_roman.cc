//============================================================================
// Given an integer, convert it to a roman numeral.
//
// Input is guaranteed to be within the range from 1 to 3999.
//============================================================================

#include <iostream>
#include <map>

using namespace std;

string integer_to_roman(int num)
{
    map<int, string> dict;
    dict[1] = "I";
    dict[4] = "IV";
    dict[5] = "V";
    dict[9] = "IX";
    dict[10] = "X";
    dict[40] = "XL";
    dict[50] = "L";
    dict[90] = "XC";
    dict[100] = "C";
    dict[400] = "CD";
    dict[500] = "D";
    dict[900] = "CM";
    dict[1000] = "M";

    string result("");

    for (auto it = dict.rbegin(); it != dict.rend(); it++) {
        while (num >= it->first) {
            num -= it->first;
            result += it->second;
        }
    }

    return result;
}

int main(void)
{
    cout << integer_to_roman(1111) << endl;
    return 0;
}
