class Solution {
public:
    int helper(vector<int>& coins, int amount, int ind,
               vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (ind == coins.size())
            return INT_MAX;

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int mini = INT_MAX;

        for (int i = ind; i < coins.size(); i++) {

            if (coins[i] <= amount) {

                int ans = helper(coins, amount - coins[i], i, dp);

                if (ans != INT_MAX)
                    mini = min(mini, ans + 1);
            }
        }

        return dp[ind][amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(coins, amount, 0, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};