class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        map<char,int> m;
        
        int ans = 0;
        int l = -1;
        
        for(int i=0;i<s.length();++i) {
            char ch = s[i];
            if(m.count(ch))
                l = max(l, m[ch]);
            m[ch] = i;
            ans = max(ans, i-l);
        }
        
        return ans;
    }
};
