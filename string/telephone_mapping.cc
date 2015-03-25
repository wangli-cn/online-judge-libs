#include <iostream>
#include <map>
#include <string>

using namespace std;

void go(const string &input, int pos, string &sol, map<char, string> &M)
{
    if (input.length() == pos) {
        cout << sol << endl;
        return;
    }

    string t = M[input[pos]];
    for (int i = 0; i < t.length(); i++) {
        sol.push_back(t[i]);
        go(input, pos+1, sol, M);
        sol.pop_back();
    }
}


int main()
{
    map<char, string> M;
    M['1'] = string("ABC");
    M['2'] = string("DEF");
    M['3'] = string("GHI");
    M['4'] = string("JKL");
    M['5'] = string("MNO");
    M['6'] = string("PQR");
    M['7'] = string("STU");
    M['8'] = string("VWX");
    M['9'] = string("Z");

    string input("112");
    string sol;
    go(input, 0, sol, M);

    return 0;
}
