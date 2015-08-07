class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> ans;
        int max_len = 0;
        for(const auto& word : dictionary) {
            if(word.length()>max_len) {
                ans.clear();
                max_len = word.length();
            }
            if(word.length()==max_len)
                ans.push_back(word);
        }
        return ans;
    }
};
