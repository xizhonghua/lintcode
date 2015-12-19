class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        recover(nums, 0, nums.size()-1);
    }
private:
    void recover(vector<int>& nums, int l, int r) {
        if(l>=r) return;
        int pos = findRotationPos(nums, l, r);
        if(pos == -1) return;
        
        for(int i=pos;i<=r;++i)
            std::swap(nums[l+i-pos], nums[i]);
        
        recover(nums, l + (r-pos+1), r);
    }
    
    int findRotationPos(const vector<int>& nums, int l, int r) {
        for(int i=l+1;i<=r;++i)
            if(nums[i] < nums[i-1]) return i;
        return -1;
    }
};
