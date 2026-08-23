class Solution {
public:
// Memoization
    // int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    //     if(i > j) return 0;
    //     int mini = INT_MAX;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     for(int ind=i; ind<=j; ind++) {
    //         int len = cuts[j+1] - cuts[i-1];
    //         int left = helper(i, ind-1, cuts, dp);
    //         int right = helper(ind+1, j, cuts, dp);
    //         len += left+right;
    //         mini = min(mini, len);
    //     }
    //     return dp[i][j] = mini;
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     cuts.push_back(n);
    //     cuts.insert(cuts.begin(), 0);
    //     sort(cuts.begin(), cuts.end());
    //     int s = cuts.size();
    //     vector<vector<int>> dp(s, vector<int>(s, -1));
    //     return helper(1, cuts.size()-2, cuts, dp);
    // }

// Tabulation
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int s = cuts.size();
        vector<vector<int>> dp(s, vector<int>(s, 0));
        for(int i=s-2; i>=1; i--) {
            for(int j=i; j<s-1; j++) {
                int mini = INT_MAX;
                for(int ind=i; ind<=j; ind++) {
                    int len = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(len, mini);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][s-2];
    }
};