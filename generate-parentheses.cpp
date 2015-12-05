class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        g(0,0,0,n,cur,ans);
        return ans;
    }
private:
    void g(int ol, int l, int r, int n, string cur, vector<string>& ans) {
        
        if(l+r==2*n) {
            ans.push_back(cur);
            return;
        }
        
        if(l<n) 
            g(ol+1, l+1, r, n, cur+'(', ans);
        if(r<n && ol>0)
            g(ol-1, l, r+1, n, cur+')', ans);
    }
};
