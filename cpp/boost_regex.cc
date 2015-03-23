#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;

int main()
{
    string str("helloooooooooooo");
    string replaced("GG");

    boost::regex re("ooooooooo");

    string result = boost::regex_replace(str, re, replaced);
    cout << result << endl;

    return 0;
}
