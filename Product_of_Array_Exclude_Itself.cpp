class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        const auto size = nums.size();
        if(size==1) return {};
        
        vector<vector<long long>> f(size+1, vector<long long>(size+1, 1));
        
        // f[i][j] == A[i] * A[i+1] * ... * A[j]
        for(auto i=1;i<=size;++i)
            for(auto j=i;j<=size;++j)
                f[i][j] = f[i][j-1]*nums[j-1];
        
        vector<long long> b(size, 1);
        for(auto i=0;i<size;++i)
        {
            if(i==0) b[i] = f[2][size];
            else if(i==size-1) b[i] = f[1][size-1];
            else b[i] = f[1][i] * f[i+2][size];
        }
        
        return b;
    }
};
