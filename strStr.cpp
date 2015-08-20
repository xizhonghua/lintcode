class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if(source == nullptr || target == nullptr) return -1;
        
        if(strcmp(source, target)==0) return 0;
        
        const int len_src = strlen(source);
        const int len_tgt = strlen(target);
        
        for(int i=0;i<len_src-len_tgt+1;++i)
        {
            bool found = true;
            for(int j=0;j<len_tgt;++j)
            {
                if(source[i+j] != target[j]) {
                    found = false;
                    break;
                }
            }
            if(found) return i;
        }
        
        return -1;
    }
};

