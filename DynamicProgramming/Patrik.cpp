#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> Problem;


int main(void)
{
    stack<Problem> S;
    long long result = 0;
    int N, h;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> h;
        Problem p(h, 1);
        for (; !S.empty() && S.top().first <= h; S.pop()) {
            result += S.top().second;
            if (S.top().first == h) 
                p.second += S.top().second;
        }

        if (!S.empty()) 
            result++;
        S.push(p);
    }

    cout << result << endl;

    return 0;
}
