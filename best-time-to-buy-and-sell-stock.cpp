/**
* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize minimum price to a large value and max profit to 0
        int minPrice = INT_MAX;
        int maxProfit = 0;

        // Traverse through the prices array
        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum price so far
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Calculate the potential profit if sold today
            int profit = prices[i] - minPrice;
            
            // Update the maximum profit if current profit is higher
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        // Return the maximum profit
        return maxProfit;
    }
};