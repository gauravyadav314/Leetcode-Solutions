class Solution {
public:
    bool isPalindrome(string& s, int i, int j, vector<vector<int>>& palDp) {
        if(i >= j) return true;
        if(palDp[i][j] != -1) return palDp[i][j];
        if(s[i] != s[j]) return palDp[i][j] = false;

        return palDp[i][j] = isPalindrome(s, i+1, j-1, palDp);

    }
    int helper(string& s, int ind, vector<int>& dp, vector<vector<int>>& palDp) {
        if(ind==s.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        string temp = "";
        int mini = INT_MAX;
        for(int i=ind; i<s.size(); i++) {
            if(isPalindrome(s, ind, i, palDp)) mini = min(mini, (1 + helper(s, i+1, dp, palDp)));
        }
        return dp[ind] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        vector<vector<int>> palDp(n, vector<int>(n, -1));
        return helper(s, 0, dp, palDp)-1;
    }
};