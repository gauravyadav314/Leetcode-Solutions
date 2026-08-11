class Solution {
public:
    int paths(int m, int n, vector<vector<int>>& dp) {
        if(m==0 && n==0) {
            return 1;
        }
        int left=0, up=0;
        if(dp[m][n] != -1) return dp[m][n];
        if(m > 0) up = paths(m-1, n, dp);
        if(n > 0) left = paths(m, n-1, dp);
        return dp[m][n] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m-1, n-1, dp);
    }
};