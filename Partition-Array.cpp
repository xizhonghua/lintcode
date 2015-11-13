class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int i=0, j=nums.size()-1;
        while(i<j) {
            while(nums[i]<k && i<=j) ++i;
            while(nums[j]>=k && j>=i) --j;
            if(i<j) {
                std::swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        return i;
    }
};
