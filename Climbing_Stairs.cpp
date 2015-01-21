class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(m_cache.count(n)) return m_cache[n];
        int ways = n<=2?n:climbStairs(n-1)+climbStairs(n-2);
        m_cache[n] = ways;
        return ways;
    }
private:
    map<int,int> m_cache;
};

