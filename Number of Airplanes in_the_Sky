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
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        typedef pair<int,int> EVENT;
        vector<EVENT> events;
        
        for(const auto& a : airplanes) {
            events.push_back(make_pair(a.start, 1));
            events.push_back(make_pair(a.end, 0));
        }
        
        std::sort(events.begin(), events.end(), [](const EVENT& e1, const EVENT& e2){
            if(e1.first == e2.first) return e1.second < e2.second;
            return e1.first < e2.first;
        });
        
        int ans = 0;
        int cur = 0;
        for(const auto& e : events) {
            if(e.second == 0) { 
                cur--;
            } else {
                cur++;
            }
            ans = max(ans, cur);
        }
        
        return ans;
    }
};
