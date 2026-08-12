class Solution {
public:
    int helper(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp) {
        if(r < 0 || c < 0) return INT_MAX;
        if(r==0 && c==0) {
            return grid[r][c];
        }
        if(dp[r][c] != -1) return dp[r][c];
        int left = helper(grid, r, c-1, dp);
        int up = helper(grid, r-1, c, dp);
        return dp[r][c] = grid[r][c] + min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return helper(grid, row-1, col-1, dp);
    }
};