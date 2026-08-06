class Solution {
public:
    // int helper(int n, vector<int>& dp) {
    //     if(n==1) return 1;
    //     else if(n==2) return 2;
    //     return climbStairs(n-1)+climbStairs(n-2);
    // }
    int climbStairs(int n) {
        // vector<int> dp(n+1, 0);
        // helper(n, dp);
        long long a=1;
        long long b=2;
        for(int i=2; i<=n; i++) {
            long long c = a+b;
            a = b;
            b = c;
        }
        return int(a);
    }
};