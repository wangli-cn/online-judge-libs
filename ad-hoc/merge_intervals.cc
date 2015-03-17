#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
    Interval(int s, int e) :start(s), end(e) {}
    int start;
    int end;
};

vector<Interval> merge_overlaps(vector<Interval> intervals, Interval another)
{
    vector<Interval> result;
    vector<Interval>::iterator it;

    bool merge_finished = false;

    for (it = intervals.begin(); it != intervals.end(); ++it) {
        if (it->start < another.end && another.start < it->end) {
            another.start = (it->start < another.start) ? it->start : another.start;
            another.end = (it->end < another.end) ? another.end : it->end;
            continue;
        }

        if (it->start > another.end) {
            result.push_back(another);
            merge_finished = true;
        }

        result.push_back(*it);
    }

    if (!merge_finished) result.push_back(another);
    return result;
}
