#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct DequeueMin
{
    DequeueMin() {}

    bool push_rear(int val) {
        Q_elems.push(val);
        while (!Q_max.empty() && Q_max.back() < val) {
            Q_max.pop_back();
        }
        Q_max.push_back(val);

        return true;
    }

    bool pop_front(int &val) {
        if (Q_elems.empty()) return false;

        if (Q_elems.front() == Q_max.front()) {
            Q_max.pop_front();
        }
        Q_elems.pop();

        return true;
    }

    bool get_max(int &val) {
        if (Q_max.empty()) return false;

        val = Q_max.front();
        return true;
    }

    queue<int> Q_elems;
    deque<int> Q_max;
};

vector<int> max_sliding_window(vector<int> &a, int w)
{
    DequeueMin Q;
    int n = a.size();

    vector<int> res;
    for (int i = 0; i < w; i++) {
        Q.push_rear(a[i]);
    }

    int val;
    for (int i = w; i < n; i++) {
        Q.get_max(val);
        res.push_back(val);

        Q.push_rear(a[i]);
        Q.pop_front(val);
    }

    Q.get_max(val);
    res.push_back(val);

    return res;
}

int main()
{
    vector<int> input {1,3,-1,-3,5,3,6,7};

    vector<int> res = max_sliding_window(input, 3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
