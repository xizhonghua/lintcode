class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        static vector<int> f(100);
        if(n<=1) return 0;
        if(n==2) return 1;
        if(f[n]==0)
            f[n] = fibonacci(n-1) + fibonacci(n-2);
        return f[n];
    }
};
