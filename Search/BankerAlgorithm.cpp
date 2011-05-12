#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; ++i)

typedef vector<int> Array;
typedef vector<Array> Matrix;

bool isSatisfied(int m, Array &req, Array &avail)
{
    REP(i, m) {
        if (req[i] > avail[i])
            return false;
    }
    return true;
}

void releaseResource(int m, Array &alloc, Array &avail)
{
    REP(i, m) {
        avail[i] += alloc[i];
        alloc[i] = 0;
    }
}

bool Banker(int n, int m, Matrix &alloc, Matrix &req, Array &avail)
{
    set<int> P;
    REP(i, n) P.insert(i); 

    while (P.size() > 0) {
        bool found = false;
        for (set<int>::iterator i = P.begin(); i != P.end(); ++i) {
            if (isSatisfied(m, req[*i], avail)) {
                releaseResource(m, alloc[*i], avail);
                P.erase(*i);
                found = true;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main(void)
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0)
            break;
       
        Matrix alloc(n, vector<int>(m, 0));
        Matrix req(n, vector<int>(m, 0));
        Array avail(m, 0);

        REP(i, m) REP(j, n) {
            scanf("%d ", &alloc[j][i]);
        }

        REP(i, m) REP(j, n) {
            scanf("%d ", &req[j][i]);
        }

        REP(i, m) {
            scanf("%d ", &avail[i]);
        }

        printf((Banker(n, m, alloc, req, avail)) ? "YES\n" : "NO\n");
    }

    return 0;
}
