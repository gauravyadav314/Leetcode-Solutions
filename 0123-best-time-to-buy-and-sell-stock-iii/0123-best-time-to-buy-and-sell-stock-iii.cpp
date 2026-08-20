class Solution {
public:
//memoization
    // int helper(vector<int>& nums, int ind, int cap, int buy, vector<vector<vector<int>>>& dp) {
    //     if(cap == 0) return 0;
    //     if(ind == nums.size()) return 0;
    //     if(dp[ind][cap][buy] != -1) return dp[ind][cap][buy];
    //     if(buy) {
    //         int purchase = -nums[ind] + helper(nums, ind+1, cap, 0, dp);
    //         int notPurchase = 0 + helper(nums, ind+1, cap, 1, dp);
    //         return dp[ind][cap][buy] = max(purchase, notPurchase);
    //     }
    //     int sell = nums[ind] + helper(nums, ind+1, cap-1, 1, dp);
    //     int notSell = 0 + helper(nums, ind+1, cap, 0, dp);
    //     return dp[ind][cap][buy] = max(sell, notSell);
    // }
    // int maxProfit(vector<int>& p) {
    //     int n = p.size();
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
    //     return helper(p, 0, 2, 1, dp);
    // }

// Tabulation
    // int maxProfit(vector<int>& p) {
    //     int n = p.size();
    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));
    //     for(int i=n-1; i>=0; i--) {
    //         for(int cap=1; cap<=2; cap++) {
    //             for(int buy=0; buy<=1; buy++) {
    //                 if(buy) {
    //                     int purchase = -p[i] + dp[i+1][cap][0];
    //                     int notPurchase = 0 + dp[i+1][cap][1];
    //                     dp[i][cap][buy] = max(purchase, notPurchase);
    //                 }
    //                 else {
    //                     int sell = p[i] + dp[i+1][cap-1][1];
    //                     int notSell = 0 + dp[i+1][cap][0];
    //                     dp[i][cap][buy] = max(sell, notSell);
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0][2][1];
    // }

// SpaceOptimization 
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> after(3, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--) {
            vector<vector<int>> curr(3, vector<int>(2, 0));
            for(int cap=1; cap<=2; cap++) {
                for(int buy=0; buy<=1; buy++) {
                    if(buy) {
                        int purchase = -p[i] + after[cap][0];
                        int notPurchase = 0 + after[cap][1];
                        curr[cap][buy] = max(purchase, notPurchase);
                    }
                    else {
                        int sell = p[i] + after[cap-1][1];
                        int notSell = 0 + after[cap][0];
                        curr[cap][buy] = max(sell, notSell);
                    }
                }
            }
            after = curr;
        }
        return after[2][1];
    }
};