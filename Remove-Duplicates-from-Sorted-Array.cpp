class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if(nums.empty()) return 0;
        
        int len = (int)nums.size();
        int ans = len;
        int i = 0, j = 1;
        while(j<ans) {
            while (nums[j] == nums[j-1] && j<ans) ++j;
            int count = j-i-1;
            ans -= count;
            
            if(count>0) {
                for(int p=j;p<ans+count;++p)
                    nums[p-count] = nums[p];
            }
            
            j -= count;
            i = j;
            ++j;
        }
        return ans;
    }
};
