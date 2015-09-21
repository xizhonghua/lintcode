class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        
        std::sort(A.begin(), A.end());
        
        vector<int> ans;
        for(const auto q : queries) {
            auto iter = lower_bound(A.begin(), A.end(), q);
            ans.push_back(iter - A.begin());
        }
        
        return ans;
    }

};
