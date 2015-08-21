class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        set<vector<int>> s;
        map<int, set<int>> o;
        int l = (int)nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        for(int i=0;i<l;++i)
            o[nums[i]].insert(i);
        
        for(int i=0;i<l;++i)
            for(int j=i+1;j<l;++j) {
                int n = 0 - nums[i] - nums[j];
                if(!o.count(n)) continue;
                set<int> p = o[n];
                p.erase(i);
                p.erase(j);
                if(p.size() == 0) continue;
                vector<int> v = {nums[i], nums[j], n};
                std::sort(v.begin(), v.end());
                s.insert(v);
            }
        
        return vector<vector<int>>(s.begin(), s.end());
    }
};

