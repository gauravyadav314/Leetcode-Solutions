class Solution {
public:
// memoization
    // int helper(int ind, vector<int>& cost, vector<int>& dp) {
    //     if(ind >= (int)cost.size()) return 0;
    //     if(dp[ind+1] != -2) return dp[ind+1];
    //     int paisa = ind<0 ? 0 : cost[ind];
    //     int one = paisa + helper(ind+1, cost, dp);
    //     int two = paisa + helper(ind+2, cost, dp);
    //     return dp[ind+1] = min(one, two); 
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n+1, -2);
    //     return helper(-1, cost, dp);
    // }

// tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; i++) {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};