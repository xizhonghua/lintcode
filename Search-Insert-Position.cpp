class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        if(A.size()==0) return 0;
        return searchInsert(A, 0, A.size()-1, target);
    }
private:
    int searchInsert(vector<int> &A, int l, int r, int target) {
        if(l>r) return l;
        int mid = (l+r)/2;
        int p = A[mid];
        if(l==r) return target > p ? r+1 : l;
        if(target == p) return mid;
        return target > p ? searchInsert(A, mid+1, r, target) : searchInsert(A, l, mid-1, target);
    }
};
