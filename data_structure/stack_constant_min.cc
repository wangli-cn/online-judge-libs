#include <iostream>
#include <stack>

class StackMin
{
public:
    bool push(int val) {
        S.push(val);
        if (S_min.empty() || S_min.top() >= val) {
            S_min.push(val);
        }

        return true;
    }

    bool pop(int &val) {
        if (S.empty()) return false;

        if (S_min.top() == S.top()) {
            S_min.pop();
        }

        val = S.top(); S.pop();
        return true;
    }

    bool min(int val) {
        if (S_min.empty()) {
            return false;
        } else {
            val = S_min.top();
            return true;
        }
    }

    std::stack<int> S;
    std::stack<int> S_min;
};


int main()
{
    StackMin S;

    S.push(1);
    S.push(3);
    S.push(2);


    return 0;
}
