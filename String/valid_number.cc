//============================================================================
// Valid Number
// Validate if a given string is numeric.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Note: It is intended for the problem statement to be ambiguous. You should
// gather all requirements up front before implementing one.
//============================================================================


#include <iostream>

using namespace std;

struct Result
{
    Result(int p) :p(p), valid(true) {}
    int p;
    bool valid;
};


Result parse_spaces(const string &s, int p)
{
    Result r(p);
    r.valid = false;

    while (isspace(s[r.p])) {
        r.p += 1;
        r.valid = true;
    }

    return r;
}

Result parse_dot_or_exp(const string &s, int p)
{
    Result r(p);
    if (s[r.p] == 'e' || s[r.p] == '.') {
        r.p += 1;
        r.valid = true;
    } else {
        r.valid = false;
    }

    return r;
}

// (-|+)?
Result parse_sign(const string &s, int p)
{
    Result r(p);

    if (s[r.p] == '+' || s[r.p] == '-') {
        r.p += 1;
        r.valid = true;
    } else {
        r.valid = false;
    }

    return r;
}


Result parse_integer(const string &s, int p)
{
    Result r(p);
    r.valid = false;

    while (isdigit(s[r.p])) {
        r.p += 1;
        r.valid = true;
    }

    return r;
}

Result parse_number(const string &s, int p)
{
    Result final(p);

    Result r = parse_spaces(s, p);

    r = parse_sign(s, r.p);
    r = parse_integer(s, r.p);

    if (r.valid) {
        Result r_ = parse_dot_or_exp(s, r.p);

        if (r_.valid) {
            final = parse_integer(s, r_.p);
        } else {
            final = r;
        }
    } else {
        final = r;
    }

    return final;
}


int main()
{
    string input("    +2e10");
    Result r = parse_number(input, 0);
    cout << r.valid << endl;
    return 0;
}
