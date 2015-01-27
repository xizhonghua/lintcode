class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int min_sum = INT_MAX;
        int sum = 0;
        for(auto n : nums)
        {
            sum += n;
            min_sum = std::min(min_sum, sum);
            if(sum>0) sum=0;
        }
        
        return min_sum;
    }
};

