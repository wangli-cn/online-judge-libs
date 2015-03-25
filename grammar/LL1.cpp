#include <iostream>

using namespace std;

//equation := equation + factor | factor
//factor   := factor   * term   | term
//term     := (equation) | Number

typedef pair<int, int> Result;
#define value first
#define p second

Result equation(const string &s, int p = 0);
Result factor(const string &s, int p = 0);
Result term(const string &s, int p = 0);

Result equation(const string &s, int p) 
{
    Result r = factor(s, p);
    while (s[r.p] == '+') {
        Result r_ = factor(s, r.p+1);
        r.value += r_.value;
        r.p = r_.p;
    }
    return r;
}

Result factor(const string &s, int p)
{
    Result r = term(s, p);
    while (s[r.p] == '*') {
        Result r_ = term(s, r.p+1);
        r.value *= r_.value;
        r.p = r_.p;
    }
    return r;
}

Result term(const string &s, int p)
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
    cout << r.value << endl;
    return 0;
}
