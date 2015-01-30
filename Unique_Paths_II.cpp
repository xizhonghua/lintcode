class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int n = obstacleGrid.size();
        if(n==0) return 0;
        int m = obstacleGrid[0].size();
        
        auto f = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        f[1][1] = 1 - obstacleGrid[0][0];
        
        for(auto i=1;i<=n;++i)
            for(auto j=1;j<=m;++j)
                if(i*j==1 || obstacleGrid[i-1][j-1] == 1) 
                    continue;
                else
                    f[i][j] = f[i-1][j] + f[i][j-1];
                    
        return f[n][m];
    }
};
