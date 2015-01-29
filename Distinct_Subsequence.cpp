class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(const string &S, const string &T) {
        // write your code here
        const auto n = S.length();
        const auto m = T.length();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        
        for(auto i=0;i<n;++i) f[i][0] = 1;
        
        for(auto i=0;i<=n;++i)
            for(auto j=0;j<=min((int)m,i);++j)
            {
                if(i*j==0) continue;
                
                if(S[i-1] == T[j-1])
                {
                    f[i][j] = f[i-1][j-1] + f[i-1][j];
                }
                else
                {
                    f[i][j] = f[i-1][j];
                }
            }
        
        return f[n][m];
    }
};

