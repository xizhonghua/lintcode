class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int count = 0;
        int len = A.size();
        int i = 0;
        
        while(i<len) {
            if(A[i]==elem) {
                ++ count;
                for(int j=i+1;j<=len-count;++j)
                    A[j-1] = A[j];
                if(i+count==len) break;
            } else {
                ++i;
            }
        }
        return len - count;
    }
};
