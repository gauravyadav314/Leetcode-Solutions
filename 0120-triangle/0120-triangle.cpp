class Solution {
public:
    int helper(vector<vector<int>>& t, int r, int c, vector<vector<int>>& dp) {
        if(r==t.size()-1) return t[r][c];
        if(dp[r][c] != INT_MAX) return dp[r][c];
        int down = helper(t, r+1, c, dp);
        int diagonal = helper(t, r+1, c+1, dp);
        return dp[r][c] = t[r][c] + min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, INT_MAX));
        return helper(triangle, 0, 0, dp);
    }
};