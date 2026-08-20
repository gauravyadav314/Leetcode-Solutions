class Solution {
public:
    int helper(vector<int>& nums, int ind, int cap, int buy, vector<vector<vector<int>>>& dp) {
        if(cap == 0) return 0;
        if(ind == nums.size()) return 0;
        if(dp[ind][cap][buy] != -1) return dp[ind][cap][buy];
        if(buy) {
            int purchase = -nums[ind] + helper(nums, ind+1, cap, 0, dp);
            int notPurchase = 0 + helper(nums, ind+1, cap, 1, dp);
            return dp[ind][cap][buy] = max(purchase, notPurchase);
        }
        int sell = nums[ind] + helper(nums, ind+1, cap-1, 1, dp);
        int notSell = 0 + helper(nums, ind+1, cap, 0, dp);
        return dp[ind][cap][buy] = max(sell, notSell);
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return helper(p, 0, 2, 1, dp);
    }
};