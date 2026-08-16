class Solution {
public:
    int helper(vector<int>& coins, int amount, int ind,
               vector<vector<int>>& dp) {
        if(ind == 0) {
            if(amount % coins[0] == 0) return amount/coins[0];
            else return INT_MAX;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int mini = INT_MAX;
        int notTake = helper(coins, amount, ind-1, dp);
        int take = INT_MAX;
        if (coins[ind] <= amount) {
            take = helper(coins, amount-coins[ind], ind, dp);
            if(take != INT_MAX) take++;
        }
        mini = min(take, notTake);

        return dp[ind][amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(coins, amount, n-1, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};