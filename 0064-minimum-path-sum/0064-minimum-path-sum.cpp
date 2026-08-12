class Solution {
public:
    // memoization 
    // int helper(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp) {
    //     if(r < 0 || c < 0) return INT_MAX;
    //     if(r==0 && c==0) {
    //         return grid[r][c];
    //     }
    //     if(dp[r][c] != -1) return dp[r][c];
    //     int left = helper(grid, r, c-1, dp);
    //     int up = helper(grid, r-1, c, dp);
    //     return dp[r][c] = grid[r][c] + min(left, up);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int row = grid.size();
    //     int col = grid[0].size();
    //     vector<vector<int>> dp(row, vector<int>(col, -1));
    //     return helper(grid, row-1, col-1, dp);
    // }

    // tabulation 
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else {
                    int left=INT_MAX, up=INT_MAX;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(left, up);
                }
            }
        }
        return dp[row-1][col-1];
    }
};