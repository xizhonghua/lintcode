class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<vector<int>> f(m+2, vector<int>(n+2,0));
        f[1][1] = 1;
        
        for(auto i=1;i<=m;i++)
            for(auto j=1;j<=n;j++) {
                if(i==1 && j==1) continue;
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        
        return f[m][n];
    }
};

