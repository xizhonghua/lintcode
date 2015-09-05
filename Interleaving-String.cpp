class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if(l3 != l1+l2) return false;
        if(s1==s3 || s2==s3) return true;
        
        vector<vector<int>> f(l1+1, vector<int>(l2+1, 0));
        
        for(int i=0;i<=l1;++i)
            for(int j=0;j<=l2;++j) {
                char c1 = i==0 ? '?' : s1[i-1];
                char c2 = j==0 ? '?' : s2[j-1];
                
                if(i>0 && j>0) {
                    int ml = f[i-1][j-1];
                    if(c1 == s3[ml] && c2 == s3[ml+1]
                    || c1 == s3[ml+1] && c2 == s3[ml])
                        f[i][j] = ml+2;
                }
                
                if(i>0) {
                    int ml = f[i-1][j];
                    if(c1 == s3[ml])
                        f[i][j] = max(f[i][j], ml+1);
                }
                
                if(j>0) {
                    int ml = f[i][j-1];
                    if(c2 == s3[ml])
                        f[i][j] = max(f[i][j], ml+1);
                }
            }
        
        return f[l1][l2] == l3;
    }
};
