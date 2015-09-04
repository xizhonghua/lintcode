class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> nums) {
        ans.clear();
        cur.clear();
        used.clear();
        if(nums.size()==0) return vector<vector<int>>();
        
        dfs(nums, 0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
private:
    void dfs(const vector<int>& nums, int depth) {
        if(depth==nums.size()) {
            ans.insert(cur);
            return;
        }
        for(int i=0;i<nums.size();++i) {
            if(used.count(i)) continue;
            used.insert(i);
            cur.push_back(nums[i]);
            dfs(nums, depth+1);
            cur.pop_back();
            used.erase(i);
        }
    }
    
    set<vector<int>> ans;
    vector<int> cur;
    set<int> used;
};
