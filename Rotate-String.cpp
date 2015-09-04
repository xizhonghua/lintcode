class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        const int l = str.length();
        if(l==0) return;
        
        offset = offset % l;
        if(offset==0) return;
        
        while(offset--) {
            char tmp = str.back();
            for(int i=l-1;i>=0;--i)
                str[i] = str[i-1];
            str[0] = tmp;
        }
    }
};
