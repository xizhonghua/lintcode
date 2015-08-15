class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        vector<int> ans(digits.size()+1, 0);
        std::reverse(digits.begin(), digits.end());
        ans[0] = 1;
        for(int i=0;i<digits.size();++i) {
            ans[i] += digits[i];
            if(ans[i] > 9) {
                ans[i] -= 10;
                ans[i+1] ++;
            }
        }
        
        while(ans.back() == 0) ans.pop_back();
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
