/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        
        // write your code here
        
        int l=1;
        int h=n;
        
        while(true)
        {
            int mid = (l+h)/2;
            bool rm = VersionControl::isBadVersion(mid);
            
            if(rm)
            {
                h = mid;
            }
            else
            {
                l = mid+1;
            }
            
            if(l==h) return h;
        }
        
        return -1;
    }
};

