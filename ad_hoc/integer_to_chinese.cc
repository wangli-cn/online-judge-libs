#include <iostream>
#include <string>
#include <map>

using namespace std;

string read_four_digits_in_chinese(int num, bool first_part)
{
    map<int, string> dict;

    dict[1] = "一";
    dict[2] = "二";
    dict[3] = "三";
    dict[4] = "四";
    dict[5] = "五";
    dict[6] = "六";
    dict[7] = "七";
    dict[8] = "八";
    dict[9] = "九";

    string result("");

    bool prepend_zero = false;
    int thousand_digit = (num / 1000) % 10,
        hundred_digit = (num / 100) % 10,
        ten_digit = (num / 10) % 10,
        unit_digit = num % 10;

    if (thousand_digit > 0) {
        result += dict[thousand_digit] + "千";
    } else {
        prepend_zero = true;
    }

    if (hundred_digit > 0) {
        if (prepend_zero && !first_part) {
            result += "零";
            prepend_zero = false;
        }

        result += dict[hundred_digit] + "百";
    } else {
        prepend_zero = true;
    }

    if (ten_digit > 0) {
        if (prepend_zero && !first_part) {
            result += "零";
            prepend_zero = false;
        }

        result += dict[ten_digit] + "十";
    } else {
        prepend_zero = true;
    }

    if (unit_digit > 0) {
        if (prepend_zero && !first_part) {
            result += "零";
            prepend_zero = false;
        }

        result += dict[unit_digit];
    }

    return result;
}

string integer_to_chinese(int num)
{
    map<int, string> dict;

    dict[100000000] = "億";
    dict[10000] = "萬";
    dict[1] = "";

    bool first_part = true;
    string result("");
    for (map<int, string>::reverse_iterator it = dict.rbegin(); it != dict.rend(); it++) {
        if (num >= it->first) {
            int four_digits = (num / it->first) % 10000;

            string t = read_four_digits_in_chinese(four_digits, first_part);
            first_part = false;

            result += t;
            result += it->second;

            num = num % it->first;
        }
    }

    return result;
}


int main()
{
    int num = 320320;

    cout << integer_to_chinese(num) << endl;

    return 0;
}
