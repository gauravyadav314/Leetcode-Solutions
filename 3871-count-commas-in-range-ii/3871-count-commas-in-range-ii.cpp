class Solution {
public:
    long long countCommas(long long n) {
        int a;
        if(n < 1000) return 0;
        else if(n < 1e6) return n-999;
        else if(n < 1e9) return a=n-999 + n-1e6+1;
        else if(n < 1e12) return n-999 + n-1e6+1 + n-1e9+1;
        else if(n< 1e15) return n-999 + n-1e6+1 + n-1e9+1 + n-1e12+1;
        return n-999 + n-1e6+1 + n-1e9+1 + n-1e12+2;
    }
};