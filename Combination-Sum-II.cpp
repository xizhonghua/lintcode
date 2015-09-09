class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        set<vector<int>> ans;
        vector<int> cur;
        
        std::sort(num.begin(), num.end());
        
        for(int i=1;i<=num.size();++i)
            dfs(num, target, 0, i, 0, cur, ans);
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
private:
    void dfs(vector<int> &num, int target, int d, int n, int s, vector<int>& cur, set<vector<int>>& ans) {
        if(d==n) {
            if(target == 0) {
                ans.insert(cur);
                return;
            }
        }
        
        for(int i=s;i<num.size();++i) {
            if(num[i]>target) break;
            cur.push_back(num[i]);
            dfs(num, target - num[i], d+1, n, i+1, cur, ans);
            cur.pop_back();
        }
    }
};
