class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        vector<vector<int>> f(n*2+1, vector<int>(3,0)); // col, diag1, diga2
        solve(ans, cur, f, 0, n);
        return ans;
    }
private:
    void solve(vector<vector<string>>&ans, vector<string>& cur, vector<vector<int>>& f, int d, int n) {
        if(n==d) {
            ans.push_back(cur);
            return;
        }
        
        for(int i=0;i<n;++i) {
            if(f[i][0] || f[i+d][1] || f[i-d+n][2]) continue;
            f[i][0] = f[i+d][1] = f[i-d+n][2] = 1;
            cur[d][i] = 'Q';
            solve(ans, cur, f, d+1, n);
            cur[d][i] = '.';
            f[i][0] = f[i+d][1] = f[i-d+n][2] = 0;
        }
    }
};

