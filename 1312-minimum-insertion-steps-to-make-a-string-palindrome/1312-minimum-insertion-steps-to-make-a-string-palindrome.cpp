class Solution {
public:
    int helper(string& s, string& t, int i1, int i2, vector<vector<int>>& dp) {
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s[i1] == t[i2]) 
        return dp[i1][i2] = (1 + helper(s, t, i1-1, i2-1, dp));
        return dp[i1][i2] = max(helper(s, t, i1-1, i2, dp), helper(s, t, i1, i2-1, dp));
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n - helper(s, t, n-1, n-1, dp);
    }
};