class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x<=1) return x;
        return sqrt(x, 1, x);
    }
private:
    int sqrt(int x, long long l, long long r) {
        if(r==l) return l;
        if(r==l+1) {
            return r*r <= x ? r : l;
        }
        auto mid = l+(r-l)/2;
        auto t = mid*mid;
        
        if(t == x) return mid;
        
        return t > x ? sqrt(x, l, mid-1) : sqrt(x, mid, r);
    }
};
