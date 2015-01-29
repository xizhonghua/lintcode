class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        unordered_map<char,int> m1, m2;
        for(const auto c: s)
            ++m1[c];
        for(const auto c: t)
            ++m2[c];
        return m1 == m2;
    }
};
