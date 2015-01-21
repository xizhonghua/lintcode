class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        int count = 0;
        for(int i=0;i<31;i++)
        {
            if(n & (1<<i)) count++;
        }
        
        return count==1;
    }
};
