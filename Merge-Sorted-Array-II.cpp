class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> ans;
        auto ita = A.cbegin();
        auto itb = B.cbegin();
        
        while(ita != A.cend() || itb != B.cend()) {
            if(ita == A.cend()) {
                ans.insert(ans.end(), itb, B.cend());
                break;
            }
            if(itb == B.cend()) {
                ans.insert(ans.end(), ita, A.cend());
                break;
            }
            if(*ita < *itb) {
                ans.push_back(*ita);
                ita++;
            } else {
                ans.push_back(*itb);
                itb++;
            }
        }
        
        return ans;
    }
};
