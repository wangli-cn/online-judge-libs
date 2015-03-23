
bool reorder(vector<int> &input, int M)
{
    map<int, int> freq;
    
    for (auto &elem: input) {
        if (freq.find(elem) != freq.end()) {
            freq[elem] += 1;
        } else {
            freq[elem] = 0;
        }
    }
    
    priority_queue< pair<int, int> > Q;
    for (auto &elem: freq) {
        Q.push(make_pair(elem.snd, elem.snd));
    }
    
    vector<int> res;
    while (Q.size() >= 2) {
        pair<int, int> p1 = Q.top(); Q.pop();
        pair<int, int> p2 = Q.top(); Q.pop();
        
        res.push_back(p1.snd); 
        res.push_back(p2.snd);
        
        if (p1.fst > 1) {
            Q.push(make_pair(p1.fst-1, p1.snd));
        }
        
        if (p2.fst > 1) {
            Q.push(make_pair(p2.fst-1, p2.snd));
        }
    }
    
    
    if (!Q.empty()) {
        return false;
    } else {
        input.swap(res);
    }
}
