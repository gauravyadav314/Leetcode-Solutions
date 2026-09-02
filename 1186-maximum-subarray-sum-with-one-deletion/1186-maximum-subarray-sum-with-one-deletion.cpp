class Solution {
public:
    int helper(vector<int>& arr, int i, int deleted, vector<vector<int>>& dp) {
        if(i<0) return -1e9;
        if(dp[i][deleted] != -1) return dp[i][deleted];
        if(deleted == 0) {
            int newSt = arr[i];
            int extend = arr[i] + helper(arr, i-1, deleted, dp);
            int del = helper(arr, i-1, 1, dp);
            return dp[i][deleted] = max({newSt, extend, del});
        }
        else {
            int newSt = arr[i];
            int extend = arr[i] + helper(arr, i-1, deleted, dp);
            return dp[i][deleted] = max(newSt, extend);
        }
    }

    int maximumSum(vector<int>& arr) {
        int ans = -1e9;

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        for (int i = 0; i < arr.size(); i++) {
            ans = max(ans, helper(arr, i, 0, dp));
            ans = max(ans, helper(arr, i, 1, dp));
        }

        return ans;
    }
};