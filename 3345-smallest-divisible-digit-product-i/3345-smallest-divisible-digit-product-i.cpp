class Solution {
public:
    bool divisible(int n, int t) {
        int product = 1;
        while(n) {
            product *= n%10;
            n /= 10;
        }
        if(product % t == 0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        if(divisible(n, t)) return n;
        while(true) {
            n++;
            if(divisible(n, t)) return n;
        }
        return -1;
    }
};