class Solution {
public:
    int helper(string& s, string& t, int ind1, int ind2, vector<vector<int>>& dp) {
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s[ind1] == t[ind2]) {
            return dp[ind1][ind2] = (1 + helper(s, t, ind1-1, ind2-1, dp));
        }
        return dp[ind1][ind2] = max(helper(s, t, ind1-1, ind2, dp), helper(s, t, ind1, ind2-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(s, t, n-1, n-1, dp);
    }
};