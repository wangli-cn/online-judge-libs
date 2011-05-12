#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool my_next_permutation(string &s)
{
    int last, j;
    int n = s.length();
    for (last = n-2; last >= 0 && s[last] >= s[last+1]; --last);
    for (j = n-1; s[last] >= s[j]; --j);

    if (last != -1) swap(s[last], s[j]);
    for (int l = last+1, r = n-1; l < r; l++, r--)
        swap(s[l], s[r]);
    return (last == -1) ? false : true;
}

int main(void)
{
    string s, t;
    
    cin >> s;
    t = s;

    cout << my_next_permutation(t) << " " << t << endl;
    cout << next_permutation(s.begin(), s.end()) << " " << s << endl;
    return 0;
}
