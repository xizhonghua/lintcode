class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        std::sort(letters.rbegin(), letters.rend());
    }
};
