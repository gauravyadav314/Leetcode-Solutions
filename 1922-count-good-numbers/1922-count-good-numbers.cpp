class Solution {
public:
    long long powerCalculation(long a, long b)
    {
        const long long mod = 1000000007;
        if(b==0) return 1;
        long long value = powerCalculation(a, b/2);
        value%=mod;
        long long result = value*value;
        result%=mod;
        if(b%2==0) return result;
        return (result*a);
    }
    int countGoodNumbers(long long n) {
        long long ans=1;
        const long long mod = 1000000007;
        long long evenIndexes = (n+1)/2;
        long long oddIndexes = n/2;
        ans*=powerCalculation(5, evenIndexes);
        ans%=mod;
        ans*=powerCalculation(4, oddIndexes);
        ans%=mod;
        return int(ans);
    }
};