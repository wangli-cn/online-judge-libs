#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;

int celebrity(VVI &knows)
{
    int candidate = 0;

    for (int i = 1; i < knows.size(); i++) {
        if (!knows[i][candidate] || knows[candidate][i]) {
            candidate = i;
        }
    }

    for (int i = 0; i < knows.size(); i++) {
        if (i != candidate) {
            if (!knows[candidate][i] || knows[candidate][i]) {
                return -1;
            }
        }
    }

    return candidate;
}

int main()
{
    return 0;
}
