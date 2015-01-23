class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        vector<int> s(k,0);
        vector<int> c(k,1);
        map<int,int> m;
        
        auto index = 0;
        
        for(auto n : nums)
        {
            if (m.count(n)) {
                ++c[m[n]];
            } else {
                if(--c[index]==0)
                {
                    m.erase(s[index]);
                    m[n] = index;
                    s[index] = n;
                    c[index] = 1;
                }
                index = (++index)%k;
            }
        }
        
        auto it = std::max_element(c.begin(), c.end());
        
        return s[it-c.begin()];
    }
};

