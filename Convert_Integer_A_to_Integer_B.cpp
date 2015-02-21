class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int ans = 0;
        int mask = 1;
        for(int i=0;i<32;++i)
        {
            ans += ((a & mask) ^ (b & mask) ? 1 : 0);
            mask <<= 1;
        }
        
        return ans;
    }
};
