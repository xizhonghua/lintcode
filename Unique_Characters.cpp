class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        unsigned int f[(256+7)/8];
        for(const auto c : str) {
            if (f[c/8] & (1 << (c%8))) return false;
            f[c/8] |= (1 << (c%8));
        }
        return true;
    }
};
