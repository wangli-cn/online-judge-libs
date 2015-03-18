//============================================================================
// Given a set of non-overlapping intervals, insert a new interval into the
// intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their
// start times.
//
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
// [1,2],[3,10],[12,16].
//
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
    Interval(int s, int e) :start(s), end(e) {}
    int start, end;
};

vector<Interval> insert(vector<Interval> &intervals, Interval new_one)
{
    vector<Interval> result;
    bool merged = false;
    for (auto it: intervals) {
        if (it.start <= new_one.end && it.end >= new_one.start) {
            new_one.start = min(new_one.start, it.start);
            new_one.end = max(new_one.end, it.end);
            continue;
        }

        if (!merged && it.start > new_one.end) {
            merged = true;
            result.push_back(new_one);
        }

        result.push_back(it);
    }

    if (!merged) result.push_back(new_one);
    return result;
}

int main(void)
{
    vector<Interval> intervals;

    intervals.push_back(Interval(1,2));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(12,16));

    vector<Interval> res = insert(intervals, Interval(4, 9));

    for (auto it: res) {
        cout << it.start << " " << it.end << endl;
    }

    return 0;
}
