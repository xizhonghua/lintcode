class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int c = 0;
        for(int i=0;i<=n;i++)
        {
            int t = i;
            do {
                if(t%10==k) ++c;
                t/=10;
            } while(t);
        }
        
        return c;
    }
};
