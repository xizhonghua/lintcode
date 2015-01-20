class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int num = 0;
        for(auto v : A)
            num ^= v;
        return num;
    }
};

