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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int size = helper(word1, word2, n-1, m-1, dp);
        return n+m-2*size;
    }
};