// 35 ms
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int profit = 0;
        for(int i=1;i<prices.size();++i)
            profit += max(0, prices[i] - prices[i-1]);
        return profit;
    }
};
