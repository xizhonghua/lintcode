class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];
        
        int max_len = INT_MAX;
        
        for(const auto& s : strs) max_len = std::min(max_len, (int)s.size());
        
        string ans("");
        bool same = true;
        for(int i=0;i<max_len;++i) {
            char c = strs[0][i];
            for(int j=1;j<strs.size();++j)
                if(strs[j][i] != c) {
                    same = false;
                    break;
                }
            if(!same) break;
            ans += c;
        }
        
        return ans;
    }
};
