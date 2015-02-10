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
        
        vector<vector<long long>> f(size, vector<long long>(size, 1));
        
        // f[i][j] == A[i] * A[i+1] * ... * A[j]
        for(auto i=0;i<size;++i)
            for(auto j=i;j<size;++j)
                f[i][j] = (j==0 ? 1 : f[i][j-1])*nums[j];
        
        vector<long long> b(size, 1);
        for(auto i=0;i<size;++i)
        {
            if(i==0) b[i] = f[1][size-1];
            else if(i==size-1) b[i] = f[0][size-2];
            else b[i] = f[0][i-1] * f[i+1][size-1];
        }
        
        return b;
    }
};
