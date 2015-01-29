class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, int> s;
        vector<string> ans;
        for(const auto str : strs)
        {
            auto t = str;
            sort(t.begin(), t.end());
            ++s[t];
        }
        
        for(const auto str : strs)
        {
            auto t = str;
            sort(t.begin(), t.end());
            if(s[t] > 1)
            {
                ans.push_back(str);
            }
        }
        
        return ans;
    }
};

