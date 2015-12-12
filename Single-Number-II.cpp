class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        int ones(0), twos(0), threes(0);
        
        for(const int n : A) {
            twos = twos | (ones & n);
            ones ^= n;
            threes = twos & ones;
            ones &= ~threes;
            twos &= ~threes;
        }
        
        return ones;
    }
};
