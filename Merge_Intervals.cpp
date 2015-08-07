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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        std::sort(intervals.begin(), intervals.end(), [=](const Interval& l, const Interval& r){
            return l.start < r.start;
        });
        
        vector<Interval> ans;
        
        for(const auto& i : intervals) {
            if(ans.empty()) ans.push_back(i);
            else if(!merge(ans.back(), i)) ans.push_back(i);
        }
        
        return ans;
    }
private:
    bool merge(Interval& back, const Interval& now) {
        if(back.end >= now.start && back.end <= now.end) {
            back.end = now.end;
            return true;
        } else if(back.end >= now.end) {
            return true;
        }
        return false;
    }
};
