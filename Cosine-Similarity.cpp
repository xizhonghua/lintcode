class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        double na = norm(A);
        double nb = norm(B);
        if(na==0 || nb==0 || A.size()!=B.size()) return 2.0;
        double s = 0.0;
        for(int i=0;i<A.size();++i)
            s += A[i]*B[i];
            
        return s / na / nb;
    }
private:
    double norm(const vector<int> V) {
        double n = 0.0;
        for(const auto v : V)
            n += v*v;
        return sqrt(n);
    }
};

