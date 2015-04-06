#include <iostream>
#include <string>
#include <algorithm>

bool my_next_permutation(std::string &s)
{
    int last, j;
    int n = s.length();

    for (last = n-2; last >= 0 && s[last] >= s[last+1]; --last);
    for (j = n-1; s[last] >= s[j]; --j);

    if (last != -1) {
        std::swap(s[last], s[j]);
        std::reverse(s.begin()+last+1, s.end());
        return true;
    } else {
        return false;
    }
}

int main(void)
{
    std::string s, t;

    std::cin >> s;
    t = s;

    std::cout << my_next_permutation(t) << " " << t << std::endl;
    std::cout << std::next_permutation(s.begin(), s.end()) << " " << s << std::endl;
    return 0;
}
