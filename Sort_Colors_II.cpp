class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        auto r =  colors.size()-1;
        for(auto i=0;i<k-1;++i)
            r = partition(colors, 0, r, k-i-1);
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
