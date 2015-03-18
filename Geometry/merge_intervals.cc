//============================================================================
// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
//
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
    int start, end;
    Interval() :start(0), end(0) {}
    Interval(int s, int e) :start(s), end(e) {}
};

bool operator<(const Interval &a, const Interval &b)
{
    if (a.start == b.start) {
        return a.end < b.end;
    } else {
        return a.start < b.start;
    }
}

vector<Interval> merge(vector<Interval> &intervals)
{
    if (intervals.size() < 2) return intervals;

    sort(intervals.begin(), intervals.end());

    vector<Interval> results;
    Interval curr;

    vector<Interval>::const_iterator it = intervals.begin();
    while (it != intervals.end()) {
        if (it == intervals.begin()) {
            curr = *it;
        } else if (it->start <= curr.end && curr.start <= it->end) {
            curr.start = min(it->start, curr.start);
            curr.end = max(it->end, curr.end);
        } else if (it->start > curr.end){
            results.push_back(curr);
            curr = *it;
        }

        ++it;
    }

    results.push_back(curr);
    return results;
}

int main(void)
{
    vector<Interval> intervals;

    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));

    vector<Interval> results = merge(intervals);

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i].start << " " << results[i].end << endl;
    }

    return 0;
}
