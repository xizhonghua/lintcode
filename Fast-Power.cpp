class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if(n==0) return 1 % b;
        if(n==1) return a % b;
        long long t1 = fastPower(a, b, n/2) % b;
        long long t2 = fastPower(a, b, n-(n/2)*2) % b;
        return ((t1*t1) % b *t2) % b;
    }
};
