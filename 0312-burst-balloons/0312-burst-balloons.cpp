class Solution {
public:
// Memoization
    // int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
    //     if(i>j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int maxi = INT_MIN;
    //     for(int ind=i; ind<=j; ind++) {
    //         int cost = (nums[i-1]*nums[ind]*nums[j+1]) + helper(i, ind-1, nums, dp) + helper(ind+1, j, nums, dp);
    //         maxi = max(maxi, cost);
    //     }
    //     return dp[i][j] = maxi;
    // }
    // int maxCoins(vector<int>& nums) {
    //     nums.insert(nums.begin(), 1);
    //     nums.push_back(1);
    //     int n = nums.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     return helper(1, n-2, nums, dp);
    // }

// Tabulation 
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-2; i>=1; i--) {
            for(int j=i; j<n-1; j++) {
                int maxi = INT_MIN;
                for(int ind=i; ind<=j; ind++) {
                    int cost = nums[i-1]*nums[ind]*nums[j+1];
                    int left = dp[i][ind-1];
                    int right = dp[ind+1][j];
                    maxi = max(maxi, cost+left+right);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
};