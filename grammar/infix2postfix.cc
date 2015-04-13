#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int priority(char op)
{
    int p;
    switch (op) {
        case '+': case '-':
            p = 1; break;
        case '*': case '/':
            p = 2; break;
        default:
            p = 0; break;
    }
    return p;
}

std::string infix2postfix(const std::string &s)
{
    std::stack<char> S;
    std::stringstream strstr;

    int n = s.length();
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case '(':
                S.push('(');
                break;
            case '+': case '-': case '*': case '/':
                while (!S.empty() && priority(S.top()) >= priority(s[i])) {
                   strstr << S.top();
                   S.pop();
                }

                S.push(s[i]);
                break;
            case ')':
                while (!S.empty() && S.top() != '(') {
                    strstr << S.top();
                    S.pop();
                }
                S.pop();
                break;
            default:
                strstr << s[i];
                break;
        }
    }

    while (!S.empty()) {
        strstr << S.top();
        S.pop();
    }

    std::string t;
    strstr >> t;
    return t;
}

int main()
{
    std::cout << infix2postfix(std::string("(a+b)*(c+d)")) << std::endl;
    return 0;
}
