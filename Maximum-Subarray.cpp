class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int sum = 0;
        int ans = INT_MIN;
        for(const auto num : nums) {
            sum += num;
            ans = max(ans, sum);
            if(sum<0) sum = 0;
        }
        return ans;
    }
};
