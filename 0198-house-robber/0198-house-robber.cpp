class Solution {
public:
// MEMOIZATION
    // int helper(vector<int>& nums, int ind, vector<int>& dp) {
    //     if(ind >= nums.size()) {
    //         return 0;
    //     }
    //     if(dp[ind] != -1) return dp[ind];
    //     int take = helper(nums, ind+2, dp) + nums[ind];
    //     int notTake = helper(nums, ind+1, dp);
    //     return dp[ind] = max(take, notTake);
    // }

    // int rob(vector<int>& nums) {
    //     // int sum = 0;
    //     int n = nums.size();
    //     vector<int> dp(n+1, -1);
    //     return helper(nums, 0, dp);
    // }

// TABULATION 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for(int i=2; i<n; i++) {
            int take = nums[i] + dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }

};