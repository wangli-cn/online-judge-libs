#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

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

string infix2postfix(const string &s)
{
    stack<char> S;
    stringstream strstr;

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

    string t;
    strstr >> t;
    return t;
}

int main()
{
    cout << infix2postfix(string("(a+b)*(c+d)")) << endl;
    return 0;
}
