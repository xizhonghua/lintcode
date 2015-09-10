class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        set<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        for(int i=1;i<=candidates.size();++i)
            dfs(candidates, target, i, 0, cur, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

private:
    void dfs(vector<int> &n, int target, int d, int s, vector<int>& cur, set<vector<int>>& ans) {
        if(d==0) {
            if(target == 0) 
                ans.insert(cur);
            return;
        }
        for(int i=s;i<n.size();++i) {
            if(n[i]>target) break;
            cur.push_back(n[i]);
            dfs(n, target-n[i], d-1, i, cur, ans);
            cur.pop_back();
        }
    }
};
