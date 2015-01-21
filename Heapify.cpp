class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        for(int i=(A.size()-1)/2;i>=0;--i)
            minHeapfiy(A, i);
    }
private:
    void minHeapfiy(vector<int> &A, int p){
        int l = p*2+1;
        int r = p*2+2;
        if(l >= A.size()) return;
        if(r == A.size()) r = l;
        
        int m = A[l] < A[r] ? l : r;
        
        if(A[p] > A[m]) {
            swap(A[p], A[m]);
            minHeapfiy(A, m);
        }
    }
};
