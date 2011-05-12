#include <iostream>

using namespace std;

const int MAXN = 12;

int constraint[2*MAXN];
bool f[(1 << 13) + 10][2*MAXN];

int main(void)
{
    int N, S;
    while(cin >> N && N) {
        cin >> S;
        for(int i = 0; i < 2*N; i++) {
            cin >> constraint[i];
        }

        for(int i = 0; i < 2*N; i++)
            f[0][i] = false;
        for(int i = 0; i < S; i++) {
            for(int j = 0; j < 2*N; j++) {
                bool win = false;

                for(int k = max(i-constraint[j], 0); k < i; k++) {
                    int nextj = (j+1) % (2*N);
                    if(f[k][nextj] == false) {
                        win = true;
                        break;
                    }
                }
                f[i][j] = win;
            }
        }

        if(f[S-1][0])
            cout << 1 << endl;
        else 
            cout << 0 << endl;
    }

    return 0;
}

