class Solution {
public:
    int digitSum(int n) {
        if(n/10==0) return n+n;
        int sum = 0;
        int product = 1;
        while(n) {
            sum += n%10;
            product *= n%10;
            n/=10;
        }
        return sum+product;
    }
    bool checkDivisibility(int n) {
        int sum = digitSum(n);
        if(n%sum == 0) return true;
        return false;
    }
};