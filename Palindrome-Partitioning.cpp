    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s, cur, ans);
        return ans;
    }
private:
    void dfs(const string& s, vector<string>& cur, vector<vector<string>>& ans){
        int l = s.length();
        if(l==0) {
             if(cur.size()>0) ans.push_back(cur);
             return;
        }
        for(int i=0;i<l;++i) {
            string first = s.substr(0, i+1);
            string second = s.substr(i+1);
            if(check(first)) {
                cur.push_back(first);
                dfs(second, cur, ans);
                cur.pop_back();
            }
        }
    }
    
    bool check(const string s) {
        int l = s.length();
        for(int i=0;i<=l/2;++i)
            if(s[i]!=s[l-i-1]) return false;
        return true;
    }
};
