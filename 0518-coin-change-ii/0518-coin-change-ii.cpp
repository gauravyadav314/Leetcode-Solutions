class Solution {
public:

// memoization
    // int helper(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp) {
    //     if(ind == 0) {
    //         if(amount%coins[ind] == 0) return 1;
    //         else return 0;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int notTake = helper(coins, ind-1, amount, dp);
    //     int take = 0;
    //     if(coins[ind] <= amount) take = helper(coins, ind, amount-coins[ind], dp);
    //     return dp[ind][amount] = take + notTake;
    // }
    // int change(int amount, vector<int>& coins) {
    //     vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
    //     return helper(coins, coins.size()-1 , amount, dp);
    // }

// tabulation
    int change(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));

    for(int i=0; i<=amount; i++) {
        if(i%coins[0] == 0)
            dp[0][i] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int a=0; a<=amount; a++) {

            long long notTake = dp[i-1][a];

            long long take = 0;

            if(coins[i] <= a)
                take = dp[i][a-coins[i]];

            if(take > INT_MAX - notTake)
                dp[i][a] = INT_MAX;
            else
                dp[i][a] = take + notTake;
        }
    }

    return dp[n-1][amount];
}
};