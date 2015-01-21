class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int index = binarySearch(array, target, 0, array.size()-1);
        if(index == -1) return -1;
        // found
        int t = index;
        while(true)
        {
            t = binarySearch(array, target, 0, index-1);
            if(t==-1) break;
            index = t;
        }
        return index;
    }
private:
    int binarySearch(vector<int> &array, const int target, const int l, const int r)
    {
        if(l>r) return -1;
        const int mid = (l+r)/2;
        if(array[mid] == target) return mid;
        if(array[mid] > target)
            return binarySearch(array, target, l, mid-1);
        return binarySearch(array, target, mid+1, r);
    }
};
