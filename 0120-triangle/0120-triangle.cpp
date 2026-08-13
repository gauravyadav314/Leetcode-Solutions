class Solution {
public:
    // memoization
    // int helper(vector<vector<int>>& t, int r, int c, vector<vector<int>>& dp) {
    //     if(r==t.size()-1) return t[r][c];
    //     if(dp[r][c] != INT_MAX) return dp[r][c];
    //     int down = helper(t, r+1, c, dp);
    //     int diagonal = helper(t, r+1, c+1, dp);
    //     return dp[r][c] = t[r][c] + min(down, diagonal);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int row = triangle.size();
    //     vector<vector<int>> dp(row, vector<int>(row, INT_MAX));
    //     return helper(triangle, 0, 0, dp);
    // }

    // tabulation 
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        vector<vector<int>> dp(r, vector<int>(r, INT_MAX));
        for(int j=0; j<r; j++) dp[r-1][j] = triangle[r-1][j];
            
        for(int i=r-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, diagonal);
            }
        }
        return dp[0][0];
    }
};