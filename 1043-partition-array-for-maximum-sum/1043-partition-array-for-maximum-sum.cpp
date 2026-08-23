class Solution {
public:
    int helper(vector<int>& arr, int ind, int k, vector<int>& dp) {
        int n = arr.size();
        if(ind==n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int maxi=INT_MIN;
        int maxSum = INT_MIN;
        int len = 0;
        for(int i=ind; i<min(n, ind+k); i++) {
            len++;
            maxi = max(maxi, arr[i]);
            int sum = (len*maxi) + helper(arr, i+1, k, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[ind] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(arr, 0, k, dp);
    }
};