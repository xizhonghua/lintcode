class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        const auto n = A.length();
        const auto m = B.length();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        
        int max_len = 0;
        for(auto i=1;i<=n;++i)
            for(auto j=1;j<=m;++j)
            {
                if(A[i-1] == B[j-1])
                    f[i][j] = f[i-1][j-1] + 1;
                max_len = max(max_len, f[i][j]);
            }
        
        return max_len;
    }
};

