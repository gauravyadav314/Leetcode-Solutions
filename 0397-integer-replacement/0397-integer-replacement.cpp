class Solution {
public:
    int helper(long long n, unordered_map<long long, int>& dp) {
        if(n<=1) return 0;
        int left = INT_MAX, right = INT_MAX;
        if(dp.find(n) != dp.end()) return dp[n];
        if(n%2==0) return dp[n] = 1 + helper(n/2, dp);
        else {
            left = 1+helper(n-1, dp);
            right = 1+helper(n+1, dp);
        }
        return dp[n] = min(left, right);
    }
    int integerReplacement(int n) {
        unordered_map<long long, int> dp;
        return helper(n, dp);
    }
};