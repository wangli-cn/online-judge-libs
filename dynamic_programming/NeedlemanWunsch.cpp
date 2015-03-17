/********************************************
 * Field Testing:
 *     - POJ 1080: Human Gene Function
 ********************************************
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <climits>

using namespace std;

const int MAXN = 105;

#define REP(i,n) for(int i = 1; i <= (int)n; ++i)

int NeedlemanWunsch(string &a, string &b, map<char, int> &mapping, vector< vector<int> > &score)
{
    int a_len = a.length(), b_len = b.length();
    vector<int> a_(a_len+1, 0), b_(b_len+1, 0);

    for (int i = 0; i < a_len; ++i) a_[i+1] = mapping[a[i]];
    for (int i = 0; i < b_len; ++i) b_[i+1] = mapping[b[i]];

    vector< vector<int> > f(a_len+1, vector<int>(b_len+1, INT_MIN));
    int deletion = mapping['-'];

    f[0][0] = 0;
    REP(i, b_len) f[0][i] = f[0][i-1] + score[b_[i]][deletion];
    REP(i, a_len) f[i][0] = f[i-1][0] + score[a_[i]][deletion];

    REP(i, a_len) REP(j, b_len) {
        if (f[i-1][j] + score[a_[i]][deletion] > f[i][j]) 
            f[i][j] = f[i-1][j] + score[a_[i]][deletion];
        if (f[i][j-1] + score[b_[j]][deletion] > f[i][j])
            f[i][j] = f[i][j-1] + score[b_[j]][deletion];
        if (f[i-1][j-1] + score[a_[i]][b_[j]] > f[i][j])
            f[i][j] = f[i-1][j-1] + score[a_[i]][b_[j]];
    }
    return f[a_len][b_len];
}

int main(void)
{
    string a("AGTGATG");
    string b("GTTAG");
    map<char, int> mapping;
    mapping.insert(make_pair('A', 0));
    mapping.insert(make_pair('C', 1));
    mapping.insert(make_pair('G', 2));
    mapping.insert(make_pair('T', 3));
    mapping.insert(make_pair('-', 4));

    vector< vector<int> > score;
    int c[5][5] = {5, -1, -2, -1, -3, 
                   -1, 5, -3, -2, -4, 
                   -2, -3, 5, -2, -2, 
                   -1, -2, -2, 5, -1,
                   -3, -4, -2, -1, 0};
    score.resize(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            score[i].push_back(c[i][j]);
    }
    cout << NeedlemanWunsch(a, b, mapping, score) << endl;
    return 0;
}
