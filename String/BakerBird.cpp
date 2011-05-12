#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 2000, M = 200;
const int A = 0x100, S = M*M*A;

int top, *next[S];
int T[N][N], P[M][M];

int add_node() {
    next[top] = new int[A];
    fill(next[top], next[top]+A, -1);
    return top++;
}

#define TRANSFORM(T, nx, ny) { \
    for (int q = 0; q < ny; ++q) { \
        int t = 0, len = nx; \
        for (int i = 0; i < len; ++i) { \
            int a = T[q][i]; \
            while (next[t][a] < 0) t = next[t][0]; \
            t = next[t][a]; \
            T[q][i] = t; \
        } \
    } \
}

int baker_bird(int nx, int ny, int mx, int my)
{
    //Horizontal Aho-Corasick
    top = 0; add_node(); //initial_state
    int acc[my]; memset(acc, 0, sizeof(acc));
    for (int i = 0; i < my; ++i) {
        int t = 0;
        for (int j = 0; j < mx; ++j) {
            char c = P[i][j];
            if (next[t][c] < 0) next[t][c] = add_node();
            t = next[t][c];
        }
        acc[i] = t;
    }

    queue<int> Q; //make failure links using BFS
    for (int a = 1; a <= 0xff; ++a) {
        if (next[0][a] >= 0) {
            next[ next[0][a] ][0] = 0;
            Q.push( next[0][a] );
        } else {
            next[0][a] = 0;
        }
    }

    while (!Q.empty()) {
        int t = Q.front(); Q.pop();
        for (int a = 1; a <= 0xff; ++a) {
            if (next[t][a] >= 0) {
                Q.push(next[t][a]);
                int r = next[t][0];
                while (next[r][a] < 0) r = next[r][0];
                next[next[t][a]][0] = next[r][a];
            }
        }
    }
    TRANSFORM(T, nx, ny); TRANSFORM(P, mx, my);

    //Vertical Knuth Morris Pratt
    int fail[my+1]; fill(fail, fail+my+1, -1);
    for (int i = 0, j = -1; i < my; ) {
        while (j >= 0 && P[i][mx-1] != P[j][mx-1]) j = fail[j];
        if (P[++i][mx-1] == P[++j][mx-1]) fail[i] = fail[j];
        else fail[i] = j;
    }

    int cnt = 0;
    for (int l = 0; l < nx; ++l) {
        for (int i = 0, k = 0; i < ny; ++i) {
            while (k >= 0 && P[k][mx-1] != T[i][l]) k = fail[k];
            if (++k >= my) {
                ++cnt; //match at (l, i) ... right-bottom corner
                k = fail[k];
            }
        }
    }
    return cnt;
}

int main(void)
{
    int nCase;
    int N, M, X, Y;

    scanf("%d ", &nCase);
    while (nCase--) {
        scanf("%d %d ", &N, &M);
        scanf("%d %d ", &X, &Y);
    }
    return 0;
}
