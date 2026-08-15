class Solution {
public:
    // Memoization
    // bool helper(vector<int>& nums, int ind, int sum, vector<vector<int>>& dp) {
    //     if(ind == nums.size()) {
    //         return false;
    //     }
    //     if(dp[ind][sum] != -1) return dp[ind][sum];
    //     if(sum==0) return true;
    //     bool left=false, right=false;
    //     if(sum >= nums[ind]) left = helper(nums, ind+1, sum-nums[ind], dp);
    //     right = helper(nums, ind+1, sum, dp);
    //     if(left || right) return dp[ind][sum] = true;
    //     return dp[ind][sum] = false;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     int n = nums.size();
    //     for(int x : nums) {
    //         sum += x;
    //     }
    //     if(sum%2 != 0) return false;
    //     sum = sum/2;
    //     vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    //     return helper(nums, 0, sum, dp);
    // }

    // Tabular
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int x : nums) {
            sum += x;
        }
        if(sum%2 != 0) return false;
        sum = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if (nums[0] <= sum) {
            dp[0][nums[0]] = true;
        }
        for(int ind=1; ind<n; ind++) {
            for(int target=1; target<=sum; target++) {
                bool notTaken = dp[ind-1][target];
                bool taken = false;
                if(nums[ind] <= target) {
                    taken = dp[ind-1][target-nums[ind]];
                }
                dp[ind][target] = taken||notTaken;
            }
        }
        return dp[n-1][sum];
    }
};