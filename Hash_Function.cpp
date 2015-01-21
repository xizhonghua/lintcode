class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        
        long long h = 0;
        for(const auto c : key)
        {
            h = (h * 33 + c) % HASH_SIZE;
        }
        return h;
    }
};
