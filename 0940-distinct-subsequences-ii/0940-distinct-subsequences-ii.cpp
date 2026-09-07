class Solution {
public:
    const int mod = 1000000007;
// dp memoization
    // int helper(string& s, int ind, int lastInd, vector<vector<int>>& dp) {
    //     if(ind == s.size()) {
    //         if(lastInd > -1) return 1;
    //         else return 0;
    //     }
    //     if(dp[ind+1][lastInd+1] != -1) return dp[ind+1][lastInd+1];
    //     int notTake=0;
    //     int take = helper(s, ind+1, ind, dp);
    //     if(lastInd == -1) notTake = helper(s, ind+1, lastInd, dp);
    //     else if(s[lastInd] != s[ind]) notTake = helper(s, ind+1, lastInd, dp);
    //     return dp[ind+1][lastInd+1] = (take + notTake)%mod;
    // }
    // int distinctSubseqII(string s) {
    //     int n = s.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //     return helper(s, 0, -1, dp);
    // }

// dp space optimization
    int distinctSubseqII(string s) {
        int n = s.size();
        long long dp = 0;
        vector<long long> hash(26, 0);
        for(char ch : s) {
            long long last = dp;
            dp = ((2* dp) + 1 - hash[ch-'a'] + mod)%mod;
            hash[ch-'a'] = last + 1;
        }
        return dp;
    }
};