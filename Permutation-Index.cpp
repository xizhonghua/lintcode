class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        vector<int> r(A.size(), 0);
        for(int i=0;i<A.size();++i)
            for(int j=i+1;j<A.size();++j)
                if(A[j]<A[i]) r[i]++;
        
        long long ans = 1;
        for(int i=0;i<A.size();++i)
            ans += r[i]==0 ? 0 : r[i]*fact(A.size()-i-1);
        return ans;
    }
private:
    long long fact(int n) {
        return n<=1 ? 1L : n*fact(n-1);
    }
};
