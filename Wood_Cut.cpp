class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here        
        if(L.size()==0) return 0;
        
        const auto max_element = *std::max_element(L.begin(), L.end());
        
        if(k==1) return max_element;
        
        return bs(L, k, 1, max_element);
    }

private:
    int bs(const vector<int>& L, const int k, int l, int r)
    {
        if(l>=r) return r;
        
        auto mid = ((long long)(l)+r)/2;
        
        if(cut(L, k, mid))
            return cut(L, k, mid+1) ? bs(L, k, mid+1, r) : mid;
        
        return bs(L, k, l, mid-1);
    }
    
    bool cut(const vector<int>& L, const int k, const int len) {
        
        auto c = 0;
        
        for(auto w : L)
        {
            c += w/len;
            if(c>=k) return true;
        }
        
        return false;
    }
};
