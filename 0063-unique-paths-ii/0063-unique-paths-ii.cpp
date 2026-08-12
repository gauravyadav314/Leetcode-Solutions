class Solution {
public:
    // memoization
    // int path(vector<vector<int>>& mat, int r, int c, vector<vector<int>>& dp) {
    //     if(r < 0 || c < 0) return 0;
    //     if(mat[r][c] == 1) return 0;
    //     if(r==0 && c==0) return 1;
    //     if(dp[r][c] != -1) return dp[r][c];
    //     int left = path(mat, r, c-1, dp);
    //     int up = path(mat, r-1, c, dp);
    //     return dp[r][c] = left + up;
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
    //     return path(obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1, dp);
    // }

    // tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if((obstacleGrid[0][0] != 1) && i==0 && j==0) dp[0][0] = 1;
                else {
                    int right=0, down=0;
                    if(i > 0) right = dp[i-1][j];
                    if(j > 0) down = dp[i][j-1];
                    if(obstacleGrid[i][j] != 1) dp[i][j] = right + down;
                }
            }
        }
        return dp[row-1][col-1];
    }
};