class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        int ans = 0;
        vector<vector<int>> f(n*2+1, vector<int>(3,0)); // col, diag1, diga2
        solve(ans, f, 0, n);
        return ans;
    }
private:
    void solve(int& ans, vector<vector<int>>& f, int d, int n) {
        if(n==d) { ans++; return; }
        
        for(int i=0;i<n;++i) {
            if(f[i][0] || f[i+d][1] || f[i-d+n][2]) continue;
            f[i][0] = f[i+d][1] = f[i-d+n][2] = 1;
            solve(ans, f, d+1, n);
            f[i][0] = f[i+d][1] = f[i-d+n][2] = 0;
        }
    }
};
