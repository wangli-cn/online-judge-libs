#include <iostream>
#include <queue>

using namespace std;

struct DequeueMin
{
    DequeueMin() {}

    bool push_rear(int val) {
        Q_elems.push(val);
        if (Q_elems.empty() || Q_elems.front() <= val) {
            Q_min.push(val);
        }

        return true;
    }

    bool pop_front(int &val) {
        if (Q_elems.empty()) return false;

        if (Q_elems.front() == Q_min.front()) {
            Q_min.pop();
        }
        Q_elems.pop();

        return true;
    }

    bool get_min(int &val) {
        if (Q_min.empty()) return false;

        val = Q_min.front();
        return true;
    }

    queue<int> Q_elems;
    queue<int> Q_min;
};

int main()
{
    return 0;
}
