class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        const auto n = A.length();
        const auto m = B.length();
        auto f = vector<vector<int>>(n+1, vector<int>(m+1,0));
        
        for(auto i=1;i<=n;++i)
            for(auto j=1;j<=m;++j)
            {
                if(A[i-1]==B[j-1])
                    f[i][j] = f[i-1][j-1]+1;
                f[i][j] = max(f[i][j], max(f[i-1][j], f[i][j-1]));
            }
        
        return f[n][m];
    }
};

