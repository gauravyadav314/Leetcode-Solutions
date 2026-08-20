class Solution {
public:
    int helper(vector<int>& p, int ind, int buy, vector<vector<int>>& dp) {
        if(ind>=p.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy) {
            int purchase = -p[ind] + helper(p, ind+1, 0, dp);
            int notPurchase = 0 + helper(p, ind+1, 1, dp);
            return dp[ind][buy] = max(purchase, notPurchase);
        }
        int sell = p[ind] + helper(p, ind+2, 1, dp);
        int notSell = 0 + helper(p, ind+1, 0, dp);
        return dp[ind][buy] = max(sell, notSell);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 1, dp);
    }
};