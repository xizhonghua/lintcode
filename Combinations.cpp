class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(n, k, 1, 0, cur, ans);
        return ans;
    }

private:
    void dfs(const int n, const int k, const int s, const int d, vector<int>& cur, vector<vector<int>>& ans) {
        if(d == k) {
            ans.push_back(cur);
            return;
        }
        
        for(int i=s;i<=n;i++) {
            cur.push_back(i);
            dfs(n, k, i+1, d+1, cur, ans);
            cur.pop_back();
        }
    }
};
