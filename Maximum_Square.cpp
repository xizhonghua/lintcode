class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        const int rows = matrix.size();
        if(rows == 0) return 0;
        const int cols = matrix[0].size();
        
        vector<vector<int>> f(rows+1, vector<int>(cols+1,0));
        
        int ans = 0;
        
        for(int i=1;i<=rows;++i)
            for(int j=1;j<=cols;++j)
            {
                if(matrix[i-1][j-1] == 0) {
                    f[i][j] = 0;
                    continue;
                }
                
                const int t = f[i-1][j-1];
                
                bool s = true;
                
                for(int k=1;k<=t;k++) {
                    if (matrix[i-1][j-1-k]==0) { s = false; break; }
                    if (matrix[i-1-k][j-1]==0) { s = false; break; }
                }
                
                f[i][j] = s ? t + 1 : 1;
                
                ans = max(ans, f[i][j]);
            }
        
        return ans*ans;
    }
};
