class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        vector<string> ans;
        string cur;
        restore(ans, s, cur, 0);
        return ans;
    }
private:
    void restore(vector<string>& ans, string left, string cur, int depth) {
        if(left.length()==0) {
            if(depth==4) ans.push_back(cur);
            return;
        }
        for(int i=1;i<=min(3, (int)left.length());++i) {
            string temp = left.substr(0, i);
            int ip = stoi(temp);
            if(temp[0]=='0' && temp.length()>1) break;
            if(ip>255) break;
            string new_cur = cur;
            if(new_cur.length()>0) new_cur += '.';
            new_cur += temp;
            restore(ans, left.substr(i), new_cur, depth+1);
        }
    }
};
