class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if(grid.size()==0) return 0;
        int h = grid.size();
        int w = grid[0].size();
        
        int ans = 0;
        for(int i=0;i<h;++i)
            for(int j=0;j<w;++j)
                if(grid[i][j] == 1) {
                    ++ ans;
                    mark(i,j,h,w,grid);
                }
        return ans;
    }
private:
    void mark(int i, int j, int h, int w, vector<vector<bool>>& grid) {
        grid[i][j] = 0;
        if(i>0 && grid[i-1][j] == 1) mark(i-1,j,h,w,grid);
        if(j>0 && grid[i][j-1] == 1) mark(i,j-1,h,w,grid);
        if(i<h-1 && grid[i+1][j] == 1) mark(i+1,j,h,w,grid);
        if(j<w-1 && grid[i][j+1] == 1) mark(i,j+1,h,w,grid);
    }
};
