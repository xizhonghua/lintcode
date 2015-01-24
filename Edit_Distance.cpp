class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        
        for(int i=0;i<=m;i++) f[i][0] = i;
        for(int i=0;i<=n;i++) f[0][i] = i;
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1] == word2[j-1])
                    f[i][j] = min(f[i-1][j-1], min(f[i][j-1], f[i-1][j])+1);
                else
                    f[i][j] = min(f[i-1][j-1], min(f[i][j-1], f[i-1][j]))+1;
            }
        
        return f[m][n];
    }
};

