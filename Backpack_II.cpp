class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        map<int, int> f{{0,0}};
        
        auto max_v = INT_MIN;
        
        for(int i=0;i<A.size();++i) {
            auto it = f.rbegin();
            while(it != f.rend()) {
                const int tw = A[i] + it->first;
                if (tw <= m) 
                {
                    f[tw] = std::max(f[tw], it->second+V[i]);
                    max_v = std::max(f[tw], max_v);
                }
                ++it;
            }
        }
        
        return max_v;
    }
};
