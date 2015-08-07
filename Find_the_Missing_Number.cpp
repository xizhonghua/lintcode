class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        const auto n = (nums.size()+1);
        auto ans = (n-1)*n/2;
        for(const auto& num : nums)
            ans -= num;
        return ans;
    }
};
