class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        unordered_set<int> s;
        while(!s.count(n) && n!=1) {
            s.insert(n);
            n = ss(n);
        }
        return n==1;
    }
private:
    int ss(int n) {
        int sum = 0;
        while(n>0) {
            sum += (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
};
