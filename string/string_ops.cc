#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>


vector<string> splitAll(string s, string t)
{
    vector<string> v;
    for (int p = 0; (p = s.find(t)) != s.npos; ) {
        v.push_back(s.substr(0, p));
        s = s.substr(p + t.size());
    }
    v.push_back(s);
    return v;
}

vecor<string> split(string s, string t)
{
    vector<string> v;
    int p = s.find(t);
    if (p != s.npos) {
        v.push_back(s.substr(0, p));
        s = s.substr(p + t.size());
    }
    v.push_back(s);
    return v;
}

string replaceAll(string s, string f, string t)
{
    string r;
    for (int p = 0; (p = s.find(f)) != s.npos; ) {
        r += s.substr(0, p) + t;
        s = s.substr(p + f.size());
    }
    return r+s;
}

string replace(string s, string f, string t)
{
    string r;
    int p = s.find(f);
    if (p != s.npos) {
        r += s.substr(0, p) + t;
        s = s.substr(p + f.size());
    }
    return r+s;
}


std::string ltrim(std::string s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string rtrim(std::string s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
std::string trim(std::string s) {
    return ltrim(rtrim(s));
}


int main(void)
{

    return 0;
}
