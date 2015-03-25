//sort a stack using pop(), top(), push(), empty(), full()
#include <iostream>
#include <stack>

using namespace std;

void sort_stack(stack<int> &S)
{
    stack<int> dest;

    while (!S.empty()) {
        if (dest.empty() || S.top() >= dest.top()) {
            dest.push(S.top());
            S.pop();
        } else {
            stack<int> tmp;
            while (!dest.empty() && dest.top() > S.top()) {
                tmp.push(dest.top());
                dest.pop();
            }

            dest.push(S.top());
            S.pop();

            while (!tmp.empty()) {
                dest.push(tmp.top());
                tmp.pop();
            }
        }
    }

    S = dest;
}


int main()
{
    stack<int> S;
    for (int i = 10; i >= 1; i--) {
        S.push(i);
    }

    sort_stack(S);
    while (!S.empty()) {
        cout << S.top() << endl;
        S.pop();
    }

    return 0;
}
