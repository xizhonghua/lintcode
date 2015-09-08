class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        int s = 0;
        int cur = 0;
        int best = INT_MIN;
        
        int bs = 0, bt = 0;
        
        for(int i=0;i<A.size();++i) {
            cur += A[i];
            if(cur>best) {
                best = cur;
                bs = s;
                bt = i;
            }
            if(cur<0) {
                cur = 0;
                s = i+1;
            }
        }
        
        return {bs,bt};
    }
};
