class Solution {
public:
    int helper(vector<vector<char>>& mat, int r, int c, int& maxi, vector<vector<int>>& dp) {
        
        if(r< 0 || c<0) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        int right = helper(mat, r, c-1, maxi, dp);
        int down = helper(mat, r-1, c, maxi, dp);
        int diagonal = helper(mat, r-1, c-1, maxi, dp);
            
        if(mat[r][c]=='1') {
            int mini = min({right, down, diagonal});
            maxi = max(maxi, mini+1);
            return dp[r][c] = mini+1;

        }
        else return dp[r][c] = 0;
            
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(row, vector<int>(col, -1));
        int temp = helper(matrix, row-1, col-1, maxi, dp);
        return maxi*maxi;
    }
};