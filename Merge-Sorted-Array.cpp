class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int ib = 0, ia = 0;
        int c = 0;
        while(ia < m + n && ib < n) {
            if(A[ia] <= B[ib] & ia < m + c) {
                ++ia;
            } else {
                c++;
                for(int p=m+c-1;p>ia;--p)
                    A[p] = A[p-1];
                A[ia++] = B[ib++];
                
            }
            
        }
    }
};
