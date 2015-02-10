class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int ans = nums[0];
        int count = 1;
        
        for(auto i=1;i<nums.size();++i)
        {
            if(ans == nums[i]) count++;
            else {
                if(--count <= 0) {
                    ans = nums[i];
                    count = 1;
                }
            }
        }
        
        return ans;
        
    }
};

