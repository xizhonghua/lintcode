class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if(nums.size()<=1) return;
        int l = 0;
        int r = nums.size()-1;
        while(l<r) {
            while(nums[l]%2==1 && l<r) ++l;
            while(nums[r]%2==0 && r>l) --r;
            std::swap(nums[l++], nums[r--]);
        }
    }
};
