class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        vector<pair<int,int> > s;
        map<int,int> m;
        int index = 0;
        
        for(auto n : nums)
        {
            if(m.count(n))
                s[m[n]].second++;
            else
            {
                if(s.size()<k) {
                    m[n] = s.size();
                    s.push_back(make_pair(n, 1));
                }
                else
                {
                    s[index].second--;
                    if(s[index].second==0)
                    {
                        m.erase(s[index].first);
                        m[n] = index;
                        s[index].first = n;
                        s[index].second = 1;
                    }
                    index++;
                    if(index>k) index=0;
                }
            }
        }
        
        int max_count = INT_MIN;
        int ans = 0;
        for(auto kv:s)
            if(kv.second > max_count) {
                max_count = kv.second;
                ans = kv.first;
            }
        
        return ans;
    }
};

