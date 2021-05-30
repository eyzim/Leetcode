/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // only have one day, no way to sell
        if(prices.size() == 1)  return 0;

        int buy = INT_MAX, profit = 0;

        for(auto i:prices)
        {
            // if there is a chance to get the minimal cost/buy
            buy = min(i, buy);

            // calculate the maximun profit
            profit = max(i-buy, profit);
        }

        return profit;
    }
};
// @lc code=end
