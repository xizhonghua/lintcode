class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int ans = 0;
        while(num>0) {
            ans += num%2;
            num>>=1;
        }
        return ans;
    }
};
