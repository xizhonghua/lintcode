class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(0, k, 0, target, 0, A, cur, ans);
        return ans;
    }
private:
    void dfs(int depth, int k, int sum, int target, int start, const vector<int>& A, vector<int>& cur, vector<vector<int>>& ans) {
        if(depth==k) {
            if(sum == target) ans.push_back(cur);
            return;
        }
        for(int i=start;i<A.size();++i) {
            if(sum+A[i]>target) continue;
            cur.push_back(A[i]);
            dfs(depth+1, k, sum+A[i], target, i+1, A, cur, ans);
            cur.pop_back();
        }
    }
};
