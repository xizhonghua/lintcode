class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        if(a.length() < b.length())
            std::swap(a,b);
        
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        while(b.length()<a.length()) b += "0";
        a += '0';
        
        for(int i=0;i<b.length();++i) {
            a[i] += b[i] - '0';
            if(a[i] > '1') {
                a[i] -= 2;
                a[i+1] ++;
            }
        }
        
        if (a.back() == '0') a.pop_back();
        
        std::reverse(a.begin(), a.end());
        
        return a;
    }
};
