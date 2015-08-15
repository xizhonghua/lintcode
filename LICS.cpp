class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int l1 = LICS(A);
        std::reverse(A.begin(), A.end());
        int l2 = LICS(A);
        return max(l1,l2);
    }
    
    int LICS(const vector<int>& A) {
        int ans = min(1, (int)A.size());
        int l = ans;
        for(int i=1;i<A.size();++i) {
            l = A[i] > A[i-1] ? l+1 : 1;
            ans = max(ans, l);
        }
        
        return ans;
    }
};
