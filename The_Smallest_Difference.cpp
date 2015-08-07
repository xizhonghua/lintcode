class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());
        
        int d = INT_MAX;
        
        int i=0, j=0;
        while(i<A.size() && j<B.size()) {
            d = min(d, abs(A[i]-B[j]));
            if(A[i]>B[j]) j++; else i++;
        }
        
        return d;
    }
};
