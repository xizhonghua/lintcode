class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        const auto n = grid.size();
        if(n==0) return 0;
        const auto m = grid[0].size();
        
        for(auto i=0;i<n;++i)
            for(auto j=0;j<m;++j)
            {
                if(i==0 && j==0) continue;
                if(i==0) grid[i][j] += grid[i][j-1];
                else if(j==0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        
        return grid[n-1][m-1];
    }
};

