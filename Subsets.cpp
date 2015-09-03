class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	std::sort(nums.begin(), nums.end());
    	vector<vector<int>> ans;
    	vector<int> cur;
    	for(int i=0;i<=nums.size();++i)
    	    dfs(nums, 0, i, 0, cur, ans);
    	return ans;
    }
private:
    void dfs(vector<int>& nums, int d, int k, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if (d==k) {
            ans.push_back(cur);
            return;
        }
        
        for(int i=s;i<nums.size();++i) {
            cur.push_back(nums[i]);
            dfs(nums, d+1, k, i+1, cur, ans);
            cur.pop_back();
        }
    }
};
