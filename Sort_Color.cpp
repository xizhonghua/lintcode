class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int l = 0, r = nums.size()-1;
        int m = partition(nums, 0, r, 1);
        partition(nums, 0, m, 0);
    }
private:
    int partition(vector<int> &nums, int l, int r, int pivot)
    {
        int i=l, j=r;
        while(i<=j)
        {
            while(i<r && nums[i] <= pivot) ++i;
            while(j>0 && nums[j] > pivot) --j;
            if(i<=j) swap(nums[i++], nums[j--]);
        }
        
        return i-1;
    }
};
