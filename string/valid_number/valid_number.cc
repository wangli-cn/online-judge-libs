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
#include <string>

class Result
{
public:
    Result() = delete;
    explicit Result(int p) :p(p), valid(true) {}

    int p;
    bool valid;
};


Result parse_spaces(const std::string &s, int p)
{
    Result r(p);
    r.valid = false;

    while (isspace(s[r.p])) {
        r.p += 1;
        r.valid = true;
    }

    return r;
}

Result parse_dot_or_exp(const std::string &s, int p)
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
Result parse_sign(const std::string &s, int p)
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


Result parse_integer(const std::string &s, int p)
{
    Result r(p);
    r.valid = false;

    while (isdigit(s[r.p])) {
        r.p += 1;
        r.valid = true;
    }

    return r;
}

Result parse_number(const std::string &s, int p)
{
    Result rr(p);

    Result r = parse_spaces(s, p);

    r = parse_sign(s, r.p);
    r = parse_integer(s, r.p);

    if (r.valid) {
        Result r_ = parse_dot_or_exp(s, r.p);

        if (r_.valid) {
            rr = parse_integer(s, r_.p);
        } else {
            rr = r;
        }
    } else {
        rr = r;
    }

    return rr;
}


int main()
{
    std::string input("    +2e10");
    Result r = parse_number(input, 0);
    std::cout << r.valid << std::endl;
    return 0;
}
