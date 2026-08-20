class Solution {
public:
    int helper(vector<int>& prices, int ind, int buy, int fee, vector<vector<int>>& dp) {
        if(ind==prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy) {
            int purchase = -prices[ind] + helper(prices, ind+1, 0, fee, dp);
            int notPurchase = 0 + helper(prices, ind+1, 1, fee, dp);
            return dp[ind][buy] = max(purchase, notPurchase);
        }
        int sell = prices[ind] - fee + helper(prices, ind+1, 1, fee, dp);
        int notSell = 0 + helper(prices, ind+1, 0, fee, dp);
        return dp[ind][buy] = max(sell, notSell);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 1, fee, dp);
    }
};