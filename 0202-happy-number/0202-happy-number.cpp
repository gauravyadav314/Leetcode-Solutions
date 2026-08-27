class Solution {
public: 
    int sqDigit(int n) {
        int ans = 0;
        while(n>0) {
            int r = n%10;
            ans += r*r;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sqDigit(slow);
            fast = sqDigit(sqDigit(fast));
        } while(slow != fast);
        return slow==1;
    }
};