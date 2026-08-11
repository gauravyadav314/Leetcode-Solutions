class Solution {
public:
    int path(vector<vector<int>>& mat, int r, int c, vector<vector<int>>& dp) {
        if(r < 0 || c < 0) return 0;
        if(mat[r][c] == 1) return 0;
        if(r==0 && c==0) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        int left = path(mat, r, c-1, dp);
        int up = path(mat, r-1, c, dp);
        return dp[r][c] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return path(obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1, dp);
    }
};