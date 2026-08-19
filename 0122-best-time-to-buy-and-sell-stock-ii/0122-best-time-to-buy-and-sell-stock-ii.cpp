class Solution {
public:
    int helper(vector<int>& p, int ind, bool buy, vector<vector<int>>& dp) {
        if(ind == p.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit=0;
        if(buy) {
            profit = max(-p[ind]+helper(p, ind+1, 0, dp), helper(p, ind+1, 1, dp));
        }
        else {
            profit = max(p[ind]+helper(p, ind+1, 1, dp), helper(p, ind+1, 0, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 1, dp);
    }
};