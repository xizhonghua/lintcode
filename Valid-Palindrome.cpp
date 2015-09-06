class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        int l = s.length();
        int i = 0;
        int j = l-1;
        while(i<j) {
            while(!isalpha(s[i]) && !isdigit(s[i]) && i<l) ++i;
            while(!isalpha(s[j]) && !isdigit(s[j]) && j>=0) --j;
            if(i==l || j<0) break;
            if (tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};
