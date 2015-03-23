//============================================================================
// SimplifyPath
// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together,
// such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".
//============================================================================


#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string join(vector<string> elems, char delim)
{
    if (elems.size() == 0) return string("");

    stringstream ss;

    ss << elems[0];
    for (int i = 1; i < elems.size(); i++) {
        ss << delim << elems[i];
    }

    return ss.str();
}

vector<string> split(string &s, char delim)
{
    stringstream ss(s);
    string item;
    vector<string> elems;

    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }

    return elems;
}

string simplify(string path)
{
    vector<string> elems = split(path, '/');

    vector<string> buffer;
    for (int i = 0; i < elems.size(); i++) {
        if (elems[i] == string("..")) {
            if (!buffer.empty()) {
                buffer.pop_back();
            }
        } else if (elems[i] == string(".")) {

        } else if (elems[i] == string("")) {

        } else {
            buffer.push_back(elems[i]);
        }
    }

    string result("/");
    result += join(buffer, '/');
    return result;
}


int main(void)
{
    string input1("/a/./b/../../c/");
    string input2("/home/");
    string input3("/home//foo/");
    string input4("/../");

    cout << simplify(input1) << endl;
    cout << simplify(input2) << endl;
    cout << simplify(input3) << endl;
    cout << simplify(input4) << endl;

    return 0;
}
