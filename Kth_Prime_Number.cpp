class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        priority_queue<long long, std::vector<long long>, std::greater<long long>> q;
        q.push(1);
        
        unordered_set<long long> ans;
        unordered_set<long long> visited;
        
        while(1)
        {
            auto t = q.top();
            ans.insert(t);
            q.pop();
            if(ans.size() == k+1) return t;
            
            auto ns = { t*3, t*5, t*7 };
            for(auto n : ns)
                if(!visited.count(n)) {
                    visited.insert(n); 
                    q.push(n);
                    
                }
        }
        
        return -1;
    }
};
