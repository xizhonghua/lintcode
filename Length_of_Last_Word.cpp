class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int l = 0;
        for(const auto& c : s)
            l = c == ' ' ? 0 : l + 1;
        return l;
    }
};
