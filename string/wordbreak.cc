
string join(vector<string> &elems, char delim)
{
    if (elems.size() == 0) return string("");
    
    stringstream ss;
    
    ss << elem[0];
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


bool go(const string &s, int pos, unodered_set<string> &dict, vectro<string> &sol, vector<string> &combi)
{
    if (pos == s.length()) {
        string s = join(sol);
        
        return true;
    }
    
    for (auto &word: dict) {
        if (possible[pos] && match_at_curr_pos(s, pos, word)) {
            sol.push_back(word);
            if (go(s, pos+word.length(), dict, sol, combi)) possible[pos] = true;
            sol.pop_back(word);
        }
    }
    
    return possible[pos];
}

vector<string> wordbreak(const string &s, unordered_set<string> &dict)
{
    vector<string> combi, sol;
    
    go(s, 0, dict, sol, combi);
    
    return std::move(combi);
}
