/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.size()==0) return { newInterval };
        
        int s = INT_MAX;
        int t = INT_MIN;
        int p = 0;
        bool intersected = false;
        
        for(int i=0;i<intervals.size();++i) {
            if (intersects(intervals[i], newInterval)) {
                s = min(s, i);
                t = max(t, i);
                intersected = true;
            } else if(newInterval.start > intervals[i].end) {
                p = i+1;
            }
        }
        
        if(intersected) {
            for(int i=s;i<=t;++i)
                newInterval = merge(intervals[i], newInterval);
            intervals.erase(intervals.begin()+s, intervals.begin()+t+1);
        } else {
            s = t = p;
        }
        
        intervals.insert(intervals.begin()+s, newInterval);
        
        return intervals;
    }
private:
    bool intersects(const Interval& l, const Interval& r) {
        return (l.start >= r.start and l.start <= r.end) 
            || (l.end >= r.start and l.end <= r.end)
            || (r.start >= l.start and r.start <= l.end) 
            || (r.end >= l.start and r.end <= l.end);
    }
    
    Interval merge(const Interval& l, const Interval& r) {
        return Interval(min(l.start, r.start), max(l.end, r.end));
    }
};
