class Solution {
public:
// MEMOIZATION
    // int helper(vector<int>& arr, int i, int deleted, vector<vector<int>>& dp) {
    //     if(i<0) return -1e9;
    //     if(dp[i][deleted] != -1) return dp[i][deleted];
    //     if(deleted == 0) {
    //         int newSt = arr[i];
    //         int extend = arr[i] + helper(arr, i-1, deleted, dp);
    //         int del = helper(arr, i-1, 1, dp);
    //         return dp[i][deleted] = max({newSt, extend, del});
    //     }
    //     else {
    //         int newSt = arr[i];
    //         int extend = arr[i] + helper(arr, i-1, deleted, dp);
    //         return dp[i][deleted] = max(newSt, extend);
    //     }
    // }

    // int maximumSum(vector<int>& arr) {
    //     int ans = -1e9;

    //     int n = arr.size();

    //     vector<vector<int>> dp(n, vector<int>(2, INT_MIN));

    //     for (int i = 0; i < arr.size(); i++) {
    //         ans = max(ans, helper(arr, i, 0, dp));
    //         ans = max(ans, helper(arr, i, 1, dp));
    //     }

    //     return ans;
    // }


// TABULATION 
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int ans = -1e9;

        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        
        // base case
        dp[0][0]=arr[0];
        dp[0][1]=arr[0];
        for (int i = 1; i < n; i++) {

            // Deletion not used here
            dp[i][0] = max(
                arr[i],
                arr[i] + dp[i - 1][0]
            );

            // Deletion used here
            dp[i][1] = max({
                arr[i],
                arr[i] + dp[i - 1][1],
                dp[i - 1][0]
            });
        }

        for (int i = 0; i < arr.size(); i++) {
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }

        return ans;
    }
};