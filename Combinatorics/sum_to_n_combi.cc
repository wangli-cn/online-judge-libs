#include <iostream>
#include <vector>

using namespace std;

void combi(int n, int kk, vector<int> &sol)
{
    if (n == 0) {
        cout << "{";
        for (auto e: sol) {
            cout << e << " ";
        }
        cout << "}" << endl;
        return;
    } else if (n > 0) {
        for (int k = 1; k <= kk; k += 1) {
            sol.push_back(k);
            combi(n-k, k, sol);
            sol.pop_back();
        }
    }
}

int main()
{
    vector<int> sol;
    int n = 4;
    combi(n, n, sol);
    return 0;
}
