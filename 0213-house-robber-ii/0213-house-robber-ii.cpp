class Solution {
public:
    int helper(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind == 0) return dp[ind]=nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int take = nums[ind] + helper(nums, ind-2, dp);
        int notTake = helper(nums, ind-1, dp);
        return dp[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> n1;
        vector<int> n2;
        for(int i=0; i<n; i++) {
            if(i != 0) n1.push_back(nums[i]);
            if(i != n-1) n2.push_back(nums[i]);
        }
        vector<int> dp1(n1.size()+1, -1);
        vector<int> dp2(n2.size()+1, -1);
        int ans1 = helper(n1, n1.size()-1, dp1);
        int ans2 = helper(n2, n2.size()-1, dp2);
        return max(ans1, ans2);
    }
};