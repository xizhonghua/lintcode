class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        
        return kth(k-1, 0, nums.size()-1, nums);
    }
private:
   int kth(int k, int l, int r, vector<int>& n)
    {
    	
        if(l==r && k==0) return n[l];
        
        int i = l, j = r;
        int p = n[(l+r)/2];
        
        while(i<=j)
        {
            while(i<r && n[i]<p) i++;
            while(j>0 && n[j]>p) j--;
            if(i<=j) swap(n[i++], n[j--]);
        }
        
        int count = (r - i + 1);
        
        if(count > k) return kth(k, i, r, n);
        return kth(k-count, l, i-1, n);
    }
};
