class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        const auto size = nums.size();
        vector<pair<int,int>> f(size+1, make_pair(0,0));
        
        f[0].second = -1;
        for(auto i=0;i<size;++i) {
            f[i+1].first = f[i].first + nums[i];
            f[i+1].second = i;
        }
        
        std::sort(f.begin(), f.end());
        
        for(auto i=1;i<=size;++i)
            if(f[i].first == f[i-1].first) {
                auto start = min(f[i].second, f[i-1].second)+1;
                auto end = max(f[i].second, f[i-1].second);
                return vector<int>{start, end};
            }
        
        return vector<int>{-1,-1};
    }
};
