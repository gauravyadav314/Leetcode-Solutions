class Solution {
public:
    // memoization
    // int paths(int m, int n, vector<vector<int>>& dp) {
    //     if(m==0 && n==0) {
    //         return 1;
    //     }
    //     int left=0, up=0;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     if(m > 0) up = paths(m-1, n, dp);
    //     if(n > 0) left = paths(m, n-1, dp);
    //     return dp[m][n] = up + left;
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return paths(m-1, n-1, dp);
    // }

    // tabulation 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) dp[0][0] = 1;
                else {
                    int down=0, right=0;
                    if(i > 0) down = dp[i-1][j];
                    if(j > 0) right = dp[i][j-1];
                    dp[i][j] = down+right;
                }
            }
        }
        return dp[m-1][n-1];
    }
};