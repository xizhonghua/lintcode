class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        std::sort(num.begin(), num.end(), 
            [](const int& a, const int& b) -> bool {
                auto sa = std::to_string(a);
                auto sb = std::to_string(b);
                return sa+sb > sb+sa;
        });
        
        string ans;
        for(const auto& n : num)
            ans += std::to_string(n);
            
        while(ans[0]=='0' && ans.length()>1) 
            ans.erase(0, 1);
        
        return ans;
    }
};
