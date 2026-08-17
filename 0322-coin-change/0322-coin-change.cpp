class Solution {
public:
// memoization
    // int helper(vector<int>& coins, int amount, int ind,
    //            vector<vector<int>>& dp) {
    //     if(ind == 0) {
    //         if(amount % coins[0] == 0) return amount/coins[0];
    //         else return INT_MAX;
    //     }

    //     if (dp[ind][amount] != -1)
    //         return dp[ind][amount];

    //     int mini = INT_MAX;
    //     int notTake = helper(coins, amount, ind-1, dp);
    //     int take = INT_MAX;
    //     if (coins[ind] <= amount) {
    //         take = helper(coins, amount-coins[ind], ind, dp);
    //         if(take != INT_MAX) take++;
    //     }
    //     mini = min(take, notTake);

    //     return dp[ind][amount] = mini;
    // }

    // int coinChange(vector<int>& coins, int amount) {

    //     int n = coins.size();

    //     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    //     int ans = helper(coins, amount, n-1, dp);

    //     return (ans == INT_MAX) ? -1 : ans;
    // }

// tabulation
//  int coinChange(vector<int>& coins, int amount) {

//         int n = coins.size();

//         vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
//         for(int target=0; target<=amount; target++) {
//             if(target % coins[0] == 0) dp[0][target] = target/coins[0];
//             else dp[0][target] = INT_MAX;
//         }
//         for(int i=1; i<n; i++) {
//             for(int target=0; target<=amount; target++) {
//                 int notTake = dp[i-1][target];
//                 int take = INT_MAX;
//                 if(coins[i] <= target) {
//                     take = dp[i][target-coins[i]];
//                     if(take != INT_MAX) take++;
//                 }
//                 dp[i][target] = min(take, notTake);
//             }
//         }
//         return (dp[n-1][amount]==INT_MAX)? -1: dp[n-1][amount];
//     }

// spaceOptimization
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<int> prev(amount+1, 0);
        for(int target=0; target<=amount; target++) {
            if(target%coins[0] == 0) prev[target] = target/coins[0];
            else prev[target] = INT_MAX;
        }

        for(int i=1; i<n; i++) {
            vector<int> curr(amount+1, 0);
            for(int target=0; target<=amount; target++) {
                int notTake = prev[target];
                int take = INT_MAX;
                if(coins[i] <= target) {
                    take = curr[target-coins[i]];
                    if(take != INT_MAX) take++;
                }
                int mini = min(take, notTake);
                curr[target] = mini;
            }
            prev = curr;
        }
        return (prev[amount] == INT_MAX)? -1 : prev[amount];
    }

};