class Solution {
public:
    int helper(int ind, vector<int>& cost, vector<int>& dp) {
        if(ind >= (int)cost.size()) return 0;
        if(dp[ind+1] != -2) return dp[ind+1];
        int paisa = ind<0 ? 0 : cost[ind];
        int one = paisa + helper(ind+1, cost, dp);
        int two = paisa + helper(ind+2, cost, dp);
        return dp[ind+1] = min(one, two); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -2);
        int one = helper(-1, cost, dp);
        // int two = helper(1, cost, dp);
        // return min(one, two);
        return one;
    }
};