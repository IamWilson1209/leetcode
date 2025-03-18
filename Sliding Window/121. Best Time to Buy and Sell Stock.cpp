class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            /* set min price */
            int min_price = prices[0];
            int ans = 0;
            /* check each day sell the stock will gain better profit, and update */
            for (int i = 1; i < prices.size(); i++) {
                min_price = min(prices[i], min_price);
                ans = max(ans, prices[i] - min_price);
            }
            return ans;
        }
    };