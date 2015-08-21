class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }
    
private:
    int findMin(const vector<int> &num, int l, int r) {
        if(r == l) return num[r];
        if(r - l == 1) return min(num[l], num[r]);
        
        int mid = (l + r) / 2;
        
        if(num[mid] >= num[l] && num[mid] >= num[r]
        || num[mid] <= num[l] && num[mid] <= num[r]) {
            return min(findMin(num, l, mid-1), findMin(num, mid, r));
        }
        
        else if(num[l] <= num[mid] && num[mid] <= num[r]) {
            return num[l];
        }
        else {
            return num[r];
        }
    } 
};
