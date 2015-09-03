class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
    	vector<int> nums = S;
    	std::sort(nums.begin(), nums.end());
    	
    	set<vector<int>> ans;
    	vector<int> cur;
    	
    	for(int i=0;i<=nums.size();++i)
    	    dfs(nums, 0, i, 0, cur, ans);
    	return vector<vector<int>>(ans.begin(), ans.end());
    }
private:
    void dfs(const vector<int>& S, int d, int k, int s, vector<int>& cur, set<vector<int>>& ans) {
        if (d==k) {
            ans.insert(cur);
            return;
        }
        
        for(int i=s;i<S.size();++i) {
            cur.push_back(S[i]);
            dfs(S, d+1, k, i+1, cur, ans);
            cur.pop_back();
        }
    }
};

