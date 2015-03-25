//============================================================================
// Word Ladder
// Given two words (start and end), and a dictionary, find the length of¿
// shortest transformation sequence from start to end, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
//
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//============================================================================

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

vector<string> get_neighbors(string &word, unordered_set<string> &dict)
{
    vector<string> res;
    for (int i = 0; i < word.size(); i++) {
        string copy(word);
        for (char c = 'a'; c <= 'z'; c++) {
            copy[i] = c;
            if (dict.find(copy) != dict.end()) {
                res.push_back(copy);
                dict.erase(copy);
            }
        }
    }

    return res;
}

int ladder(string start, string end, unordered_set<string> &dict)
{
    queue<pair<string, int> > Q;

    Q.push(make_pair(start, 1));
    dict.insert(end);
    while (!Q.empty()) {
        pair<string, int> curr = Q.front(); Q.pop();

        if (curr.first == end) {
            return curr.second;
        }

        vector<string> neighbors = get_neighbors(curr.first, dict);
        for (auto it: neighbors) {
            Q.push(make_pair(it, curr.second+1));
        }
    }
}

int main()
{
    string start("hit");
    string end("cog");
    vector<string> dict { string("hot"), string("dot"), string("dog"), string("lot"), string("log") };

    std::cout << ladder(start, end, dict) << std::endl;

    return 0;
}
