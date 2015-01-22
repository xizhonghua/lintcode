// Given 2*n + 2 numbers, every numbers occurs twice except two, find them.

// Example
// Given [1,2,2,3,4,4,5,3] return 1 and 5

// Challenge
// O(n) time, O(1) extra space.

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        
        int t = 0;
        for(const auto v : A)
            t ^= v;
        
        int mask = t & ~(t-1);
        
        int x = 0;
        int y = 0;
        
        for(const auto v : A)
        {
            if(v & mask) 
                x^=v;
            else
                y^=v;
        }
        
        return vector<int>{x,y};
    }
};
 
