/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comparefunc(Interval a, Interval b) {
    if(a.start!=b.start) return a.start<b.start;
    else return a.end<b.end;
}
class Solution {

public:
    vector<Interval> merge(vector<Interval> &intervals) {
        std::sort(intervals.begin(), intervals.end(), comparefunc);
        int n=intervals.size();
        if(n<=1) { return intervals;}
        vector<Interval> result;
        result.push_back(intervals[0]);
        for(int i=1; i<n; i++) {
            if(result.back().start==intervals[i].start) {
                result.back().end = intervals[i].end;
            }else if(result.back().end>=intervals[i].start){
                result.back().end = max(intervals[i].end,result.back().end);
            }else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
