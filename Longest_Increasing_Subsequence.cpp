class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        auto size = nums.size();
        if (size==0) return 0;
        vector<int> f(size, 1);
        for(auto i=0;i<size;++i)
            for(auto j=0;j<i;++j)
                if(nums[i]>=nums[j])
                    f[i] = max(f[i], f[j]+1);
                
        return *std::max_element(f.begin(), f.end());
    }
};

/////////////////////////////////////////////////////////////////////
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        
        multiset<int> s;
        
        for(const auto n : nums) {
            s.insert(n);
            auto it = s.upper_bound(n);
            if(it != s.end()) s.erase(it);
        }
        
        return s.size();
    }
};


