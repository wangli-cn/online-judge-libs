#include <iostream>
#include <string>

//equation := equation + factor | factor
//factor   := factor   * term   | term
//term     := (equation) | Number

using Result = std::pair<int, int>;
#define value first
#define p second

Result equation(const std::string &s, int p = 0);
Result factor(const std::string &s, int p = 0);
Result term(const std::string &s, int p = 0);

Result equation(const std::string &s, int p)
{
    Result r = factor(s, p);
    while (s[r.p] == '+') {
        Result r_ = factor(s, r.p+1);
        r.value += r_.value;
        r.p = r_.p;
    }
    return r;
}

Result factor(const std::string &s, int p)
{
    Result r = term(s, p);
    while (s[r.p] == '*') {
        Result r_ = term(s, r.p+1);
        r.value *= r_.value;
        r.p = r_.p;
    }
    return r;
}

Result term(const std::string &s, int p)
{
    if (s[p] == '(') {
        Result r = equation(s, p+1);
        r.p += 1;
        return r;
    } else {
        int value = 0;
        while (isdigit(s[p]))
            value = value * 10 + (s[p++] - '0');
        return Result(value, p);
    }
}

int main(void)
{
    Result r = equation("(1+2+3)*(4+5+6)");
    std::cout << r.value << std::endl;
    return 0;
}
