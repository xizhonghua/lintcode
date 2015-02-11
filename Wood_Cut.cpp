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
        
        std::sort(L.begin(), L.end(), std::greater<int>());
        
        if(k==1) return L[0];
        
        return bs(L, k, 1, L[0]);
    }

private:
    int bs(const vector<int>& L, const int k, int l, int r)
    {
        if(l>=r) return r;
        
        auto mid = ((long long)(l)+r)/2;
        
        // cout<<"l = "<<l<<" r = "<<r<< " mid = "<<mid<<endl;
        
        if(cut(L, k, mid))
        {
            return cut(L, k, mid+1) ? bs(L, k, mid+1, r) : mid;
        }
        else
        {
            return bs(L, k, l, mid-1);
        }
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
