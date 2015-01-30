class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int min_price = INT_MAX;
        int max_profit = 0;
        for(int i=0;i<prices.size();++i)
        {
            max_profit = max(max_profit, prices[i]-min_price);
            min_price = min(min_price, prices[i]);            
        }
        
        return max_profit;
    }
};

