class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        stringstream ss(s);
        string ans;
        while(ss>>s) {
            std::reverse(s.begin(), s.end());
            if(!ans.empty()) ans += " ";
            ans += s;
        }
        
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
