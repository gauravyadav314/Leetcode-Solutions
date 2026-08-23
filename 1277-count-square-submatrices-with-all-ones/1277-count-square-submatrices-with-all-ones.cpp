class Solution {
public:
    int helper(vector<vector<int>>& mat, int r, int c, int& totalCount, vector<vector<int>>& dp) {
        if (r < 0 || c < 0) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int left = helper(mat, r, c - 1, totalCount, dp);
        int up = helper(mat, r - 1, c, totalCount, dp);
        int diagonal = helper(mat, r - 1, c - 1, totalCount, dp);

        if (mat[r][c] == 1) {
            int current = 1 + min({left, up, diagonal});
            totalCount += current;
            return dp[r][c] = current;
        } else {
            return dp[r][c] = 0;
        }
    }

    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int totalCount = 0;
        vector<vector<int>> dp(row, vector<int>(col, -1));

        helper(matrix, row - 1, col - 1, totalCount, dp);
        
        return totalCount;
    }
};