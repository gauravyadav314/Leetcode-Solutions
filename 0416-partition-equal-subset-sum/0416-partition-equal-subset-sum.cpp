class Solution {
public:
    bool helper(vector<int>& nums, int ind, int sum, vector<vector<int>>& dp) {
        if(ind == nums.size()) {
            return false;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        if(sum==0) return true;
        bool left=false, right=false;
        if(sum >= nums[ind]) left = helper(nums, ind+1, sum-nums[ind], dp);
        right = helper(nums, ind+1, sum, dp);
        if(left || right) return dp[ind][sum] = true;
        return dp[ind][sum] = false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int x : nums) {
            sum += x;
        }
        if(sum%2 != 0) return false;
        sum = sum/2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return helper(nums, 0, sum, dp);
    }
};