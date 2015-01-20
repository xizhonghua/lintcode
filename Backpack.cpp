// 4134 ms
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        map<int,bool> p;
        p[0] = true;
        
        for(auto v : A)
        {
            for(auto it = p.rbegin(); it!=p.rend(); ++it)
            {
                int key = it->first + v;
                if(key>m) continue;
                
                p[key] = true;
            }
        }
        
        return p.rbegin()->first;
    }
};
